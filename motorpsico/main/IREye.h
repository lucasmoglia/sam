/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef IREye_h
#define IREye_h
#include <IRremote.h>

class IREye
{
  public: 
    IREye(IRrecv *passedIr, int pin);
    void setup();
    void recieve();
  private:
    int _pin;
    IRrecv *_irrecv;
    IRsend irsend;
    decode_results _results;
    void _sendSonyMsg(uint32_t _ircode);
};

#endif
