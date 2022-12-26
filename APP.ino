#include "Private_LIB.h"
#include "DC_Motor.h"
#include "PID.h"
#include "IMU.h"
#include "APP.h"

//  currentAngle = 0.9934*(prevAngle + gyroAngle) + 0.0066*(accAngle);

ISR(TIMER1_OVF_vect)                    // interrupt service routine for overflow
{   
      /*preload Timer*/
      TCNT1 = timer_value;
      /*Get Current Angle With Compelementry Filter*/
      Current_Angle = 0.98*(Current_Angle + Get_Gero_Angle_X_Y_Z(X) *TIMER_DT ) + 0.02*(Get_ACC_2D_Angle_X());
      /*Update PID Data*/
      Update_voidPID_Data(Current_Angle);
      /*modify motor speed to be > 0*/
      if(PID_output<0)
      {
        Motor_Speed = PID_output + MAX_VALUE;
      }
      else
      {
        Motor_Speed = PID_output;
      }
}

void Timer_voidInit(void)
{
  // timer interrupt setup
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = timer_value;                        // preload timer
  //TCCR1B |= (1 << CS10)|(1 << CS12);    // 1024 prescaler 
  TCCR1B |= (1 << CS12);                 // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);               // enable timer overflow interrupt ISR
  interrupts();                         // enable all interrupts
}

void System_voidInit(void)
{
  Serial.begin(9600);
  IMU_voidInit();
  Car_voidInit();
  Timer_voidInit();
}

void Data_Display(void)
{
  Serial.println("/**************************************************************************************/");
  Serial.print("Current_Angle = ");
  Serial.println(Current_Angle);

  Serial.print("PID_OutPut = ");
  Serial.println(PID_output);


 Serial.println("/*************Gero_Data******************/");

  Serial.print("Get_Gero_Angle_X_Y_Z(X) = ");
  Serial.println(Get_Gero_Angle_X_Y_Z(X));
//
  Serial.print("Get_Gero_Angle_X_Y_Z(Y) = ");
  Serial.println(Get_Gero_Angle_X_Y_Z(Y));
//
  Serial.print("Get_Gero_Angle_X_Y_Z(Z = ");
  Serial.println(Get_Gero_Angle_X_Y_Z(Z));
//
 Serial.println("/*************ACC_Data******************/");
  Serial.print("Get_ACC_2D_Angle_X = ");
  Serial.println(Get_ACC_2D_Angle_X() );
//
  Serial.print("ACC_Z = ");
  Serial.println(Get_ACC_X_Y_Z(Z));
//
  Serial.print("ACC_Y = ");
  Serial.println( Get_ACC_X_Y_Z(Y) );
//
  Serial.print("ACC_X = ");
  Serial.println( Get_ACC_X_Y_Z(X) );

  Serial.println("/**************************************************************************************/");
}
