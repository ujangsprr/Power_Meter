#include <Arduino.h>

#define slaveID1 101 //Alamat device iem2150
#define slaveID2 102 //Alamat device iem2150
#define slaveID3 103 //Alamat device iem2150

//Network details
const char apn[]  = "Internet";
const char user[] = "WAP";
const char pass[] = "WAP123";

// ====== MQTT ======
#define mqtt_server "202.154.61.158"
#define mqtt_port 1883
#define mqtt_user "bbtk"
#define mqtt_password "ebtbbtk@PJB"

char Tag1[30] = "PTN-PLTHK-VOLTAGE";
char Tag2[30] = "PTN-PLTHK-CURRENT";
char Tag3[30] = "PTN-PLTHK-POWRFTR";
char Tag4[30] = "PTN-PLTHK-FREQNCY";
char Tag5[30] = "PTN-PLTHK-ACTPOWR";
char Tag6[30] = "PTN-PLTHK-REAPOWR";
char Tag7[30] = "PTN-PLTHK-APPPOWR";
char Tag8[30] = "PTN-PLTHK-POWRCAL";

// ====== SD Card ======
const int pinSDCard = 53;
String filename = "data.txt";

float vAC1, cAC1, dAC1, acPow1, rp1, app1, freq1, pf1;
float vAC2, cAC2, dAC2, acPow2, rp2, app2, freq2, pf2;
float vAC3, cAC3, dAC3, acPow3, rp3, app3, freq3, pf3;

// ====== LCD ======
char vACBuff1[50];
char cACBuff1[50];
char acPBuff1[50];
char apPBuff1[50];
char pfBuff1[50];
char rPBuff1[50];
char freqBuff1[50];
char dACBuff1[50];

char vACBuff2[50];
char cACBuff2[50];
char acPBuff2[50];
char apPBuff2[50];
char pfBuff2[50];
char rPBuff2[50];
char freqBuff2[50];
char dACBuff2[50];

char vACBuff3[50];
char cACBuff3[50];
char acPBuff3[50];
char apPBuff3[50];
char pfBuff3[50];
char rPBuff3[50];
char freqBuff3[50];
char dACBuff3[50];

char databuff11[150];
char databuff12[150];
char databuff21[150];
char databuff22[150];
char databuff31[150];
char databuff32[150];

// New Case
//char databuff11[50];
//char databuff12[50];
//char databuff13[50];
//char databuff21[50];
//char databuff22[50];
//char databuff23[50];
//char databuff31[50];
//char databuff32[50];
//char databuff33[50];

char databuff1[80];
char databuff2[80];
char databuff3[80];
char databuff4[80];
char databuff5[80];
char databuff6[80];
char databuff7[80];
char databuff8[80];

// ====== Global Variable ======
int count = 0, countA = 0, countB = 0;
long currentTime, lastTime;
char msg[20];
int snr1, snr2, snr3;
bool conn, kirim;

void modbusRTU();
float int2float(unsigned int d1, unsigned int d2);
void showData();
void CreateChar2();
void publishData2();

//=============>>   Timing LCD  <<=================
int MenuChoice = 0;
unsigned long currentMillis;
unsigned long previousMillisLCD = 0;
unsigned long previousMillisSend = 0;
unsigned long previousMillisSD = 0;
unsigned long previousMillisCon = 0;
unsigned long previousMillisMqtt = 0;
const int IntervalLCD = 1000; //Send data setiap 3 detik sekali
const int IntervalMqtt = 800;
const int IntervalSend = 2000;
const int IntervalCon = 30000;
