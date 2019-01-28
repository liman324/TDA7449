#include <Wire.h>
#include <TDA7449.h>
  TDA7449 tda;

void setup(){ 
  Serial.begin(9600);Wire.begin();
}

void loop(){
  audio();
  delay(1000);
}

void audio(){
  tda.setInput(1); //         int 1...2 //// номер входа
  tda.inputGain(0); //        int 0...15 (шаг 2дБ)    0...30 дБ  //// усиление
  tda.setVolume(30); //       int 0...47 (шаг 1 дБ)  -47...0 дБ  //// громкость
  tda.setBass(0); //          int -7...+7 (шаг 2 дБ) -14...14 дБ //// тембр НЧ
  tda.setTreble(0); //        int -7...+7 (шаг 2 дБ) -14...14 дБ //// тембр ВЧ
  tda.setAttL(10); //          int 0...72 (шаг 1дБ)    -72...0 дБ 
  tda.setAttR(10); //          int 0...72 (шаг 1дБ)    -72...0 дБ
}
