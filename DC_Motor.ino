#include "DC_Motor.h"

void Car_voidInit(void)
{
  pinMode(RIGHT_MOTOR_CW_PIN,OUTPUT);
  pinMode(RIGHT_MOTOR_CCW_PIN,OUTPUT );
  pinMode(RIGHT_MOTOR_SPEED_PIN, OUTPUT);

  pinMode(LEFT_MOTOR_CW_PIN,OUTPUT);
  pinMode(LEFT_MOTOR_CCW_PIN,OUTPUT );
  pinMode(LEFT_MOTOR_SPEED_PIN, OUTPUT);

  digitalWrite(RIGHT_MOTOR_CW_PIN, LOW);
  digitalWrite(RIGHT_MOTOR_CCW_PIN, LOW);
  analogWrite(RIGHT_MOTOR_SPEED_PIN, 0);

  digitalWrite(LEFT_MOTOR_CW_PIN, LOW);
  digitalWrite(LEFT_MOTOR_CCW_PIN, LOW);
  analogWrite(LEFT_MOTOR_SPEED_PIN, 0);
  
}
void Car_voidMove_CW(uint8_t Copy_speed)
{
  digitalWrite(RIGHT_MOTOR_CW_PIN, HIGH);
  digitalWrite(RIGHT_MOTOR_CCW_PIN, LOW);
  analogWrite(RIGHT_MOTOR_SPEED_PIN, Copy_speed);

  digitalWrite(LEFT_MOTOR_CW_PIN, HIGH);
  digitalWrite(LEFT_MOTOR_CCW_PIN, LOW);
  analogWrite(LEFT_MOTOR_SPEED_PIN, Copy_speed);
}


void Car_voidMove_CCW(uint8_t Copy_speed)
{
  digitalWrite(RIGHT_MOTOR_CW_PIN, LOW);
  digitalWrite(RIGHT_MOTOR_CCW_PIN, HIGH);
  analogWrite(RIGHT_MOTOR_SPEED_PIN, Copy_speed);

  digitalWrite(LEFT_MOTOR_CW_PIN, LOW);
  digitalWrite(LEFT_MOTOR_CCW_PIN, HIGH);
  analogWrite(LEFT_MOTOR_SPEED_PIN, Copy_speed);
}

void Car_voidStop(void)
{
  digitalWrite(RIGHT_MOTOR_CW_PIN, LOW);
  digitalWrite(RIGHT_MOTOR_CCW_PIN, LOW);
  analogWrite(RIGHT_MOTOR_SPEED_PIN, 0);

  digitalWrite(LEFT_MOTOR_CW_PIN, LOW);
  digitalWrite(LEFT_MOTOR_CCW_PIN, LOW);
  analogWrite(LEFT_MOTOR_SPEED_PIN, 0);
}
