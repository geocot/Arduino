#include <FastLED.h>
#define PUISSANCE   100
#define LED_PIN     5
#define NUM_LEDS    30
CRGB leds[NUM_LEDS];
int delais = 30;
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
  allume(random(0,30), 0,PUISSANCE,0);  /*vert*/
  delay(delais);
  allume(random(0,30), PUISSANCE,0,0);  /*rouge*/
  delay(delais);
}

void allume(int ledNb, int R, int V, int B){
    
    leds[ledNb] = CRGB(R, V, B);
    /*fadeToBlackBy(leds,NUM_LEDS, 40);*/
    FastLED.show();
}
