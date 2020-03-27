
#include <DHT.h>    // incluye libreria DHT de Adafruit
#include <DHT_U.h>    // incluye libreria Adafruit Unified Sensor
#define SENSOR 4    // constante SENSOR en pin digital 4 (senal de DHT11)
int TEMPERATURA;    // variable para almacenar valor de temperatura
int HUMEDAD;      // variable para almacenar valor de humedad
int HUMEDADS;    // variable para almacenar valor de humedad de suelo
DHT dht(SENSOR, DHT11);   // objeto dht del tipo DHT en pin 4 y modelo DHT11
#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 

void setup() {  
  u8g.setFont(u8g_font_helvB12r);
  u8g.setColorIndex(1); // Instructs the display to draw with a pixel on. 
  Serial.begin(9600);   // inicializa monitor serie a 9600 bps
  dht.begin();
  pinMode(0, INPUT);
}

void loop() {  
u8g.firstPage();
  do {  
    draw();    
  } while( u8g.nextPage() );
  delay(1000); 
  u8g.firstPage();
  do {  
    draw2();    
  } while( u8g.nextPage() ); 
 delay(1000);
   Serial.println("Temperatura");
   Serial.println(dht.readTemperature());
   Serial.println("Humedad");
   Serial.println(dht.readHumidity());
   Serial.println("Humedad Suelo:");
   Serial.println(analogRead(0));
}

void draw(){
   u8g.setFont(u8g_font_profont17r);   // select font
   u8g.drawStr(0, 20, "Temp: ");   // put string of display at position X, Y
   u8g.drawStr(0, 60, "Hum: ");
   u8g.setPrintPos(72, 20);        // set position
   u8g.print(dht.readTemperature(), 0);  // display temperature from DHT11 in Celsius
   u8g.println("C"); 
   u8g.setPrintPos(60, 60);        // set position
   u8g.print(dht.readHumidity(), 0);     // display humidity from DHT11
   u8g.println("%");
  }
  
void draw2(){
  u8g.setFont(u8g_font_profont17r);        // select font
  u8g.drawStr(18, 12, "Humedad de suelo"); 
  u8g.setPrintPos(33,40);
  u8g.drawRFrame(15, 20, 100, 30, 10);     // draws frame with rounded edges
  u8g.println(analogRead(0));                        //Prints the voltage
  u8g.println("%");
  
  }
 
