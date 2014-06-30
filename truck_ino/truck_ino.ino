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

// game score
int score = 0;

boolean IS_OVER = false;

// current row for a human
int humanRow;

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

byte truck1[8] = {
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b01010,
  0b00000,
  0b00000,
};
 
byte truck2[8]= {
  0b00000,
  0b00000,
  0b11000,
  0b10100,
  0b11110,
  0b01000,
  0b00000,
  0b00000,  
};

byte human[8]= {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00100,
  0b01110,
  0b00100,
  0b01010,
};

void debug() {
  String humanRowStr = String(humanRow);
  printStr(humanRowStr, 10, 0);
  
}

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
  lcd.createChar(11, truck1);
  lcd.createChar(12, truck2);
  lcd.createChar(13, human);
  // set up the lcd's number of columns and rows: 
  lcd.begin(16, 2);
  
  Serial.begin(9600);
}

void printStr(String s, int X, int Y) {
  for (int i = 0; i < s.length(); i++) {
      lcd.setCursor(X+i, Y);
      lcd.write(s[i]);
  }
}

void printChar(int charNo, int X, int Y) {
  lcd.setCursor(X, Y);
  lcd.write (charNo);
}
  
String adjust(String s) {
  String result = s;
  for (int i = s.length(); i < 3; i++) {
    result = " " + result;
  }
  return result;
}
  
void loop() {
  
  int FIRST_ROW  = 0;
  int SECOND_ROW = 1;
  
  if (IS_OVER) {
    printStr("GAME OVER: " + String(score), 0, FIRST_ROW);
  } else {
    
    int HUMAN_CHAR  = 13;
    int TRUCK1_CHAR = 11;
    int TRUCK2_CHAR = 12;
    
    String scoreStr = String(score);  
    printStr(adjust(scoreStr), 0, FIRST_ROW);
    
    humanRow = 1;
    
    // draw truck
    printChar(TRUCK1_CHAR, 0, SECOND_ROW);
    printChar(TRUCK2_CHAR, 1, SECOND_ROW);
    
    int HUMAN_POSITION = 7;
    
    //draw a human
    printChar(HUMAN_CHAR, HUMAN_POSITION, SECOND_ROW);
    
    // cycle to move forward
    for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
      
      char ch;
      
      if (Serial.available() > 0) {
  
        //reading command
        ch = Serial.read();
        
        if (ch == 'r') {
          score = 0;
        }
        
        if (ch == 'u') {
          //wipe guy from lower row
          printStr(" ", HUMAN_POSITION, SECOND_ROW);
          
          //draw guy on upper row
          printChar(HUMAN_CHAR, HUMAN_POSITION, FIRST_ROW);
          
          //update current row
          humanRow = FIRST_ROW;      
        } 
        if (ch == 'd') {
          //wipe guy on upper row
          printStr(" ", HUMAN_POSITION, FIRST_ROW);
          //draw guy on lower row
          printChar(HUMAN_CHAR, HUMAN_POSITION, SECOND_ROW);
          
          //update current row
          humanRow = SECOND_ROW;
        }     
  //      lcd.setCursor(0, 0);
  //      lcd.write(ch);
      }
      
      // scroll one position right:
  //    lcd.scrollDisplayRight(); 
  
  
      // wipe previous position of truck
      printStr("  ", positionCounter, SECOND_ROW);
      
      //draw truck on next position
      printChar(TRUCK1_CHAR, positionCounter+1, SECOND_ROW);    
      printChar(TRUCK2_CHAR, positionCounter+2, SECOND_ROW);
      
      if (positionCounter+2 == HUMAN_POSITION) {
        if (humanRow == SECOND_ROW) {
          score = score - 1;
        } else {
          score = score + 1;
        }
        
        if (score >= 10 || score <= -10) {
          IS_OVER = true;
        }
        
        break;
      }
      
      // wait a bit:
      delay(250);
    }
    
  //  debug();
      
    delay(1000);
     
    // wipe guy
    printStr(" ", HUMAN_POSITION, FIRST_ROW);
    
    //wipe truck 
    printStr("  ", HUMAN_POSITION-1u
    u
    , SECOND_ROW);
  }
}


