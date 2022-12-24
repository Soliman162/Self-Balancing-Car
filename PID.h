#ifndef PID_HPP
#define PID_HPP


/********************Delta_t**************************/
#define TIMER_DT  0.2
/*****************************************************/
#define MAX_VALUE   255
#define MIN_VALUE   -255


/****************************PID_Config***************************************/
#define KP_VALUE  40
#define KD_VALUE  0.05
#define KI_VALUE  40

#define DES_VALUE  -2.5
/*****************************************************************************/

/***********************************PID_common_var************************************************/
volatile float Error = 0 ;
volatile float Error_Sum = 0 ;
volatile float Error_dot = 0 ;
volatile float Error_dot_unfilterd = 0 ;

volatile float I_trem = 0 ;
volatile float P_trem = 0 ;
volatile float D_trem = 0 ;

volatile float Last_Value = 0 ;
volatile double PID_output = 0 ;
/************************************************************************************************/
void Update_voidPID_Data(float Current_Measure);



#endif
