#ifndef EPPROM_LOGGER_H
#define EPPROM_LOGGER_H

#include <EEPROM.h>

#define START_ADD 0

typedef struct{
	long Longitude;
	long latitude;
	unsigned long timestamp;
}gpsDataEntry;
void init_EEPROM();
void log_GPS(long Longitude, log latitude, unsigned long timestamp);
void read_GPS(int index, gpsDataEntry* out);

