#include <stdio.h>  

#include <hd44780.h>
#include <time.h> 
#include <Wire.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <LiquidCrystal.h>


const char button_1_q1[] PROGMEM = "Color of water";
const char button_2_q1[] PROGMEM = "Color of the sun";
const char button_3_q1[] PROGMEM = "Color of grass";
const char button_4_q1[] PROGMEM = "Color of fire";

const char button_1_q2[] PROGMEM = "Argentina Flag";
const char button_2_q2[] PROGMEM = "Brunei Flag";
const char button_3_q2[] PROGMEM = "Brazil Flag";
const char button_4_q2[] PROGMEM = "China Flag";

const char button_1_q3[] PROGMEM = "Starts with b";
const char button_2_q3[] PROGMEM = "Starts with y";
const char button_3_q3[] PROGMEM = "Starts with g";
const char button_4_q3[] PROGMEM = "Starts with r";

const char button_1_q4[] PROGMEM = "Color of the sky";
const char button_2_q4[] PROGMEM = "Color of urine";
const char button_3_q4[] PROGMEM = "Color of trees";
const char button_4_q4[] PROGMEM = "Color of magma";

const char button_1_q5[] PROGMEM = "Ends with e";
const char button_2_q5[] PROGMEM = "Ends with w";
const char button_3_q5[] PROGMEM = "Ends with n";
const char button_4_q5[] PROGMEM = "Ends with d";

const char button_1_q6[] PROGMEM = "Kosovo Flag";
const char button_2_q6[] PROGMEM = "Colombia Flag";
const char button_3_q6[] PROGMEM = "Mauritania Flag";
const char button_4_q6[] PROGMEM = "Morocco Flag";

const char button_1_q7[] PROGMEM = "Color of Dory";
const char button_2_q7[] PROGMEM = "Color of Bubbles";
const char button_3_q7[] PROGMEM = "Color of Blenny";
const char button_4_q7[] PROGMEM = "Color of Jacques";

const char button_1_q8[] PROGMEM = "Color of bluejays";
const char button_2_q8[] PROGMEM = "Color of bees";
const char button_3_q8[] PROGMEM = "Color of frogs";
const char button_4_q8[] PROGMEM = "Color of flamingos";
                                       
const char *const QUESTIONS[8][4] PROGMEM = {{button_1_q1, button_2_q1, button_3_q1, button_4_q1},
                                              {button_1_q2, button_2_q2, button_3_q2, button_4_q2},
                                              {button_1_q3, button_2_q2, button_3_q3, button_4_q3},
                                              {button_1_q4, button_2_q2, button_3_q4, button_4_q4},
                                              {button_1_q5, button_2_q2, button_3_q5, button_4_q5},
                                              {button_1_q6, button_2_q2, button_3_q6, button_4_q6},
                                              {button_1_q7, button_2_q2, button_3_q7, button_4_q7},
                                              {button_1_q8, button_2_q2, button_3_q8, button_4_q8}};
                                             
                                            

char buffer[16]; 


const int blue = 7;
const int yellow = 6;
const int red = 4;
const int green = 5;
const int counterclock = A4;
const int clearDFF = A5;

LiquidCrystal screen(13,12,11,10,9,8);

bool correctBlue;
bool correctYellow;
bool correctGreen;
bool correctRed;

bool stateBlue;
bool stateYellow;
bool stateGreen;
bool stateRed;

bool blueAND;
bool yellowAND;
bool greenAND;
bool redAND;

bool changeQuestion;

void setup() {

    Serial.begin(9600);
    bool gameStart = false;
    int b;
    int q;
    int decimal = 0;
  
  
    pinMode(blue, INPUT_PULLUP);
    pinMode(yellow, INPUT_PULLUP);
    pinMode(red, INPUT_PULLUP);
    pinMode(green, INPUT_PULLUP);
   
    pinMode(clearDFF, OUTPUT);
    pinMode(counterclock, OUTPUT);
    
    screen.begin(16,2);
    screen.clear();
    screen.print("NAME of the GAME");
    screen.setCursor(0,1);
    screen.print("Press Y to Start");
    digitalWrite(clearDFF, HIGH);
        
    randomSeed(analogRead(A0));


}

void loop() {
    // put your main code here, to run repeatedly:
    
    bool gameStart;
    int b;
    int q;
    bool game;
    bool boot = true;
    int timer = 0;
  
    correctBlue = LOW;
    correctYellow = LOW;
    correctGreen = LOW;
    correctRed = LOW;
  
    stateBlue;
    stateYellow;
    stateGreen;
    stateRed;
    
    blueAND;
    yellowAND;
    greenAND;
    redAND;
   
    screen.begin(16,2);
    screen.clear();
    screen.print("NAME of the GAME");
    screen.setCursor(0,1);
    screen.print("Press Y to Start");
    digitalWrite(clearDFF, LOW);
    digitalWrite(clearDFF, HIGH);


    while(boot == true){
        digitalWrite(clearDFF, HIGH);
        if(digitalRead(yellow) == HIGH) {
            digitalWrite(clearDFF, HIGH);
            gameStart = true;
            game = true;
            boot = false;
      
            screen.clear();
            screen.print("Starting in....");
            delay(1000);
            screen.clear();
            screen.print("3");
            delay(1000);
            screen.clear();
            screen.print("2");
            delay(1000);
            screen.clear();
            screen.print("1");
            delay(1000);
        }
    }
  
    while(gameStart == true) {
  
       digitalWrite(clearDFF, HIGH);
       digitalWrite(counterclock, LOW);
       b = random(0,8);
       q = random(0,4);
  
   
       screen.clear();
       screen.setCursor(0,0);
   
       delay(1000);
       screen.print(strcpy_P(buffer, (char*)pgm_read_word(&(QUESTIONS[b][q]))));
       
       while(game == true){
  
          changeQuestion = false;
             
          if (q == 0) { //blue
              correctBlue = HIGH;
          }
          if (q == 1) { //yellow
              correctYellow = HIGH;
          }
          if (q == 2) { //green
              correctGreen = HIGH;
          }
          if (q == 3) { //red
              correctRed = HIGH;
          }  
           
  
          delay(1);
     
          timer += 1;
          Serial.print("Timer: ");
          Serial.println(timer);
      
          delay(1);
          
          while(digitalRead(yellow) == HIGH or digitalRead(blue) == HIGH or digitalRead(red) == HIGH or digitalRead(green) == HIGH /*and readButt == true*/) {
  
  
              stateBlue = digitalRead(blue);
              stateYellow = digitalRead(yellow);
              stateGreen = digitalRead(green);
              stateRed = digitalRead(red);
              
              blueAND = stateBlue & correctBlue;
              yellowAND = stateYellow & correctYellow;
              greenAND = stateGreen & correctGreen;
              redAND = stateRed & correctRed;
              
              digitalWrite(counterclock, blueAND);
              digitalWrite(counterclock, yellowAND);
              digitalWrite(counterclock, greenAND);
              digitalWrite(counterclock, redAND);
  
              /*
              Serial.print("Blue correct: ");
              Serial.println(correctBlue);
              Serial.println(blueAND);
              Serial.println(stateBlue);
              Serial.print("Yellow correct: ");
              Serial.println(correctYellow);
              Serial.println(yellowAND);
              Serial.println(stateYellow);
              Serial.print("Green correct: ");
              Serial.println(correctGreen);
              Serial.println(greenAND);
              Serial.println(stateGreen);
              Serial.print("Red correct: ");
              Serial.println(correctRed);
              Serial.println(redAND);
              Serial.println(stateRed);
              Serial.print("Q is: ");
              Serial.println(q);
              */
  
              delay(200);
  
              changeQuestion = true;
      
              correctBlue = LOW;
              correctYellow = LOW;
              correctGreen = LOW;
              correctRed = LOW;
  
          }
          
          while(changeQuestion == true){
              screen.clear();
              screen.setCursor(0,0);
              screen.print("Next Question");
              
              delay(1000);
              
              b = random(0,8);
              q = random(0,4);      
              screen.clear();
              screen.setCursor(0,0);
              
              
              screen.print(strcpy_P(buffer, (char*)pgm_read_word(&(QUESTIONS[b][q]))));
              game = true;
              //screen.setCursor(0,1);
              //screen.print("Score: ");
  
              changeQuestion = false;
  
          
          }
  
  
  
        
          if(timer >= 1500) {
              
              screen.clear();
              screen.setCursor(0,0);
              screen.print("GAME OVER");
              delay(10000);
              game = false;
              gameStart = false;
  
         
          
          }
       }
    }
}
