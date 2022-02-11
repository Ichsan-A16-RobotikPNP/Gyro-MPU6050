#include <I2Cdev.h>
#include <MPU6050.h>
#include <Wire.h>

MPU6050 gy_521;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int ACCX,ACCY;
int GYRX,GYRY,GYRZ,sensitif;

void setup(){
    Serial.begin(9600);
    Wire.begin();
    gy_521.initialize();
    sensitif=350;
}

void loop(){
    acc();
    gyro();
    delay(100);
    Serial.print("ax/ay/gx/gy/gz: \t");
    Serial.print(ACCX); Serial.print("\t");
    Serial.print(ACCY);Serial.print("\t");
    Serial.print(GYRX); Serial.print("\t");
    Serial.print(GYRY); Serial.print("\t");
    Serial.println(GYRZ);
}

void acc(){
    gy_521.getAcceleration(&ax, &ay, &az);
    ACCX = 57.295*atan((float)ay/ sqrt(pow((float)az,2)+pow((float)ax,2)));
    ACCY = 57.295*atan((float)-ax/ sqrt(pow((float)az,2)+pow((float)ay,2)));
}

void gyro(){
    gy_521.getRotation(&gx, &gy, &gz);
    GYRX = gx/sensitif;
    GYRY = gy/sensitif;
    GYRZ = gz/sensitif;
}
