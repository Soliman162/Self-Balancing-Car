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

      /*Update IMU Data*/ 
      Update_voidIMU();
      if(PID_output >= 0)
      {
        Car_voidMove_CCW(Motor_Speed);
      }else
      {
        Car_voidMove_CW(Motor_Speed);
      }
      Data_Display();
}

  /*
      Update_voidIMU();

      Current_Angle = 0.98*(Current_Angle + Get_Gero_Angle_X_Y_Z(X) *TIMER_DT ) + 0.02*(Get_ACC_2D_Angle_X());

      Update_voidPID_Data(Current_Angle);

      if(PID_output<0)
      {
        Motor_Speed = PID_output + MAX_VALUE;
      }
      else
      {
        Motor_Speed = PID_output;
      }

  */
