//VS Supply voltage 6 9 10.2 V
//VCL Max input signal handling 2 VRMS
//THD Total harmonic distortion V = 0.1 Vrms f = 1 kHz 0.01 0.1 %
//S/N Signal-to-noise ratio Vout = 1 Vrms (mode = OFF) 106 dB
//SC Channel separation f = 1 KHz 90 dB
//Input gain (2 dB step) 0 30 dB
//Volume control (1 dB step) -47 0 dB
//Treble control (2 dB step) -14 14 dB
//Bass control (2 dB step) -14 14 dB
//Balance control 1 dB step -79 0 dB
//Mute attenuation 100 dB
////////////////////////////////////////////////////////////////////////////
// TDA7449 | rcl-radio.ru | liman324@yandex.ru | Автор: Лиман А.А.

#ifndef TDA7449_H
#define TDA7449_H

#define TDA7449_address 0x88 // адрес

//Sub addresses
#define TDA7449_INP_SEL    0x00
#define TDA7449_INP_GAIN   0x01
#define TDA7449_VOLUME     0x02
#define TDA7449_BASS       0x04
#define TDA7449_TREBLE     0x05
#define TDA7449_ATT_RIGHT  0x06
#define TDA7449_ATT_LEFT   0x07

//Input selection
#define TDA7449_INP1       0x03
#define TDA7449_INP2       0x02


#include <Arduino.h>
class TDA7449
{
  public:
    TDA7449();
        void setInput(int input); //        int 1...2 //// номер входа
	void inputGain(int gain); //        int 0...15 (шаг 2дБ)    0...30 дБ  //// усиление
	void setVolume(int volume); //      int 0...47 (шаг 1 дБ)  -47...0 дБ  //// громкость
        void setBass(int bass); //          int -7...+7 (шаг 2 дБ) -14...14 дБ //// тембр НЧ
        void setTreble(int treble); //      int -7...+7 (шаг 2 дБ) -14...14 дБ //// тембр ВЧ
/////////////////////// для регулировки баланса до -79 дБ, ограничено программно до -8 дБ /////////////////////////////////
        void setAttL(int att_l); //         int 0...8 (шаг 1дБ)    -8...0 дБ 
        void setAttR(int att_r); //         int 0...8 (шаг 1дБ)    -8...0 дБ
/////////////////////////////////////////////////////////////////////////////////	
  private:
	void writeWire(char a, char b);
};
	
#endif //TDA7449_H
