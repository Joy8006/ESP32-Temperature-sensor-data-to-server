/*
  SD card read/write
 
  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
        SS    = 5;
        MOSI  = 23;
        MISO  = 19;
        SCK   = 18;
 

 
*/
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
 
File myFile;
 
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 
 
  Serial.print("Initializing SD card...");
 
  if (!SD.begin(SS)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);
 
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
 
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
 
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}
 
void loop() {
  // nothing happens after setup
}