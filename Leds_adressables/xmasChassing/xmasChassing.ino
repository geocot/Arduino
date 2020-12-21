#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    30
#define DELAIS       30
CRGB leds[NUM_LEDS];
int delais = 90;
void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop() {
  
   if (Serial.available() > 0) {
    delais = Serial.readString().toInt(); // read the incoming byte:
    Serial.print("Reçu: "); 
    Serial.println(delais); 
   }
    allumeCro(0,60,0);  /*vert*/
    allumeDec(60,0,0);  /*rouge*/
    allumeCro(0,0,60);  /*bleu*/
    allumeDec(0,0,0);  /*eteint*/
}

void allumeCro(int R, int V, int B){
  for(int i = 0;i<=NUM_LEDS;i++){
    leds[i] = CRGB(R, V, B);
    FastLED.show();
    delay(delais);
  }
}

void allumeDec(int R, int V, int B){
   for(int i = NUM_LEDS;i>=0;i--){
    leds[i] = CRGB(R, V, B);
    FastLED.show();
    delay(delais);
  }
}
