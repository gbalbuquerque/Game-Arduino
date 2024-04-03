// C++ code
//
#include <LiquidCrystal.h>


LiquidCrystal lcd(12,11,10,9,8,7);


String pgtfacil[5]{


};

String pgtmed[5]{


};

String pgtdif[5]{


};

int nivelpgt = 0;
int acertos = 0;
int numpgt = 0;

void setup()
{
  pinMode(1,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  lcd.begin(16,2);
  lcd.print("Bem vindo ao jogo!");
}

void loop()
{
  lcd.setCursor(0,1);
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  lcd.setCursor(0,1);
  delay(1000);
}