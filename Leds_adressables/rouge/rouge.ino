#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    120
CRGB leds[NUM_LEDS];
int delais = 10;
void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  
  allume(255,0,0);
}

void allume(int R, int V, int B){
    for(int i = 0;i<=120;i++){
      delay(100);
      leds[i] = CRGB(R, V, B);
      FastLED.show();
    }
}
