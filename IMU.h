#ifndef IMU_HPP
#define IMU_HPP

//A4 (SDA), A5 (SCL)
/***************************Axes_config********************************************/

typedef enum
{
  X = 0,
  Y,
  Z  
}AXES;
/***********************************************************************/

#define AD0_PIN_NUM     13

/***************************Config***************************************/
/*                    AD0 Voltage Level
 *  options:-
 *    - HIGH
 *    - LOW
*/
#define AD0_PIN_VALUE   HIGH

/***********************************************************************/

/***************************Config***************************************/
/*             full scale range of the gyroscope outputs config
 *  options:-
 *    - FS_250
 *    - FS_500 
 *    - FS_1000
 *    - FS_2000
*/
#define FS_SEL   FS_250

/***********************************************************************/

/***************************Config***************************************/
/*             full scale range of the accelerometer outputs
 *  options:-
 *    - AFS_2g
 *    - AFS_4g
 *    - AFS_8g
 *    - AFS_16g
*/
#define AFS_SEL   AFS_2g

/***********************************************************************/



  
    void IMU_voidInit(void);
    
    void Update_voidIMU(void);
    
    float Get_ACC_X_Y_Z(AXES Copy_Axe);
    float Get_GERO_X_Y_Z(AXES Copy_Axe);
    
    float Get_Gero_Angle_X_Y_Z(AXES Copy_Axe);
    
    float Get_ACC_3D_Angle_X(void);
    float Get_ACC_3D_Angle_Y(void);
    
    float Get_ACC_2D_Angle_X(void);
    float Get_ACC_2D_Angle_Y(void);

  // currentAngle = 0.9934*(prevAngle + gyroAngle) + 0.0066*(accAngle);
    
/**************************************************************************************************************************/

#endif
