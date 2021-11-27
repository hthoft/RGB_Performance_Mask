#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    118
int BRIGHTNESS = 20;
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

const byte numChars = 32;
char receivedChars[numChars];


int goBack = 0;

String incomingString;
int mode = 0;

int dataNumber = 0;

String Mode;
String Brightness;

boolean newData = false;


#define UPDATES_PER_SECOND 100

unsigned long previousMillis = 0; 

int ms = 0;
int bpm = 128;
int ledStates = 0;

int callback = 0;
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

void setup() { 
    Serial.begin(115200);
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

}

void loop() { 
  
  recvWithEndMarker();
  showNewData();

  FastLED.setBrightness(  BRIGHTNESS );
  
  switch (mode) {
    case 1:
      mode1();
      goBack = 1;
      break;
    case 2:
      mode2(bpm);
      goBack = 2;
      break;
    case 3:
      mode3(bpm);
      goBack = 3;
      break;
    case 4:
      mode4(bpm);
      goBack = 4;
      break;
    case 5:
      mode5(bpm);
      goBack = 5;
      break;
    case 6:
      mode6(bpm);
      goBack = 6;
      break;
    case 7:
      mode7(128);
      goBack = 7;
      break;
    case 8:
      mode8(256);
      goBack = 8;
      break;
    case 9:
      mode9(512);
      goBack = 9;
      break;


    case 11:
      mode11();
      goBack = 11;
      break;
    case 12:
      mode12();
      goBack = 12;
      break;
    case 13:
      mode13();
      goBack = 13;
      break;
    case 14:
      mode14();
      goBack = 14;
      break;
    case 15:
      mode15();
      goBack = 15;
      break;
    case 16:
      mode16();
      goBack = 16;
      break;
    case 17:
      mode17();
      goBack = 17;
      break;
    case 18:
      mode18();
      goBack = 18;
      break;
    case 19:
      mode19();
      goBack = 19;
      break;

    case 21:
      mode21(bpm);
      goBack = 21;
      break;
    case 22:
      mode22(bpm);
      goBack = 22;
      break;
    case 23:
      mode23(bpm);
      goBack = 23;
      break;
    case 24:
      mode24(bpm);
      goBack = 24;
      break;
    case 25:
      mode25(bpm);
      goBack = 25;
      break;
    case 26:
      mode26(bpm);
      goBack = 26;
      break;
    case 27:
      mode27(bpm);
      goBack = 27;
      break;
    case 28:
      mode28(bpm);
      goBack = 28;
      break;
    case 29:
      mode29(bpm);
      goBack = 29;
      break;

      case 41:
      mode41(bpm);
      goBack = 41;
      break;
    case 42:
      mode42(bpm);
      goBack = 42;
      break;
    case 43:
      mode43(bpm);
      goBack = 43;
      break;
    case 44:
      mode44(bpm);
      goBack = 44;
      break;
    case 45:
      mode45(bpm);
      goBack = 45;
      break;
    case 46:
      mode46(bpm);
      goBack = 46;
      break;
    case 47:
      mode47(bpm);
      goBack = 47;
      break;
    case 48:
      mode48(bpm);
      goBack = 48;
      break;
    case 49:
      mode49(bpm);
      goBack = 49;
      break;

    case 50:
      mode50(bpm);
      goBack = 50;
      break;
    case 51:
      mode51(bpm);
      goBack = 51;
      break;
      
    case 81:
      BRIGHTNESS = 255*0.15;
      mode = goBack;
      break;
    case 82:
      BRIGHTNESS = 255*0.25;
      mode = goBack;
      break;
    case 83:
      BRIGHTNESS = 255*0.35;
      mode = goBack;
      break;
    case 84:
      BRIGHTNESS = 255*0.50;
      mode = goBack;
      break;
    case 85:
      BRIGHTNESS = 255*0.60;
      mode = goBack;
      break;
    case 86:
      BRIGHTNESS = 255*0.70;
      mode = goBack;
      break;
    case 87:
      BRIGHTNESS = 255*0.80;
      mode = goBack;
      break;
    case 88:
      BRIGHTNESS = 255*0.90;
      mode = goBack;
      break;
    case 89:
      BRIGHTNESS = 255;
      mode = goBack;
      break;
    case 91:
      bpm = 100;
      mode = goBack;
      break;
    case 92:
      bpm = 110;
      mode = goBack;
      break;
    case 93:
      bpm = 120;
      mode = goBack;
      break;
    case 94:
      bpm = 125;
      mode = goBack;
      break;
    case 95:
      bpm = 128;
      mode = goBack;
      break;
    case 96:
      bpm = 130;
      mode = goBack;
      break;
    case 97:
      bpm = 132;
      mode = goBack;
      break;
    case 98:
      bpm = 140;
      mode = goBack;
      break;
    case 99:
      bpm = 150;
      mode = goBack;
      break;
    
    default:
      currentPalette = RainbowColors_p;
      currentBlending = LINEARBLEND;
      updatePalette(bpm);
      break;
  }
  
}
  

void mode2(float bpm) {
  SetupBlackAndWhiteStripedPalette();
  currentBlending = NOBLEND;
  updatePalette(bpm);
}
void mode3(float bpm) {
  SetupBlackAndWhiteStripedPalette2();
  currentBlending = NOBLEND;
  updatePalette(bpm);
}
void mode4(float bpm) {
  SetupBlackAndWhiteStripedPalette3();
  currentBlending = NOBLEND;
  updatePalette(bpm);
}
void mode5(float bpm) {
  SetupBlackAndWhiteStripedPalette4();
  currentBlending = NOBLEND;
  updatePalette(bpm);
}
void mode6(float bpm) {
  SetupBlackAndWhiteStripedPalette5();
  currentBlending = NOBLEND;
  updatePalette(bpm);
}


void mode7(float bpm) {
  long interval = 60/bpm*1000/2;
  for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(interval);
  mode = 7;
}

void mode8(float bpm) {
  long interval = 60/bpm*1000/2;
  for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(interval);
  mode = 8;
}

void mode9(float bpm) {
  long interval = 60/bpm*1000/2;
  for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(interval);
  mode = 9;
}


void mode50(float bpm) {
  long interval = 60/bpm*1000/6;
  int layer1[] = {64};
  int layer2[] = {56, 63, 65, 74};
  int layer3[] = {48, 49, 50, 82, 83, 84, 85, 86};
  int layer4[] = {34, 35, 36, 37, 38, 39, 40, 73, 75, 81, 87, 91, 92};
  int layer5[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 33, 41, 62, 66, 72, 76, 80, 88, 90, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102};
  int layer6[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 17, 27, 32, 42, 61, 67, 71, 77, 79, 89};

  for (int i = 0; i < sizeof(layer1); i++) {
    leds[layer1[i]] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i<sizeof(layer1); i++) {
    leds[layer1[i]] = CRGB::Black;
  }
  for (int i = 0; i<sizeof(layer2); i++) {
    leds[layer2[i]] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i<sizeof(layer2); i++) {
    leds[layer2[i]] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 0; i<sizeof(layer3); i++) {
    leds[layer3[i]] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i<sizeof(layer3); i++) {
    leds[layer3[i]] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 0; i<sizeof(layer4); i++) {
    leds[layer4[i]] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i<sizeof(layer4); i++) {
    leds[layer4[i]] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 0; i<sizeof(layer5); i++) {
    leds[layer5[i]] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i<sizeof(layer5); i++) {
    leds[layer5[i]] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 0; i<sizeof(layer6); i++) {
    leds[layer6[i]] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i<sizeof(layer6); i++) {
    leds[layer6[i]] = CRGB::Black;
  }
  FastLED.show();
}

void mode51(float bpm) {
  long interval = 60/bpm*1000/13;
  int layer1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  int layer2[] = {15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
  int layer3[] = {};
  int layer4[] = {34, 35, 36, 37, 38, 39, 40, 73, 75, 81, 87, 91, 92};
  int layer5[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 33, 41, 62, 66, 72, 76, 80, 88, 90, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102};
  int layer6[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 17, 27, 32, 42, 61, 67, 71, 77, 79, 89};

  for (int i = 0; i < 15; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 0; i<15; i++) {
    leds[i] = CRGB::Black;
  }
  for (int i = 15; i<30; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 15; i<30; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 30; i<45; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 30; i<45; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 45; i<54; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 45; i<54; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 54; i<59; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 54; i<59; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 59; i<70; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 59; i<70; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 70; i<90; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 70; i<90; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 90; i<94; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 90; i<94; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 94; i<103; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 94; i<103; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 103; i<108; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 103; i<108; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 108; i<111; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 108; i<111; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  for (int i = 111; i<118; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(interval);
  for (int i = 111; i<118; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void mode1() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
      }
  FastLED.show();
}

void mode11() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::White;
      }
  FastLED.show();
}
void mode12() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::Red;
      }
  FastLED.show();
}
void mode13() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::Orange;
      }
  FastLED.show();
}
void mode14() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::Yellow;
      }
  FastLED.show();
}
void mode15() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::Green;
      }
  FastLED.show();
}
void mode16() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::Cyan;
      }
  FastLED.show();
}
void mode17() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::Blue;
      }
  FastLED.show();
}
void mode18() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::Magenta;
      }
  FastLED.show();
}
void mode19() {
  for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB::Pink;
      }
  FastLED.show();
}


void mode21(float bpm) {
  currentPalette = CloudColors_p;
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode22(float bpm) {
  currentPalette = LavaColors_p;
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode23(float bpm) {
  currentPalette = ForestColors_p;
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode24(float bpm) {
  currentPalette = OceanColors_p;
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode25(float bpm) {
  SetupPurpleAndGreenPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode26(float bpm) {
  SetupOrangeAndCyanPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode27(float bpm) {
  SetupRedAndBluePalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode28(float bpm) {
  SetupOrangeAndGreenPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode29(float bpm) {
  SetupYellowAndRedPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void SetupPurpleAndGreenPalette()
{
    CRGB purple = CHSV( HUE_PURPLE, 255, 255);
    CRGB green  = CHSV( HUE_GREEN, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}

void SetupOrangeAndCyanPalette()
{
    CRGB purple = CHSV( HUE_ORANGE, 255, 255);
    CRGB green  = CHSV( HUE_BLUE, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}
void SetupRedAndBluePalette()
{
    CRGB purple = CHSV( HUE_RED, 255, 255);
    CRGB green  = CHSV( HUE_BLUE, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}
void SetupOrangeAndGreenPalette()
{
    CRGB purple = CHSV( HUE_ORANGE, 255, 255);
    CRGB green  = CHSV( HUE_GREEN, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}
void SetupYellowAndRedPalette()
{
    CRGB purple = CHSV( HUE_YELLOW, 255, 255);
    CRGB green  = CHSV( HUE_RED, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}




void mode41(float bpm) {
  SetupWhitePalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode42(float bpm) {
  SetupRedPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode43(float bpm) {
  SetupOrangePalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode44(float bpm) {
  SetupYellowPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode45(float bpm) {
  SetupGreenPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode46(float bpm) {
  SetupCyanPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode47(float bpm) {
  SetupBluePalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode48(float bpm) {
  SetupMagentaPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode49(float bpm) {
  SetupPinkPalette();
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void SetupWhitePalette()
{
    CRGB white = CHSV( 255, 0, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   white,  white,  black,  black,
                                   white, white, black,  black,
                                   white,  white,  black,  black,
                                   white, white, black,  black );
}
void SetupRedPalette()
{
    CRGB red = CHSV( HUE_RED, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   red,  red,  black,  black,
                                   red, red, black,  black,
                                   red,  red,  black,  black,
                                   red, red, black,  black );
}
void SetupOrangePalette()
{
    CRGB orange = CHSV( HUE_ORANGE, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   orange,  orange,  black,  black,
                                   orange, orange, black,  black,
                                   orange,  orange,  black,  black,
                                   orange, orange, black,  black );
}
void SetupYellowPalette()
{
    CRGB yellow = CHSV( HUE_YELLOW, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   yellow,  yellow,  black,  black,
                                   yellow, yellow, black,  black,
                                   yellow,  yellow,  black,  black,
                                   yellow, yellow, black,  black );
}
void SetupGreenPalette()
{
    CRGB green = CHSV( HUE_GREEN, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   green, green, black,  black,
                                   green,  green,  black,  black,
                                   green, green, black,  black );
}
void SetupCyanPalette()
{
    CRGB cyan = CHSV( HUE_AQUA, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   cyan,  cyan,  black,  black,
                                   cyan, cyan, black,  black,
                                   cyan,  cyan,  black,  black,
                                   cyan, cyan, black,  black );
}
void SetupBluePalette()
{
    CRGB blue = CHSV( HUE_BLUE, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   blue,  blue,  black,  black,
                                   blue, blue, black,  black,
                                   blue,  blue,  black,  black,
                                   blue, blue, black,  black );
}
void SetupMagentaPalette()
{
    CRGB magenta = CHSV( HUE_PURPLE, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   magenta,  magenta,  black,  black,
                                   magenta, magenta, black,  black,
                                   magenta,  magenta,  black,  black,
                                   magenta, magenta, black,  black );
}
void SetupPinkPalette()
{
    CRGB pink = CHSV( HUE_PINK, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   pink,  pink,  black,  black,
                                   pink, pink, black,  black,
                                   pink,  pink,  black,  black,
                                   pink, pink, black,  black );
}


void SetupBlackAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[2] = CRGB::Blue;
    currentPalette[4] = CRGB::White;
    currentPalette[6] = CRGB::Blue;
    currentPalette[8] = CRGB::White;
    currentPalette[10] = CRGB::Blue;
    currentPalette[12] = CRGB::White;
    currentPalette[14] = CRGB::Blue;

}

void SetupBlackAndWhiteStripedPalette2()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[2] = CRGB::Green;
    currentPalette[4] = CRGB::White;
    currentPalette[6] = CRGB::Green;
    currentPalette[8] = CRGB::White;
    currentPalette[10] = CRGB::Green;
    currentPalette[12] = CRGB::White;
    currentPalette[14] = CRGB::Green;

}

void SetupBlackAndWhiteStripedPalette3()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[2] = CRGB::Red;
    currentPalette[4] = CRGB::White;
    currentPalette[6] = CRGB::Red;
    currentPalette[8] = CRGB::White;
    currentPalette[10] = CRGB::Red;
    currentPalette[12] = CRGB::White;
    currentPalette[14] = CRGB::Red;

}

void SetupBlackAndWhiteStripedPalette4()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[2] = CRGB::Black;
    currentPalette[4] = CRGB::White;
    currentPalette[6] = CRGB::Black;
    currentPalette[8] = CRGB::White;
    currentPalette[10] = CRGB::Black;
    currentPalette[12] = CRGB::White;
    currentPalette[14] = CRGB::Black;

}

void SetupBlackAndWhiteStripedPalette5()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[2] = CRGB::White;
    currentPalette[4] = CRGB::White;
    currentPalette[6] = CRGB::White;
    currentPalette[8] = CRGB::Black;
    currentPalette[10] = CRGB::Black;
    currentPalette[12] = CRGB::Black;
    currentPalette[14] = CRGB::Black;

}

void updatePalette(float bpm) {
    
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    Serial.println(map(bpm,100,150,70,1));
    FastLED.delay(map(bpm,100,150,70,1));
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '>';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        dataNumber = 0;             // new for this version
        dataNumber = atoi(receivedChars);   // new for this version
        Serial.print("Data as Number ... ");    // new for this version
        Serial.println(dataNumber);     // new for this version
        newData = false;
        if (callback == 0) {
          Serial.println("Brightness");
          mode = dataNumber;
        }
    }
}
