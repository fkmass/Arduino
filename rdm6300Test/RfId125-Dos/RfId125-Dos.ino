 /*
  RDM6300-125KHz-RFID

  based on www.mschoeffler.de Arduino Examples
*/

#include <SoftwareSerial.h>

const int BUFFER_SIZE = 14; // RFID DATA FRAME FORMAT: 1byte head (value: 2), 10byte data (2byte version + 8byte tag), 2byte checksum, 1byte tail (value: 3)
const int DATA_SIZE = 10; // 10byte data (2byte version + 8byte tag)
const int DATA_VERSION_SIZE = 2; // 2byte version (actual meaning of these two bytes may vary)
const int DATA_TAG_SIZE = 8; // 8byte tag
const int CHECKSUM_SIZE = 2; // 2byte checksum

SoftwareSerial ssrfid = SoftwareSerial(6,8); 

uint8_t buffer[BUFFER_SIZE]; // used to store an incoming data frame 
int buffer_index = 0;
unsigned tag;
long tagAnterior = 1;


// var
int led = 13;
byte data_1 = 0x00;
byte data_2 = 0x00;
byte data_3 = 0x00;
byte data_4 = 0x00;
byte data_5 = 0x00;
int val = 0;

void setup(){
  // Start serial port 19200 bps
  Serial.begin(9600); 
  ssrfid.begin(9600);
  
  pinMode(led, OUTPUT);
  delay(500);
    
  // Setting Auto Read Mode - EM4102 Decoded Mode - No password
  // command: FF 01 09 87 01 03 02 00 10 20 30 40 37
  ssrfid.write(0xFF);
  ssrfid.write(0x01);
  ssrfid.write(0x09);
  ssrfid.write(0x87);
  ssrfid.write(0x01);
  ssrfid.write(0x03);
  ssrfid.write(0x02);
  ssrfid.write((byte)0x00);
  ssrfid.write(0x10);
  ssrfid.write(0x20);
  ssrfid.write(0x30);
  ssrfid.write(0x40);
  ssrfid.write(0x37);
  
  delay(500);
  
  while (ssrfid.available() >0)
  {
  ssrfid.read();
  }
  
  Serial.println();
  Serial.println("RFID module started in Auto Read Mode");
  Serial.println("Waiting card");
  ssrfid.listen();
}


void loop() {
  val = ssrfid.read();
  while (val != 0xff){
    Serial.print(".");
    val = ssrfid.read();
    delay(1000);
  }
  Serial.println("card");

}
