#include <Adafruit_Circuit_Playground.h>
#include <Adafruit_CircuitPlayground.h>

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>
#include <stdio.h>
#include <time.h>
uint32_t value;
uint32_t num;
uint32_t base;
uint32_t baseup;
uint32_t basedown;
int index = -1;
double Parkfee = 0;

void setup() {
  Serial.begin(115200);
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
  base = CircuitPlayground.senseColor();
  baseup = base + 50000;
  basedown = base - 50000;
  

}

void loop() {
   Serial.print("base:");
   Serial.println(base);
   delay(1000);
   value = CircuitPlayground.senseColor();
   //Serial.print("first:");
   //Serial.println(value);
   //Serial.println(".");
   delay(1000);
   num = CircuitPlayground.senseColor();
   //Serial.print("second:");
   //Serial.println(num);
   //Serial.println("..");
   delay(1000);
   if ((-5000<=(value - num) <= 5000) && (num>=basedown && num <=baseup)&& (value>=basedown && value <=baseup) ){
    Serial.println("         No Car Parking...       ");
   }
   else
   {
    index = -1;
    Parkfee = 0;
    value = CircuitPlayground.senseColor();
    delay(1000);
    num = CircuitPlayground.senseColor();
    Serial.print(".");
    //Serial.println(value);
    Serial.println("..");
    //Serial.println(num);
    while ((-5000<=(value - num) <= 5000) && !(num>=basedown && num <=baseup)&& !(value>=basedown && value <=baseup) ){
      CircuitPlayground.setPixelColor(6, 0x808000);
      delay(1000);
      Serial.println("           Car Parking...        ");
      index++;
      value = CircuitPlayground.senseColor();
      delay(1000);
      num = CircuitPlayground.senseColor(); 
       Serial.print(".");
      //Serial.println(value);
      Serial.println("..");
      //Serial.println(num);
      }
       if (index != -1){
       Parkfee = index * 2;
       Serial.println("**********Parking  ends**********");
       Serial.print("Parking time (in minute):");
       Serial.println(index);
       Serial.print("Parking fee (in dollar):");
       Serial.println(Parkfee);
       Serial.println("*********************************");
   }
  }

   CircuitPlayground.setPixelColor(6, 0,0,0);
   //clock (not working right now)
   
   /*struct tm * timeinfo;
   time ( &rawtime );
   timeinfo = localtime ( &rawtime );
   Serial.print("Current local time and date:");
   Serial.println(asctime (timeinfo) );*/
   Serial.println("---------------------------------");
   delay(2000);


}
