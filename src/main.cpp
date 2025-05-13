#include <Arduino.h>
#include <stdio.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20,4);
#define FILENAME "GPSData.kml"

typedef struct GPSData{
  byte hour;
  byte minute;
  byte seconds;
  float Longitude;
  float Latitude;
}gpsDataEntry;

int sizeOfData = sizeof(gpsDataEntry);
int address = 4;

float **gpsCoords;
int entry_count = 0;
void setup() {
	lcd.init();
	lcd.backlight();

	EEPROM.get(0,entry_count);
	gpsCoords = new float*[entry_count];
	gpsDataEntry entry;
	for(int i = 0; i < entry_count; i++){
		gpsCoords[i] = new float[2];
		EEPROM.get(address, entry);
		int localHour = (int(entry.hour) + 24 - 7 ) % 24;
		lcd.print("Entry #");
		lcd.print(entry_count);
		lcd.setCursor(0,1);
		lcd.print("time:");
		if(entry.hour < 10) lcd.print("0");
		lcd.print(localHour);
		lcd.print(":");
		if(entry.minute < 10) lcd.print("0");
		lcd.print(":");
		if(entry.seconds < 10) lcd.print("0");
		lcd.print(entry.seconds);

		lcd.setCursor(0,2);
		lcd.print("Long:");
		lcd.print(entry.Longitude);
		gpsCoords[i][0] = entry.Longitude;
		lcd.setCursor(0,3);
		lcd.print("Lat:");
		lcd.print(entry.Latitude);
		gpsCoords[i][1] = entry.Latitude;

		address += sizeOfData;


	  }


}


int main(){
	FILE *data; 

	data = fopen(FILENAME,"w");
	if (data == NULL){
		return 1;
	}
	fprintf(data, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	fprintf(data,"<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n");
	fprintf(data,"	<Document>\n");
	fprintf(data,"		<name>GpsPath</name>\n");
	fprintf(data,"		<Placemark>\n");
	fprintf(data,"			<name>Start Point</name>\n");
	fprintf(data,"			<Point>\n");
	fprintf(data,"				<coordinates> %.6f,%.6f\n",gpsCoords[0][0], gpsCoords[0][1]);
	fprintf(data,"			</Point>\n");
	fprintf(data,"		</Placemark>\n");
	fprintf(data,"		<Placemark>\n");
	fprintf(data,"			<name>Path</name>\n");
	fprintf(data,"			<LineString>\n");
	fprintf(data,"				<coordinates>\n");
	
	for(int i = 1; i < entry_count;i++){
	fprintf(data,"\t\t\t\t\t%.6f,%.6f\n", gpsCoords[i][0], gpsCoords[i][1]);
	}
	fprintf(data,"				</coordinates>\n");
	fprintf(data,"			</LineString>\n");
	fprintf(data,"		</Placemark>\n");
	fprintf(data,"	</Document>\n");
	fprintf(data,"</kml>\n");
	fclose(data);
	

}

void loop() {
  // put your main code here, to run repeatedly:
}

