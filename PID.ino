#include "Private_LIB.h"
#include "PID.h"

void Update_voidPID_Data(float Current_Measure)
{
  Error = DES_VALUE - Current_Measure;
    
  //Error_dot_unfilterd = (Error - Last_Error)/TIMER_DT;  //exp

  Error_dot_unfilterd = -(Current_Measure-Last_Value)/TIMER_DT;
  
  Error_dot = exp_moving_avg(Error_dot,Error_dot_unfilterd,0.1);
  
  Error_Sum += Error*TIMER_DT;
  
 // Last_Error = Error;
 
  Last_Value = Current_Measure;
  
  P_trem = KP_VALUE*Error;
  D_trem = KD_VALUE*Error_dot;
  I_trem = KI_VALUE*Error_Sum;

  if( (I_trem >= MAX_VALUE) || (I_trem <= MIN_VALUE) )
  {
    I_trem = MAX_VALUE*SIGN(I_trem);
  }

  PID_output = P_trem + D_trem + I_trem;
  
  if( (PID_output >= MAX_VALUE) || (PID_output <= MIN_VALUE) )
  {
    PID_output = MAX_VALUE*SIGN(PID_output);
  }
  
}
