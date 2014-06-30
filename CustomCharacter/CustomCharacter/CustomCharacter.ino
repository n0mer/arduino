/*
  LiquidCrystal Library - Custom Characters
 
 Demonstrates how to add custom characters on an LCD  display.  
 The LiquidCrystal library works with all LCD displays that are 
 compatible with the  Hitachi HD44780 driver. There are many of 
 them out there, and you can usually tell them by the 16-pin interface.
 
 This sketch prints "I <heart> Arduino!" and a little dancing man
 to the LCD.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K potentiometer:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 10K poterntiometer on pin A0
 
 created21 Mar 2011
 by Tom Igoe
 Based on Adafruit's example at
 https://github.com/adafruit/SPI_VFD/blob/master/examples/createChar/createChar.pde
 
 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 
 Also useful:
 http://icontexto.com/charactercreator/
 
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// make some custom characters:
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

byte aim[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b10101,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

byte aimEmpty[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

byte thumbUp[8] = {
  0b00000,
  0b01000,
  0b01000,
  0b01110,
  0b11110,
  0b11110,
  0b11110,
  0b00000
};

byte thumbDown[8] = {
  0b00000,
  0b11110,
  0b11110,
  0b11110,
  0b01110,
  0b01000,
  0b01000,
  0b00000
};

byte car[8] = {
  0b00000,
  0b01110,
  0b01010,
  0b11111,
  0b01010,
  0b00000,
  0b00000,
  0b00000
};



void setup() {
  // create a new character
  lcd.createChar(5, heart);
  // create a new character
  lcd.createChar(1, smiley);
  // create a new character
  lcd.createChar(2, frownie);
  // create a new character
  lcd.createChar(3, armsDown);  
  // create a new character
  lcd.createChar(4, armsUp);  
  // create "aim" character
  lcd.createChar(6, aim);
  lcd.createChar(7, aimEmpty);
  lcd.createChar(8, thumbUp);
  lcd.createChar(9, thumbDown);
  lcd.createChar(10, car);
  // set up the lcd's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the lcd.
//  lcd.print("I "); 
//  lcd.write(5);
//  lcd.print(" Arduino! ");
//  lcd.write(6);
//  lcd.write(" ");
//  lcd.write(6);

}

void loop() {
//  // read the potentiometer on A0:
//  int sensorReading = analogRead(A0);
//  // map the result to 200 - 1000:
//  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
//  // set t



//he cursor to the bottom row, 5th position:
//  lcd.setCursor(13, 0);
//  // draw the little man, arms down:
//  lcd.write(6);
//  
//  lcd.setCursor(0, 1);
//  lcd.write(8);
//  
//  delay(delayTime);
//  lcd.setCursor(13, 0);
//  // draw him arms up:
//  lcd.write(7);
//  
//  lcd.setCursor(0, 1);
//  lcd.write(9);
//  
//  delay(delayTime); 
  
  // draw car
  lcd.setCursor(0, 1);
  lcd.write(10);
  
  // cycle to move forward
  for (int positionCounter = 0; positionCounter < 10; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight(); 
    // wait a bit:
    delay(250);
  }
  
  //draw "Boom!"
  lcd.setCursor(0, 0);
  lcd.write("Boom!");

  // write "tumbs down"
  lcd.setCursor(5, 0);
  lcd.write(9);

  //wait
  delay(500);
  
  // wipe out "Boom!"
  lcd.setCursor(0, 0);
  lcd.write("      ");

  // cycle to move backwards
  for (int positionCounter = 0; positionCounter < 10; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(250);
  }
  
  
  
  delay(1000);
  
}



