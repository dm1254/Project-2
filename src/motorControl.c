#include "motorControl.h"


void init(MotorControl* mc, MotorPins *config, int motorCount){
	for(int i = 0; i < motorCount; i++){
		mc->pins[i] = config[i];

	}

}
