#include "Private_LIB.h"
#include "DC_Motor.h"
#include "IMU.h"
#include "PID.h"
#include "APP.h"

void setup() 
{
  System_voidInit();
}

void loop() 
{    
      if(PID_output >= 0)
      {
        Car_voidMove_CCW(Motor_Speed);
      }else
      {
        Car_voidMove_CW(Motor_Speed);
      }
      Data_Display();
}
