#include "Wire.h"
#include "I2C.h"

#define MPU9250_IMU_ADDRESS 0x68
#define MPU9250_MAG_ADDRESS 0x0C

#define GYRO_FULL_SCALE_250_DPS  0x00
#define GYRO_FULL_SCALE_500_DPS  0x08
#define GYRO_FULL_SCALE_1000_DPS 0x10
#define GYRO_FULL_SCALE_2000_DPS 0x18

#define ACC_FULL_SCALE_2G  0x00
#define ACC_FULL_SCALE_4G  0x08
#define ACC_FULL_SCALE_8G  0x10
#define ACC_FULL_SCALE_16G 0x18

#define INTERVAL_MS_PRINT 1000

#define G 9.80665

struct gyroscope_raw {
  int16_t x, y, z;
} gyroscope;

struct accelerometer_raw {  
  int16_t x, y, z;
} accelerometer;

struct magnetometer_raw {
  int16_t x, y, z;

  struct {
    int8_t x, y, z;
  } adjustment;
} magnetometer;

unsigned long lastPrintMillis = 0;

void setMagnetometerAdjustmentValues()
{
  uint8_t buff[3];

  I2CwriteByte(MPU9250_MAG_ADDRESS, 0x0A, 0x1F);

  delay(1000);

  I2Cread(MPU9250_MAG_ADDRESS, 0x10, 3, buff);

  magnetometer.adjustment.x = buff[0];
  magnetometer.adjustment.y = buff[1];
  magnetometer.adjustment.z = buff[2];

  I2CwriteByte(MPU9250_MAG_ADDRESS, 0x0A, 0x10);
}

bool isMagnetometerReady()
{
  uint8_t isReady;

  I2Cread(MPU9250_MAG_ADDRESS, 0x02, 1, &isReady);

  return isReady & 0x01;
}

void readRawMagnetometer()
{
  uint8_t buff[7];

  I2Cread(MPU9250_MAG_ADDRESS, 0x03, 7, buff);

  magnetometer.x = (buff[1] << 8 | buff[0]);
  magnetometer.y = (buff[3] << 8 | buff[2]);
  magnetometer.z = (buff[5] << 8 | buff[4]);
}

bool isImuReady()
{
  uint8_t isReady;

  I2Cread(MPU9250_IMU_ADDRESS, 58, 1,
}  










