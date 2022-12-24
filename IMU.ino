#include <Wire.h>
#include "Private_LIB.h"
#include "IMU.h"

/********************************************IMU common Var Config*************************************************************/
    volatile float ACC_X_Y_Z[3] = {0.0};
    volatile float GERO_X_Y_Z[3] = {0.0};
    volatile float Gero_Angle_X_Y_Z[3] = {0.0};
    
    volatile float ACC_Angle_X_Y[2] = {0.0};
    
    uint32_t current_Time = 0;
    uint32_t previous_Time = 0;
    volatile float dt_Gero = 0;
/*******************************************************************************************************************************/   



static inline void Uodate_voidAccelerometer_Data(void);  
static inline void Uodate_voidGero_Scope_Data(void);  
static inline void Write_voidData_To_REG(IMU_REGs_Addr Copy_enum_Reg, uint8_t Copy_u8Data);

static inline void Write_voidData_To_REG(IMU_REGs_Addr Copy_enum_Reg, uint8_t Copy_u8Data)
{
  /*Send slave address*/
  Wire.beginTransmission(IMU_ADDRESS);
  /*select register*/
  Wire.write(Copy_enum_Reg);
  /*Write Data*/
  Wire.write(Copy_u8Data);
  /*send stop bit*/
  Wire.endTransmission(true);
}
/*************************************************************************************************************************************/

static inline void Uodate_voidAccelerometer_Data(void)
{
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(ACCEL_X_H);
  Wire.endTransmission(false);
  Wire.requestFrom(IMU_ADDRESS, 6, true);

  ACC_X_Y_Z[X] = ((Wire.read()<<8) | Wire.read()) / static_cast<float>(ACC_DIV_FACTOR);
  ACC_X_Y_Z[Y] = ((Wire.read()<<8) | Wire.read()) / static_cast<float>(ACC_DIV_FACTOR);
  ACC_X_Y_Z[Z] = ((Wire.read()<<8) | Wire.read()) / static_cast<float>(ACC_DIV_FACTOR);

  Wire.endTransmission(true);
}
/*************************************************************************************************************************************/

static inline void Uodate_voidGero_Scope_Data(void)
{
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(GYRO_X_H);
  Wire.endTransmission(false);
  Wire.requestFrom(IMU_ADDRESS, 6, true);

  GERO_X_Y_Z[X] = (((Wire.read()<<8) | Wire.read()) / static_cast<float>(GERO_SCOPE_DIV_FACTOR)) ;
  GERO_X_Y_Z[Y] = (((Wire.read()<<8) | Wire.read()) / static_cast<float>(GERO_SCOPE_DIV_FACTOR)) ;
  GERO_X_Y_Z[Z] = (((Wire.read()<<8) | Wire.read()) / static_cast<float>(GERO_SCOPE_DIV_FACTOR)) ;

  Wire.endTransmission(true);
}
/*************************************************************************************************************************************/

void IMU_voidInit(void)
{
    /*SET AD0 Pin as output*/
  pinMode(AD0_PIN_NUM, OUTPUT);
  /*SET AD0 Voltage Level*/
  digitalWrite(AD0_PIN_NUM, AD0_PIN_VALUE);
  /*init I2C*/
  Wire.begin();
  /*Reset IMU*/
  Write_voidData_To_REG(PWR_MGMT_1, RESET_IMU);
  /*init GeroScope*/
  Write_voidData_To_REG(GYRO_CONFIG,static_cast<uint8_t>(FS_SEL<<FS_SEL_BIT));
  /*init Acc*/
  Write_voidData_To_REG(ACCEL_CONFIG,static_cast<uint8_t>(AFS_SEL<<AFS_SEL_BIT));
}

void Update_voidIMU(void)
{
  Uodate_voidAccelerometer_Data();
  Uodate_voidGero_Scope_Data();
}
/*************************************************************************************************************************************/

float Get_Gero_Angle_X_Y_Z(AXES Copy_Axe)
{
  /*save current time*/
  current_Time = millis();
  
  /*calculate dt*/
  dt_Gero = (current_Time-previous_Time) / 1000;
  
  /*calculate angle*/
  Gero_Angle_X_Y_Z[Copy_Axe] += GERO_X_Y_Z[Copy_Axe]*dt_Gero;
   
  /*save previos time*/
  previous_Time = current_Time;
  
  /*return angle*/
  return Gero_Angle_X_Y_Z[Copy_Axe];
}
/*************************************************************************************************************************************/

float Get_ACC_3D_Angle_X(void)
{
  /*Calculate Rotaion About X*/
  ACC_Angle_X_Y[X] = (atan2(ACC_X_Y_Z[Y], sqrt( pow(ACC_X_Y_Z[X],2) + pow(ACC_X_Y_Z[Z],2) ) ) * (180/PI) ); ;
  
  return ACC_Angle_X_Y[X];
}
/*************************************************************************************************************************************/
float Get_ACC_3D_Angle_Y(void)
{
  /*Calculate Rotaion About Y*/
  ACC_Angle_X_Y[Y] = -(atan2(ACC_X_Y_Z[X], sqrt( pow(ACC_X_Y_Z[Y],2) + pow(ACC_X_Y_Z[Z],2) ) ) * (180/PI) );
  
  return ACC_Angle_X_Y[Y];
}
/*************************************************************************************************************************************/
float Get_ACC_2D_Angle_X(void)
{
    /*Calculate Rotaion About X*/
  ACC_Angle_X_Y[X] = atan2(ACC_X_Y_Z[Y],ACC_X_Y_Z[Z])  * (180/PI);
  
  return ACC_Angle_X_Y[X];
}
/*************************************************************************************************************************************/

float Get_ACC_2D_Angle_Y(void)
{
    /*Calculate Rotaion About Y*/
  ACC_Angle_X_Y[Y] = atan2(ACC_X_Y_Z[X],ACC_X_Y_Z[Z])  * (180/PI) ;
  
  return ACC_Angle_X_Y[Y];
}
/*************************************************************************************************************************************/

float Get_ACC_X_Y_Z(AXES Copy_Axe)
{
  return ACC_X_Y_Z[Copy_Axe];
}
/*************************************************************************************************************************************/ 
float Get_GERO_X_Y_Z(AXES Copy_Axe)
{
  return GERO_X_Y_Z[Copy_Axe];
}
