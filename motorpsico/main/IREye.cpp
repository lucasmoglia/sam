/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.

  SONY SOUND BAR
  ----------------------------
  SLEEP       0x030C (15 bits)
  POWER       0x540C (15 bits)
  BD/DVD      0x68114 (20 bits)
  SAT/CATV    0x600D (15 bits)
  GAME        0x1F0C (15 bits)
  SA-CD/CD    0x520C (15 bits)
  VIDEO       0x220C (15 bits)
  TV          0x2B0C (15 bits)
  FM          0x0C0C (15 bits)
  AM          0x2C0C (15 bits)
  USB         0xE8114 (20 bits)
  
  iPhone CTRL 0x4E110 (20 bits)
  REPEAT      0x34110 (20 bits)
  SHUFFLE     0x54110 (20 bits)
  A.F.D./2CH  0x710D (15 bits)
  MOVIE       0x610D (15 bits)
  MUSIC       0x490D (15 bits)
  
  DISPLAY     0x690C (15 bits)
  AMP MENU    0x770D (15 bits)
  RETURN      0xBE110 (20 bits)
  OPTIONS     0xCE110 (20 bits)
  UP          0x0F0D (15 bits)
  RIGHT       0x6F0D (15 bits)
  DOWN        0x4F0D (15 bits)
  LEFT        0x2F0D (15 bits)
  SELECT      0x180C (15 bits)
  
  HOME                      0x650C (15 bits)
  PRESET DOWN Skip Forward  0x0C110 (20 bits)
  PLAY PAUSE                0x5C110 (20 bits)
  PRESET UP Skip Reverse    0x8C110 (20 bits)
  STOP                      0x1C110 (20 bits)
  
  MUTE        0x140C (15 bits)
  VOLUME UP   0x240C (15 bits)
  VOLUME DOWN 0x640C (15 bits)
*/
#include "IREye.h"
#include "irSonyHtct370.h";

IREye::IREye(IRrecv *passedIr, int pin)
{
  if(pin){
    _pin = pin;
  }
  _irrecv = passedIr;
}

void IREye::setup(){
  _irrecv->enableIRIn(); // Start the receiver
  _irrecv->blink13(false);
}

void IREye::_sendSonyMsg(uint32_t _irCode) {
  int msg;
  Serial.println(_irCode);
  switch(_irCode) {
    case 16756815:
      sleep(&msg);
      break;
    case 16738455:
      power(&msg);
      break;
    case 16769565:
      up(&msg);
      break;
    case 16753245:
      down(&msg);
      break;
    case 16712445:
      right(&msg);
      break;
    case 16720605:
      left(&msg);
      break;
    case 16754775:
      volumeUp(&msg);
      break;
    case 16769055:
      volumeDown(&msg);
      break;
    case 16761405:
      select(&msg);
      break;
    case 16748655:
      ampMenu(&msg);
      break;
    case 16728765:
      mute(&msg);
      break;
      
  }
  for(int i=0; i<3; i++){
    irsend.sendSony((unsigned long)(&msg)[0], (int)(&msg)[1]);
    delay(10);
  }
}

void IREye::recieve(){
  if (_irrecv->decode(&_results)) {
    if(_results.decode_type == NEC){
      _sendSonyMsg(_results.value); 
      setup();
    }
    _irrecv->resume(); // Receive the next value
  }
}
