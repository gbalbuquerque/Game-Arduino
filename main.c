#include <LiquidCrystal.h>
#include <stdlib.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

//botoes, buzzer e led
int btsim = A0;
int btnao = 2;
int btpular = 3;
int btca = 4;
int buzzer = 13;
int lv = 5;
int lred = 6;  

//variaveis 
int maxperguntasf = 5;
int perguntas = 0;
int pontuacao = 0;
int tentativas = 3;
int dificuldade = 0;
int numQ = 0;
bool mostrandoPergunta = false;
int indiceAleatorio;

String pgtfacil[10] = {
    "  O arduino tem 14 pinos?",
    "  O cachorro tem 4 patas?",
    "  A Terra eh plana?",
    "  O Sol eh uma estrela",
    "  Os seres humanos precisam de oxigenio para sobreviver?",
    "  A gravidade eh uma forca fundamental no universo?",
    "  A Antartica eh o continente mais frio da Terra?",
    "  A agua eh composta por hidrogenio e oxigenio?",
    "  O zero é um numero par?",
    "  As plantas podem viver sem luz solar?",
};



String pgtfinal[1] = { 
  "Voce gostou do Jogo?" 
}; 
 

bool rpgtfacil[10] = {true, true, false, true, true, true, true, true, false, false};
bool rpgtmedio[10] = {true, false, true, true, true,true, true, true, false, false};
bool rpgtdificil[10] = {true, true, false, false, true};
bool rpgtfinal[1] = {true};

void setup()
{
    //config
    Serial.begin(9600);
    pinMode(btsim, INPUT_PULLUP);
    pinMode(btnao, INPUT_PULLUP);
    pinMode(btpular, INPUT_PULLUP);
    pinMode(btca, INPUT_PULLUP);
    pinMode(lred, OUTPUT);
    pinMode(lv, OUTPUT);
    pinMode(buzzer, OUTPUT);
    randomSeed(analogRead(0));

    //home
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("BEM VINDO!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("APERTE O BT 1");
    lcd.setCursor(0, 1);
    lcd.print(" PARA COMECAR! ");

    //loop
    while (digitalRead(btca) == HIGH)
    {
    }
    lcd.clear();
  	emitirSomInicioJogo();
    loop();
}

void exibirPontuacao() {
    lcd.setCursor(0, 1);
    lcd.print("Pontuacao: ");
    lcd.print(pontuacao);
}

void exibirQuestao() {
  	lcd.print("Questao:");
  	lcd.print(numQ);
}

void verifica_resposta(bool resposta) {
  bool resposta_correta = false;
  if (dificuldade < 3) {
    switch (dificuldade) {
      case 0: resposta_correta = rpgtfacil[indiceAleatorio]; 
              break;
      case 1: resposta_correta = rpgtmedio[indiceAleatorio]; 
              break;
      case 2: resposta_correta = rpgtdificil[indiceAleatorio]; 
              break;
    }

    if (resposta == resposta_correta) {
      lcd.clear();
      lcd.print("Correta!");
      emitirSomAcerto();
      digitalWrite(lv, HIGH);
      emitirSomAcerto();
      delay(3000);
      digitalWrite(lv, LOW); 
      pontuacao++;
    } else {
      lcd.clear();
      lcd.print("Incorreta!");
      emitirSomErro();
      digitalWrite(lred, HIGH); 
      delay(3000);
      digitalWrite(lred, LOW);
      tentativas--;
    }
    delay(3000);
    exibirPontuacao();
    delay(5000);
  }
}
void emitirSomAcerto() {
    int frequencia[] = {261, 329, 392, 523};  
    int duracaoNota = 250; 

    for (int i = 0; i < 4; i++) {
        tone(buzzer, frequencia[i]);
        delay(duracaoNota);
        noTone(buzzer);
        delay(50);
    }
}
void emitirSomErro() {
    int frequencia[] = {200, 150, 100}; 
    int duracaoNota = 100; 
    for (int i = 0; i < 3; i++) {
        tone(buzzer, frequencia[i]);
        delay(duracaoNota);
        noTone(buzzer);
        delay(50);
    }
}

void emitirSomInicioJogo() {
    
    int notas[] = {330, 299, 392, 543};
    int duracaoNota = 150;    
    for (int i = 0; i < 4; i++) {
        tone(buzzer, notas[i], duracaoNota);
        delay(duracaoNota);
        noTone(buzzer);
        delay(50);
    }
}

void emitirSomGameOver() { 
    int notas[] = {262, 196, 147, 131, 110};
    int duracaoNota = 300;
    for (int i = 0; i < 5; i++) {
        tone(buzzer, notas[i], duracaoNota);
        delay(duracaoNota); 
        noTone(buzzer); 
        delay(50); 
    }
}

void emitirSomPularPergunta() {
    
    int frequencia = 400; 
    int duracaoNota = 200; 

    tone(buzzer, frequencia, duracaoNota);
    delay(duracaoNota); 
    noTone(buzzer); 
}


void pularPergunta() {
    mostrandoPergunta = false;
    perguntas++;
}

void loop() {
    unsigned long tempoInicioPergunta = millis();
    unsigned long tempoDecorrido = 0;

    while (tentativas > 0) {
        if (perguntas < maxperguntasf) {
            if (!mostrandoPergunta) {
                indiceAleatorio = random(10);
                lcd.clear();
                lcd.setCursor(1, 0);
                numQ++;
                exibirQuestao();
                delay(2000);
                lcd.clear();
                lcd.setCursor(1, 0);
                lcd.print(pgtfacil[indiceAleatorio]);
                for (int i = 0; i < 16; i++) {
                    lcd.scrollDisplayLeft();
                    delay(300);
                }
                mostrandoPergunta = true;
                tempoInicioPergunta = millis(); 
                tempoDecorrido = 0;
            }

            if (digitalRead(btsim) == LOW) {
                verifica_resposta(true);
                mostrandoPergunta = false;
                perguntas++;
            }
            if (digitalRead(btnao) == LOW) {
                verifica_resposta(false);
                mostrandoPergunta = false;
                perguntas++;
            } 
          
          	if (digitalRead(btpular) == LOW) {
                emitirSomPularPergunta();
              	pularPergunta();
            }
          
            tempoDecorrido = millis() - tempoInicioPergunta;
            if (tempoDecorrido >= 10000 && tempoDecorrido < 15000) { 
                digitalWrite(lred, HIGH); 
                delay(100); 
                digitalWrite(lred, LOW); 
                delay(100); 
            }           
            if (tempoDecorrido >= 15000) {
                emitirSomPularPergunta();
              	pularPergunta();
            }
            
            delay(100);
        }
    }

    if (tentativas == 0) {
        emitirSomGameOver();
        delay(3000);
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("GAME OVER");

        if (digitalRead(btca) == HIGH) {
            emitirSomInicioJogo();
            tentativas = 3;
            numQ = 0;
            pontuacao = 0;
            loop();
        }
    }
}

