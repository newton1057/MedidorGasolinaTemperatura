#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);
float tempC; 
int pinLM35 = 0;
int tanque = 1;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {

  //Medir Gasolina
   float porcentaje;
   float space;
   int m=analogRead(tanque); 
   double voltage = m*(5.0000/1023.0000); 
   float resistor=10*(5-voltage)/voltage;
   Serial.print(resistor); Serial.print(" ohms\n");
   //float porcentaje=(resistor*100)/220; 
   
  if(resistor>=260)
    {
      Serial.print("100% FULL ");
      lcd.setCursor(0,0);             
      lcd.print("Gasolina: 100% FULL");   
    }
  else if(resistor<=259.9 && resistor>=170)
  {
    //270 = 1/1 = 100% = TANQUE LLENO
    //170 = 3/4 = 75%
    space = (resistor-170);
    porcentaje = (space/4)+75;
    Serial.print(porcentaje);
    Serial.print(" %");
    lcd.setCursor(0,0);             
    lcd.print("Gasolina:            ");
    lcd.setCursor(9,0);             
    lcd.print(porcentaje);
    lcd.print(" %");
    
  }
  else if(resistor<=169.9 && resistor>=96)
  {
    //170 = 3/4 = 75%
    //96  = 1/2 = 50%
    space = (resistor-96);
    porcentaje = (space/2.9)+50;
    Serial.print(porcentaje);
    Serial.print(" %");
    lcd.setCursor(0,0);             
    lcd.print("Gasolina:            ");
    lcd.setCursor(9,0);             
    lcd.print(porcentaje);
    lcd.print(" %");
  }
  else if(resistor<=95.9 && resistor>=75)
  {
    //96 = 1/2 = 50%
    //75 = 1/4 = 25%
    space = (resistor-75);
    porcentaje = (space/0.8)+25;
    Serial.print(porcentaje);
    Serial.print(" %");
    lcd.setCursor(0,0);             
    lcd.print("Gasolina:            ");
    lcd.setCursor(9,0);             
    lcd.print(porcentaje);
    lcd.print(" %");
  }
  else if(resistor<=74.9 && resistor>=55)
  {
    //75 = 1/4 = 25%
    //55 = 1/8 = 12.5%
    
    space = (resistor-55);
    porcentaje = (space/1.6)+12;
    Serial.print(porcentaje);
    Serial.print(" %");
    lcd.setCursor(0,0);             
    lcd.print("Gasolina:            ");
    lcd.setCursor(9,0);             
    lcd.print(porcentaje);
    lcd.print(" %");
  }
  else if(resistor<=54.9 && resistor>=40)
  {
    //55 = 1/8 = 12.5%
    //40 = 0   = 0%
    Serial.print("RESERVA ");
    //1.2 = 1%
    space = (resistor-40);
    porcentaje = (space*12.5)/15;
    Serial.print(porcentaje);
    Serial.print(" %");
    lcd.setCursor(0,0);             
    lcd.print("Gasolina:            ");
    lcd.setCursor(9,0);             
    lcd.print(porcentaje);
    lcd.print(" %");
  }
 

   
  //Medir Temperatura
   tempC = analogRead(pinLM35);
   tempC = (5.0 * tempC * 100.0)/1024.0;
   Serial.print("Temperatura: ");
   Serial.print(tempC); 
   Serial.print("°C");
   Serial.print("\n");
   lcd.setCursor(0,1);             
   lcd.print("Temp:          ");   
   lcd.setCursor(5,1);             
   lcd.print(tempC);
   lcd.print("C");
   
   delay(1000); 
}
