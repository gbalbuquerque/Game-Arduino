/***************************************************************

				JOGO DE PERGUNTAS NO ARDUINO

CERTIFIQUE-SE DE ANTES DE JOGAR LER A DOCUMENTAÇÃO
DISPONÍVEL EM: https://github.com/gbalbuquerque/Game-Arduino

***************************************************************/
#include <LiquidCrystal.h>
#include <stdlib.h>

LiquidCrystal lcd(12,11,10,9,8,7);

int btsim = 1;
int btnao = 2;
int btpular = 3;
int btca = 4;
int buzzer = 13;


int maxperguntas = 15;
int perguntas = 0; 
int pontuacao = 0;
int tentativas = 3;



String pgtfacil[10] = {
  "  O arduino tem 14 pinos?",
  "  O cachorro tem 4 patas?",
  "  A Terra é plana?",
  "	 O Sol é uma estrela",
  "	 Os seres humanos precisam de oxigênio para sobreviver?",
  "  A gravidade é uma força fundamental no universo?",
  "  A Antártica é o continente mais frio da Terra?",
  "  A água é composta por hidrogênio e oxigênio?",
  "O zero é um número ímpar?",
  "As plantas podem viver sem luz solar?",
};


int rpgtfacil[10] = {1,1,0,1,1,1,1,1,0,0};


String pgtmed[5] = {
  "",
  "",
  "",
  "",
  ""

};

String pgtdif[5] = {
  "",
  "",
  "",
  "",
  ""

};

void setup()
{
  //config
  pinMode(btsim,INPUT_PULLUP);
  pinMode(btnao,INPUT_PULLUP);
  pinMode(btpular,INPUT_PULLUP);
  pinMode(btca,INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(buzzer,OUTPUT);
  //Home
  lcd.begin(16,2);
  lcd.setCursor(0, 0);             
  lcd.print("BEM VINDO ");
  lcd.setCursor(0, 1);
  lcd.print("FEIANO!");
  delay(3000);
  lcd.clear();
  lcd.print("JOGO DO QUIZ!");
  delay(3000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("APERTE O BT 1");
  lcd.setCursor(0,1);
  lcd.print(" PARA COMECAR");
  
  while (digitalRead(btca) == HIGH) {
  }
  loop();
}

void pgtcerta(){
  lcd.setCursor(0,0);
  lcd.print("Correta!");
    
}


void loop()
{
  btsim = digitalRead(1);
  btnao = digitalRead(2);
  btpular = digitalRead(3);
  btca = digitalRead(4);
  
  if(perguntas != maxperguntas){
    
  }
  
  /*lcd.setCursor(0,1);
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  lcd.setCursor(0,1);
  delay(1000);
  lcd.clear();*/
  
}