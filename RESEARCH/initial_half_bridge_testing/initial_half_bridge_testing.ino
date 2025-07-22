#include <SPI.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  PORTD |= 0b00000100;
  SPI.begin();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  uint16_t spiOutput1;
  uint16_t spiOutput2;
  delayMicroseconds(45);

  SPI.beginTransaction(SPISettings(5000000, MSBFIRST, SPI_MODE1));
  //digitalWrite(10, LOW);
  PORTD &= 0b11111011;
  spiOutput1 = SPI.transfer16(0b0000000110000100);
  PORTD |= 0b00000100;

  delayMicroseconds(44);

  PORTD &= 0b11111011;
  spiOutput2 = SPI.transfer16(0b0000000110000110);
  PORTD |= 0b00000100;
  SPI.endTransaction();

  //Serial.print("\n");
  //Serial.print(spiOutput2, BIN);
  //Serial.print("\n");
  //Serial.print("\n");
  //Serial.print(spiOutput1, BIN);
}
