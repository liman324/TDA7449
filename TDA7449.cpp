#include <Arduino.h>
#include <Wire.h>
#include "TDA7449.h"

TDA7449::TDA7449(){
	Wire.begin();
}

void TDA7449::setVolume(int volume){
  volume = 47 - volume;
  writeWire(TDA7449_VOLUME, volume);
}

void TDA7449::setBass(int bass){
  switch (bass){
        case -7:bass = 0;break;
	case -6:bass = 1;break;
	case -5:bass = 2;break;
	case -4:bass = 3;break;
	case -3:bass = 4;break;
	case -2:bass = 5;break;
	case -1:bass = 6;break;
	case 0 :bass = 15;break;
	case 1 :bass = 14;break;
	case 2 :bass = 13;break;
	case 3 :bass = 12;break;
	case 4 :bass = 11;break;
	case 5 :bass = 10;break;
	case 6 :bass = 9;break;
	case 7 :bass = 8;break;}
  writeWire(TDA7449_BASS, bass);
}

void TDA7449::setTreble(int treble){
  switch (treble){
        case -7:treble = 0;break;
	case -6:treble = 1;break;
	case -5:treble = 2;break;
	case -4:treble = 3;break;
	case -3:treble = 4;break;
	case -2:treble = 5;break;
	case -1:treble = 6;break;
	case 0 :treble = 15;break;
	case 1 :treble = 14;break;
	case 2 :treble = 13;break;
	case 3 :treble = 12;break;
	case 4 :treble = 11;break;
	case 5 :treble = 10;break;
	case 6 :treble = 9;break;
	case 7 :treble = 8;break;}
  writeWire(TDA7449_TREBLE, treble);
}

void TDA7449::setInput(int input){
  switch (input) {
        case 1: input = 0x02;break;
	case 2: input = 0x03;break;}
  writeWire(TDA7449_INP_SEL,input);	
  } 

void TDA7449::inputGain(int gain){
  writeWire(TDA7449_INP_GAIN, gain);
}

void TDA7449::setAttR(int att_r){
  if(att_r > 8){att_r = 8;}
  writeWire(TDA7449_ATT_RIGHT, att_r);
}

void TDA7449::setAttL(int att_l){
  if(att_l > 8){att_l = 8;}
  writeWire(TDA7449_ATT_LEFT, att_l);
}

void TDA7449::writeWire(char a, char b){
  Wire.beginTransmission(TDA7449_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
