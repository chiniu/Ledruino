//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
 /* ADK  50 (MISO), 51 (MOSI), 52 (SCK), 53 (SS) */
//LedControl lc=LedControl(12,11,10,1);
LedControl lc=LedControl(51,52,53,1);

/* 5x5 Font from http://arduino.cc/forum/index.php/topic,7384.0.html , thanks */
byte a[8]={0x00,0x7c,0x44,0x44,0x7c,0x44,0x00,0x00};    
  byte b[8]={0x00,0x7c,0x44,0x78,0x44,0x7c,0x00,0x00};  
  byte c[8]={0x00,0x7c,0x40,0x40,0x40,0x7c,0x00,0x00};  
  byte d[8]={0x00,0x78,0x44,0x44,0x44,0x78,0x00,0x00};  
  byte e[8]={0x00,0x7c,0x40,0x78,0x40,0x7c,0x00,0x00};
  byte f[8]={0x00,0x7c,0x40,0x70,0x40,0x40,0x00,0x00};
  byte g[8]={0x00,0x7c,0x40,0x4c,0x44,0x7c,0x00,0x00};
  byte h[8]={0x00,0x44,0x44,0x7c,0x44,0x44,0x00,0x00};
  byte i[8]={0x00,0x7c,0x10,0x10,0x10,0x7c,0x00,0x00};
  byte j[8]={0x00,0x0c,0x04,0x04,0x44,0x7c,0x00,0x00};
  byte k[8]={0x00,0x44,0x48,0x70,0x48,0x44,0x00,0x00};
  byte l[8]={0x00,0x40,0x40,0x40,0x40,0x7c,0x00,0x00};
  byte m[8]={0x00,0x44,0x6c,0x54,0x44,0x44,0x00,0x00};
  byte n[8]={0x00,0x44,0x64,0x54,0x4c,0x44,0x00,0x00};
  byte o[8]={0x00,0x38,0x44,0x44,0x44,0x38,0x00,0x00};  
  byte p[8]={0x00,0x78,0x44,0x78,0x40,0x40,0x00,0x00};              
  byte q[8]={0x00,0x7c,0x44,0x44,0x7c,0x10,0x00,0x00};            
  byte r[8]={0x00,0x78,0x44,0x78,0x44,0x44,0x00,0x00};            
  byte s[8]={0x00,0x7c,0x40,0x7c,0x04,0x7c,0x00,0x00};            
  byte t[8]={0x00,0x7c,0x10,0x10,0x10,0x10,0x00,0x00};              
  byte u[8]={0x00,0x44,0x44,0x44,0x44,0x7c,0x00,0x00};            
  byte v[8]={0x00,0x44,0x44,0x28,0x28,0x10,0x00,0x00};            
  byte w[8]={0x00,0x44,0x44,0x54,0x54,0x28,0x00,0x00};            
  byte x[8]={0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00};            
  byte y[8]={0x00,0x44,0x44,0x28,0x10,0x10,0x00,0x00};            
  byte z[8]={0x00,0x7c,0x08,0x10,0x20,0x7c,0x00,0x00};            
  
  byte ze[8]={0x00,0x7c,0x4c,0x54,0x64,0x7c,0x00,0x00};            
  byte on[8]={0x00,0x10,0x30,0x10,0x10,0x38,0x00,0x00};            
  byte tw[8]={0x00,0x78,0x04,0x38,0x40,0x7c,0x00,0x00};            
  byte th[8]={0x00,0x7c,0x04,0x38,0x04,0x7c,0x00,0x00};            
  byte fo[8]={0x00,0x40,0x40,0x50,0x7c,0x10,0x00,0x00};            
  byte fi[8]={0x00,0x7c,0x40,0x78,0x04,0x78,0x00,0x00};            
  byte si[8]={0x00,0x7c,0x40,0x7c,0x44,0x7c,0x00,0x00};            
  byte se[8]={0x00,0x7c,0x04,0x08,0x10,0x10,0x00,0x00};            
  byte ei[8]={0x00,0x7c,0x44,0x7c,0x44,0x7c,0x00,0x00};            
  byte ni[8]={0x00,0x7c,0x44,0x7c,0x04,0x7c,0x00,0x00};

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
  byte d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
  byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
  byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* now display them one by one with a small delay */
  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  delay(delaytime);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  delay(delaytime);
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(delaytime);
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  delay(delaytime);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(delaytime);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  delay(delaytime);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  delay(delaytime);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime);
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime);
    lc.setRow(0,row,B10100000);
    delay(delaytime);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime);
      lc.setRow(0,row,B10100000);
      delay(delaytime);
      lc.setRow(0,row,(byte)0);
    }
  }
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime);
    lc.setColumn(0,col,B10100000);
    delay(delaytime);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime);
      lc.setColumn(0,col,B10100000);
      delay(delaytime);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime);
      lc.setLed(0,row,col,true);
      delay(delaytime);
      for(int i=0;i<col;i++) {
        lc.setLed(0,row,col,false);
        delay(delaytime);
        lc.setLed(0,row,col,true);
        delay(delaytime);
      }
    }
  }
}

void show_c(){
    
  for(int i=0; i<8;i++){
  lc.setRow(0,i,b[i]);
  }
}
void square(){
   for(int s = 0 ; s < 8 ; s++){
     for(int row = s ; row < 8-s ; row++){
       for(int col = s; col < 8-s ; col++){
         lc.setLed(0,row,col,true);
       } 
     } 
     delay(200);
     lc.clearDisplay(0);
   }
   
  
}


                
int heart1_bmp[]={0x00, 0x0E, 0x11, 0x21, 0x42, 0x21, 0x11, 0x0E};
int heart2_bmp[]={0x00, 0x0E, 0x1F, 0x3F, 0x7E, 0x3F, 0x1F, 0x0E};
static uint8_t __attribute__ ((progmem)) smile_bmp1[]={0x3C, 0x42, 0x95, 0xA1, 0xA1, 0x95, 0x42, 0x3C};
static uint8_t __attribute__ ((progmem)) smile_bmp2[]={ 0x42, 0x95, 0xA1, 0xA1, 0x95, 0x42, 0x3C, 0x00};
static uint8_t __attribute__ ((progmem)) smile_bmp3[]={0x95, 0xA1, 0xA1, 0x95, 0x42, 0x3C, 0x00, 0x00};
static uint8_t __attribute__ ((progmem)) smile_bmp4[]={0xA1, 0xA1, 0x95, 0x42, 0x3C, 0x00, 0x00, 0x00};
static uint8_t __attribute__ ((progmem)) smile_bmp5[]={0xA1, 0x95, 0x42, 0x3C, 0x00, 0x00, 0x00, 0x00};
static uint8_t __attribute__ ((progmem)) smile_bmp6[]={0x95, 0x42, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00};
static uint8_t __attribute__ ((progmem)) smile_bmp7[]={0x42, 0x3C, 0x00 0x00, 0x00, 0x00, 0x00, 0x00};
static uint8_t __attribute__ ((progmem)) smile_bmp8[]={0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static uint8_t __attribute__ ((progmem)) smile_bmp9[]={0x00, 0x00, 0x000, 0x00, 0x00, 0x00, 0x00, 0x00};
static uint8_t __attribute__ ((progmem)) smile_bmp[]={0x3C, 0x42, 0x95, 0xA1, 0xA1, 0x95, 0x42, 0x3C};
static uint8_t __attribute__ ((progmem)) frown_bmp[]={0x3C, 0x42, 0xA5, 0x91, 0x91, 0xA5, 0x42, 0x3C};
static uint8_t __attribute__ ((progmem)) neutral_bmp[]={0x3C, 0x42, 0x95, 0x91, 0x91, 0x95, 0x42, 0x3C};

void myheard1(){
    
  for(int i=0; i<8;i++){
  lc.setRow(0,i,heart1_bmp[i]);
  }
}

void myheard2(){
    
  for(int i=0; i<8;i++){
  lc.setRow(0,i,heart2_bmp[i]);
  }
}

void loop() { 
  //writeArduinoOnMatrix();
  //rows();
  //columns();
  //single();
  //show_c();
//  myheard1();
  //delay(300);
  //myheard2();
  //delay(300);
  square();
  
  
}
