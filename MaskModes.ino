#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    118
int BRIGHTNESS = 255;
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
  Serial.println(mode);
  Serial.println(bpm);
  
  switch (mode) {
    case 1:
      mode1(bpm);
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
    case 10:
      mode10(bpm);
      goBack = 10;
      break;
    case 11:
      mode11(bpm);
      goBack = 11;
      break;
    case 12:
      mode12(bpm);
      goBack = 12;
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
  

void mode1(float bpm) {
  
}

void mode2(float bpm) {
  currentPalette = RainbowStripeColors_p;
  currentBlending = NOBLEND;
  updatePalette(bpm);
}

void mode3(float bpm) {
  currentPalette = CloudColors_p;
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode4(float bpm) {
  currentPalette = LavaColors_p;
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode5(float bpm) {
  currentPalette = ForestColors_p;
  currentBlending = LINEARBLEND;
  updatePalette(bpm);
}

void mode6(float bpm) {
  currentPalette = OceanColors_p;
  currentBlending = LINEARBLEND;
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

void mode10(float bpm) {
  SetupBlackAndWhiteStripedPalette();
  currentBlending = NOBLEND;
  updatePalette(bpm);
}

void mode11(float bpm) {
  SetupBlackAndWhiteStripedPalette2();
  currentBlending = NOBLEND;
  updatePalette(bpm);
}

void mode12(float bpm) {
  SetupBlackAndWhiteStripedPalette3();
  currentBlending = NOBLEND;
  updatePalette(bpm);
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
