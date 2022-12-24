#ifndef DC_MOTOR_HPP
#define DC_MOTOR_HPP

/*******************************Motor_PINOUT_Conig***********************************/
#define RIGHT_MOTOR_CW_PIN  3
#define RIGHT_MOTOR_CCW_PIN 12

#define LEFT_MOTOR_CW_PIN   9
#define LEFT_MOTOR_CCW_PIN  8

#define RIGHT_MOTOR_SPEED_PIN   11
#define LEFT_MOTOR_SPEED_PIN    10

/*****************************************************************************/


void Car_voidInit(void);
void Car_voidMove_CW(uint8_t Copy_speed);
void Car_voidMove_CCW(uint8_t Copy_speed);

void Car_voidStop(void);




#endif
