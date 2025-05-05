#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#define ENA 11
#define IN1 12
#define IN2 13

#define ENB 6
#define IN3 7
#define IN4 8

void motor_init(void);
void forward(int motor1, int motor2);
void backward(int motor1, int moto2);
void stop(void);

#endif 
