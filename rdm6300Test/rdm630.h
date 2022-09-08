#ifndef RDM630_H
#define RDM630_H

#include "Arduino.h"
#include "SoftwareSerial.h"

const unsigned long RDM630_READ_WAIT_MS = 1000;

class RDM6300
{
public:
  RDM6300(byte yPinRx, byte yPinTx);
  RDM6300(byte yPinRx, byte yPinTx, unsigned long readWaitMs);
  void begin();
  void listen();
  String getTagId();
  static String toHexString(byte *data, size_t length);
  int available();  // FKD
  void getData(char * data, int* dataLength); // FKD

private:
  typedef enum
  {
    WAITING_FOR_STX,
    READING_DATA,
    DATA_VALID
  } state;

  static const int STX = 2;
  static const int ETX = 3;

  byte asciiCharToNum(byte data);
  state dataParser(state s, byte c);
  void reset();

  SoftwareSerial _rfid;
  state _state;
  int _iNibbleCtr;
  byte _data[6];
  unsigned long _readWaitMs;
};

#endif // RDM630_H
