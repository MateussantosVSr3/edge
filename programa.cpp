#include <LiquidCrystal.h>
float leituras;
int pino = A2;

float tensaoSaida = 0;
float tensaoEntrada = 5;
float R1 = 1000;
float R2 = 0;
float buffer = 0;
float TDS;

float R = 0;
float r = 0;
float L = 0.06;
double A = 0.000154;
float C = 0;
float Cm = 0;

LiquidCrystal lcd1(13, 12, 11, 10, 9, 8);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  //PH e Temperatura
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("pH:");
  lcd.setCursor(0, 1);
  lcd.print("Temp:");

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  Serial.println("Iniciando...");
  //TDS
  lcd1.begin(16, 2);  
  lcd1.setCursor(0,1);
  lcd1.print("TDS");
}

void loop() {
  //PH e Temperatura
  int valor_pH = analogRead(A0);
  float pH = (valor_pH / 1023.0) * 5.0 * 2.63 - 0.36;

  int valor_temp = analogRead(A1);
  float temp = (valor_temp / 1023.0) * 5000.0 / 10.0;

  Serial.print("pH: ");
  Serial.println(pH);
  Serial.print("Temp: ");
  Serial.println(temp);

  lcd.setCursor(4, 0);
  lcd.print(pH);
  lcd.setCursor(6, 1);
  lcd.print(temp);

  delay(500);
  
  //TDS
  leituras = analogRead(A2);
  tensaoSaida = leituras * 5 / 1023;
  buffer = (tensaoEntrada / tensaoSaida) - 1;
  R2 = R1 * buffer;
  
  delay(100);
  
  r = R2 * A / L;
  C = 1 / r;
  Cm = C * 10;
  TDS = Cm * 700;
  
  if (TDS >= 1200)
  {  
    lcd1.setCursor(0,0);
    lcd1.print("Inaceitavel    ");  
    lcd1.setCursor(4,1);
    lcd1.print(TDS);
    lcd1.print("                ");
  }
  
  if (TDS >= 600 && TDS <= 900)
  {  
    lcd1.setCursor(0,0);
    lcd1.print("Nao saudavel   ");  
    lcd1.setCursor(4,1);
    lcd1.print(TDS);
    lcd1.print("                ");
  }
  
  if (TDS >= 300 && TDS <= 600)
  {  
    lcd1.setCursor(0,0);
    lcd1.print("Aceitavel      ");  
    lcd1.setCursor(4,1);
    lcd1.print(TDS);
    lcd1.print("                ");
  }
  
  if (TDS >= 1 && TDS <= 300)
  {  
    lcd1.setCursor(0,0);
    lcd1.print("Muito boa      ");  
    lcd1.setCursor(4,1);
    lcd1.print(TDS);
    lcd1.print("                ");
  }
  
  if (TDS == 0)
  {  
    lcd1.setCursor(0,0);
    lcd1.print("Pura           ");  
    lcd1.setCursor(4,1);
    lcd1.print(TDS);
    lcd1.print("                ");
  }
}