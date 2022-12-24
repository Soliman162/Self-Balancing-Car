#ifndef APP_HPP
#define APP_HPP

/********************************************************Timer_Init_Value******************************************************************/

//TCNTn =  65535– (16x1010xTime in sec / Prescaler Value) .... n can be 0,1,2 for timer 0,1,2 ... maxvalue =(65535 for 16 bit,)
float timer_value = (65535 - ((16*pow(10, 6)*TIMER_DT)/256));

/*******************************************************************************************************************************************/

/******************************************Global_Var*****************************************************************/
//volatile int PID_OutPut = 0;
volatile uint8_t Motor_Speed = 0;
volatile double Current_Angle = 0.0;
volatile boolean Timer_Flag = true;

/**********************************************************************************************************************/
void Timer_voidInit(void);
void System_voidInit(void);
void Data_Display(void);




#endif
