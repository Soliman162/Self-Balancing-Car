#ifndef PRIVATE_HPP
#define PRIVATE_HPP

/*************************************Macro Func**********************************/
#define SIGN(VALUE)   ( (VALUE>0) - (VALUE<0) )
#define exp_moving_avg(last_avg,new_reading,alpha)    ((alpha * new_reading ) + ((1.0 - alpha) * last_avg))
/*********************************************************************************/
/*******************************IMU_Addres_Config********************************/
#if AD0_PIN_VALUE == HIGH
  #define IMU_ADDRESS   0b1101001
#elif AD0_PIN_VALUE == LOW
  #define IMU_ADDRESS   0b1101000
#endif
/*******************************************************************************/

/*******************************ACC DIV_Factor Config********************************/
#if AFS_SEL == AFS_2g
    #define ACC_DIV_FACTOR    16384.0f
#elif AFS_SEL == AFS_4g
    #define ACC_DIV_FACTOR    8192.0f
#elif AFS_SEL == AFS_8g
    #define ACC_DIV_FACTOR    4096.0f
#elif AFS_SEL == AFS_16g
    #define ACC_DIV_FACTOR    2048.0f
#endif
/**************************************************************************************/

/*******************************Gero_Scope DIV_Factor Config********************************/
#if AFS_SEL == AFS_2g
    #define GERO_SCOPE_DIV_FACTOR    131.0f
#elif AFS_SEL == AFS_4g
    #define GERO_SCOPE_DIV_FACTOR    65.5f
#elif AFS_SEL == AFS_8g
    #define GERO_SCOPE_DIV_FACTOR    32.8f
#elif AFS_SEL == AFS_16g
    #define GERO_SCOPE_DIV_FACTOR    16.4f
#endif
/**************************************************************************************/

/****************************IMU_Reg_Values*************************************/
/*                           Reset_IMU                                         */
#define RESET_IMU   0b10000000
/*******************************************************************************/
#define FS_SEL_BIT   3
#define AFS_SEL_BIT  3
/****************************full scale range of the gyroscope outputs*******************************************/

typedef enum  
{
  FS_250 = 0,
  FS_500 ,
  FS_1000,
  FS_2000
}FS_r_Gero_Scope_OUT;

/****************************************************************************************************************/
typedef enum 
{
  AFS_2g = 0,
  AFS_4g,
  AFS_8g,
  AFS_16g
}AFS_r_ACC_OUT;
/********************************IMU_Registers_Addresses_Config***********************************************/
typedef enum 
{
  CONFIG = 0x1A ,
  GYRO_CONFIG = 0x1B ,
  ACCEL_CONFIG = 0x1C ,
  PWR_MGMT_1 = 0x6B ,

  ACCEL_X_H = 0x3B ,
  ACCEL_X_L,
  
  ACCEL_Y_H,
  ACCEL_Y_L,
  
  ACCEL_Z_H,
  ACCEL_Z_L,

  GYRO_X_H = 0x43,
  GYRO_X_L,
  
  GYRO_Y_H,
  GYRO_Y_L,
  
  GYRO_Z_H,
  GYRO_Z_L
  
}IMU_REGs_Addr;
/*************************************************************************************************************/

#endif
