#include <Arduino.h>
#include <FastLED.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_LEDS 11
#define DELAY 100
#define DATA_PIN 12
#define JUMP 400
CRGB leds[NUM_LEDS];

void shiftLeds(){
  for(int i = 0; i < NUM_LEDS-1; i++){
    leds[i+1] = leds[i];
    FastLED.show();
    delay(DELAY);
  }
}


//                                  <DUHA>
void doRainbow(){
  for(int i = 1; i < 256;i+=JUMP){
    shiftLeds();
    leds[0].setRGB(255,i,0);
    FastLED.show();
  }
  for(int i = 255; i >=0; i-=JUMP){
    shiftLeds();
    leds[0].setRGB(i,255,0);
    FastLED.show();
  }
  for(int i = 1; i < 256;i+=JUMP){
    shiftLeds();
    leds[0].setRGB(0,255,i);
    FastLED.show();
  }
  for(int i = 255; i >=0; i-=JUMP){
    shiftLeds();
    leds[0].setRGB(0,i,255);
    FastLED.show();
  }
  for(int i = 1; i < 256;i+=JUMP){
    shiftLeds();
    leds[0].setRGB(i,0,255);
    FastLED.show();
  }
  for(int i = 255; i >=0; i-=JUMP){
    shiftLeds();
    leds[0].setRGB(255,0,i);
    FastLED.show();
  }
}


void clear(){
  for(int i = 0; i<NUM_LEDS;i++){
    leds[i].setRGB(0,0,0);
    FastLED.show();
    delay(100);
  }
}

bool isPrime(int number){
  if(number % 2 == 0){
    return true;
  }
  return false;
}

void leftW(){
  clear();
  delay(500);
  for(int i = 0; i<NUM_LEDS; i++){
    leds[i].setRGB(2,2,255);
    FastLED.show();
    delay(30);
  }
}
void rightW(){
  clear();
  delay(500);
  for(int i = NUM_LEDS-1; i>=0;i--){
    leds[i].setRGB(255,2,2);
    FastLED.show();
    delay(30);
  }
}
void draw(){
  clear();
  delay(500);
  for(int i = 0; i<floor(NUM_LEDS/2); i++){
    leds[i].setRGB(2,2,255);
    leds[NUM_LEDS-1-i].setRGB(255,2,2);
    FastLED.show();
    delay(30);
  }
} 

bool Play(int left, int right, int center){
  while(1){
    left += rand() % 2;
    right += rand() % 2;
    for(int i = 0; i < left; i++){
      leds[i].setRGB(2,2,255);
    }
    for(int i = NUM_LEDS-1; i >= NUM_LEDS-right;i--){
      leds[i].setRGB(255,2,2);
    }
    if(left >= center && right >= center){
      draw();
      return true;
    }
    else if(left >= center){
      leftW();
      return true;
    }
    else if(right >= center){
      rightW();
      return true;
    }
    FastLED.show();
    delay(500);
  }
}

//                                  <RACE>
void Race(){
  clear();
  leds[0].setRGB(2,2,255);
  leds[NUM_LEDS-1].setRGB(255,2,2);
  int center = floor(NUM_LEDS/2);
  if(isPrime(NUM_LEDS)){
    leds[center].setRGB(237, 222, 12);
    leds[center-1].setRGB(237, 222, 12);
  }
  else{
    leds[center].setRGB(237, 222, 12);
  }
  FastLED.show();
  int left = 1;
  int right = 1;
  delay(1000);
  Play(left,right,center);
  delay(3000);
}





void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B,DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  Race();
  
}



