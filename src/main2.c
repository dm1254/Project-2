#include <Arduino.h>
#include <EEPROM.h>

#define FILENAME "GPSData.kml"

typedef struct GPSData{
  byte hour;
  byte minute;
  byte seconds;
  float Longitude;
  float Latitude;
}gpsDataEntry;

int sizeOfData = sizeof(GPSData);
int address = 4;

void setup() {
  int entry_count = 0;
  EEPROM.get(0,entry_count);
  gpsDataEntry entry;
  for(int i = 0; i < entry_count; i++){
    EEPROM.get(address, entry);
    int localHour = (int(entry.Hour) + 24 - 7 ) % 24;
    

  }


}

int main(){
  FILE *data 

  data = fopen(FILENAME,"w");
  if (data == NULL){
    return 1;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
}

