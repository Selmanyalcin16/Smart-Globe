// Kurenin arduino kodu, sadece gyro kismi

//Kutuphaneleri dahil et
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SPI.h>
#include <CapacitiveSensor.h>
#include <RH_NRF24.h>

//Sensoru Tanimla
Adafruit_MPU6050 mpu;

//nrf24'u tanimla
RH_NRF24 nrf24(8, 7);

//Kapasitif Algilama Hassasiyet Ayari
int threshold = 45;

struct data {
  byte country;
  byte pos;
};

data data_send = {0, 0};

CapacitiveSensor   cs_4_0 = CapacitiveSensor(4, 0);
CapacitiveSensor   cs_4_1 = CapacitiveSensor(4, 1);
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4, 5);
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4, 6);
CapacitiveSensor   cs_4_9 = CapacitiveSensor(4, 9);
CapacitiveSensor   cs_4_10 = CapacitiveSensor(4, 10);
CapacitiveSensor   cs_4_11 = CapacitiveSensor(4, 11);
CapacitiveSensor   cs_4_12 = CapacitiveSensor(4, 12);
CapacitiveSensor   cs_4_13 = CapacitiveSensor(4, 13);
CapacitiveSensor   cs_4_14 = CapacitiveSensor(4, 14);
CapacitiveSensor   cs_4_15 = CapacitiveSensor(4, 15);
CapacitiveSensor   cs_4_16 = CapacitiveSensor(4, 16);
CapacitiveSensor   cs_4_17 = CapacitiveSensor(4, 17);
CapacitiveSensor   cs_4_18 = CapacitiveSensor(4, 18);
CapacitiveSensor   cs_4_19 = CapacitiveSensor(4, 19);

void setup() {
  Serial.begin(9600);


  //Jiroskop ayarlari
  mpu.begin();
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  //nrf24
  if (!nrf24.init())
    Serial.println("init failed");
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1))
    Serial.println("setChannel failed");
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    Serial.println("setRF failed");

  delay(100);
}

  byte globe_position(float radian){
    float degree=(radian*4068)71;
    return(map(degree, 0, 360, 0,15));
  }

  void updateCapacitiveSensors() {
    long key1 =  cs_4_0.capacitiveSensor(30);
    long key2 =  cs_4_1.capacitiveSensor(30);
    long key3 =  cs_4_5.capacitiveSensor(30);
    long key4 =  cs_4_6.capacitiveSensor(30);
    long key5 =  cs_4_9.capacitiveSensor(30);
    long key6 =  cs_4_10.capacitiveSensor(30);
    long key7 =  cs_4_11.capacitiveSensor(30);
    long key8 =  cs_4_12.capacitiveSensor(30);
    long key9 =  cs_4_13.capacitiveSensor(30);
    long key10 =  cs_4_14.capacitiveSensor(30);
    long key11 =  cs_4_15.capacitiveSensor(30);
    long key12 =  cs_4_16.capacitiveSensor(30);
    long key13 =  cs_4_17.capacitiveSensor(30);
    long key14 =  cs_4_18.capacitiveSensor(30);
    long key15 =  cs_4_19.capacitiveSensor(30);

    if (key1 > threshold) {
      data_send.country = 1;
    }
    else if (key2 > threshold) {
      data_send.country = 2;
    }
    else if (key3 > threshold) {
      data_send.country = 3;
    }
    else if (key4 > threshold) {
      data_send.country = 4;
    }
    else if (key5 > threshold) {
      data_send.country = 5;
    }
    else if (key6 > threshold) {
      data_send.country = 6;
    }
    else if (key7 > threshold) {
      data_send.country = 7;
    }
    else if (key8 > threshold) {
      data_send.country = 8;
    }
    else if (key9 > threshold) {
      data_send.country = 9;
    }
    else if (key10 > threshold) {
      data_send.country = 10;
    }
    else if (key11 > threshold) {
      data_send.country = 11;
    }
    else if (key12 > threshold) {
      data_send.country = 12;
    }
    else if (key13 > threshold) {
      data_send.country = 13;
    }
    else if (key14 > threshold) {
      data_send.country = 14;
    }
    else if (key15 > threshold) {
      data_send.country = 15;
    }
  }

  void loop() {

  //Sensor okumalarini al
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  updateCapacitiveSensors();

  //Z ekseninin hangi bolgede(0-15) oldugu degerini dondurur,her bolge 24 derece
  //globe_position(g.gyro.z)

  if (nrf24.available())
  {
//globe_position(g.gyro.z)
    delay(50);
  }

  }  
