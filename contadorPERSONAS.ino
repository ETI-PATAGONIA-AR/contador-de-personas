#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

  #define pin8 8   // Al terminal  8 lo llamamos pin8. Aquí irá un pulsador.
#define pin9 9   // Al terminal  9 lo llamamos pin9. Aquí irá otro pulsador.

#define LED2 2
#define LED3 3
#define LED4 4
#define LED5 5
#define LED6 6
#define LED7 7

int contador8, contador9; // Variables enteras.
int contador=0;     // Variable contador igual a cero
int cambio=3;





void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
 Serial.begin(9600);        // Para ver información en el Serial Monitor. 
 lcd.init();
 lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("--------------------");
 lcd.setCursor(0,1);
 lcd.print("      contador      ");
 lcd.setCursor(0,2);
 lcd.print("     variables      ");
 lcd.setCursor(0,3);
 lcd.print("--------V1.1--------");
 delay(1000);
 void luces();
 lcd.clear();
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
void loop()
{
 //lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("--------------------");
 lcd.setCursor(0,1);
 lcd.print("CONTADOR: ");
 lcd.print(contador);
 if (contador > 18)
     {
      contador=18;
      lcd.setCursor(0,2);
      lcd.print("  NO HAY CAPACIDAD  ");
      }
 if (contador < 18)   
    { 
     lcd.setCursor(0,2);
     lcd.print("ESPACIOconCAPACIDAD!");
    }
 lcd.setCursor(0,3);
 lcd.print("--------------------");   
  contador8 = digitalRead(11); // Lee el contador del pin8 y se lo asigna a contador8. (Puede ser 0 o 1)
  contador9 = digitalRead(10); // Lee el contador del pin9 y se lo asigna a contador9. (Puede ser 0 o 1)
if (contador8 == HIGH)
 {
  contador = contador + 1; 
  if (contador > 18)
     {
      contador=18;
      lcd.setCursor(0,2);
      lcd.print("  NO HAY CAPACIDAD  ");
      }
  luces();   
 }
if (contador9 == HIGH)
  {
   contador = contador - 1;
   if (contador < 0)
     {
     contador=0;
     }
    luces();                               
  }
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
// Subrutina luces()
void luces(){
   Serial.print(contador);

  if (contador >= cambio*1)
      {digitalWrite(LED2, HIGH);}// 3
      else
      {digitalWrite(LED2, LOW);}
      
  if (contador >= cambio*2)
      {digitalWrite(LED3, HIGH);}// 6
      else
      {digitalWrite(LED3, LOW);}   
      
  if (contador >= cambio*3)
      { digitalWrite(LED4, HIGH);}// 9
      else
      {digitalWrite(LED4, LOW);}
        
  if (contador >= cambio*4)
      {digitalWrite(LED5, HIGH);}// 12
      else
      {digitalWrite(LED5, LOW);}
      
  if (contador >= cambio*5)
      {digitalWrite(LED6, HIGH);}// 15
      else
      {digitalWrite(LED6, LOW);}

    if (contador >= cambio*6)
       {
        digitalWrite(LED7, HIGH);
        lcd.setCursor(0,2);
        lcd.print("  NO HAY CAPACIDAD  ");
        }// 18
      else
      {digitalWrite(LED7, LOW);}   
      
   delay(300); // Retardo entre pulsaciones.
}
///////////////////////////////////////////////////