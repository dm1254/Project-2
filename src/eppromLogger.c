#include "eepromLogger.h"

void init_EEPROM(){
	for(int i = 0; i < EEPROM.length(); i++){
		EEPROM.write(i,0);
	}

}

void log_GPS(long longitude, long latitude, usigned long timestamp){
	

}
