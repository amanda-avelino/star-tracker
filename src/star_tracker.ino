#include <Wire.h>
#include <DS3231.h>
#include <Stepper.h>

// Define os pinos para os motores de passo
const int stepsPerRevolution = 200;

// Motor RA
const int motorPinRA1 = 8;
const int motorPinRA2 = 9;
const int motorPinRA3 = 10;
const int motorPinRA4 = 11;

// Motor Dec
const int motorPinDec1 = 4;
const int motorPinDec2 = 5;
const int motorPinDec3 = 6;
const int motorPinDec4 = 7;

// Cria os objetos para os motores de passo
Stepper motorRA(
  stepsPerRevolution,
  motorPinRA1,
  motorPinRA3,
  motorPinRA2,
  motorPinRA4
);

Stepper motorDec(
  stepsPerRevolution,
  motorPinDec1,
  motorPinDec3,
  motorPinDec2,
  motorPinDec4
);

// Inicialização do RTC
DS3231 rtc;

float observer_longitude = -47.929;
float star_RA = 0.0;
float star_Dec = 0.0;

// Função para calcular a hora sideral
float calculateSiderealTime(
  int hours,
  int minutes,
  int seconds,
  float longitude
) {
  float JD = 2451545.0
           + (hours / 24.0)
           + (minutes / 1440.0)
           + (seconds / 86400.0);

  float SID = 280.46061837
            + 360.98564736629 * (JD - 2451545.0)
            + longitude;

  return SID;
}

// Função para calcular as coordenadas da estrela
void calculateStarCoordinates(
  float RA_hours,
  float Dec_deg,
  float siderealTime
) {
  star_RA = RA_hours * 15.0;
  star_Dec = Dec_deg;
}

// Função para mover cada motor separadamente
void moveToStar() {

  const int stepsPerDegreeRA = 15;
  const int stepsPerDegreeDec = 15;

  int stepsRA = star_RA * stepsPerDegreeRA;
  int stepsDec = star_Dec * stepsPerDegreeDec;

  motorRA.setSpeed(60);
  motorDec.setSpeed(60);

  Serial.print("Movendo motor RA: ");
  Serial.println(stepsRA);

  motorRA.step(stepsRA);

  delay(500);

  Serial.print("Movendo motor Dec: ");
  Serial.println(stepsDec);

  motorDec.step(stepsDec);
}

// Função de teste para os motores
void testMotors() {

  Serial.println("Testando motor RA...");

  motorRA.setSpeed(100);
  motorRA.step(50);

  delay(1000);

  Serial.println("Testando motor Dec...");

  motorDec.setSpeed(100);
  motorDec.step(50);

  delay(1000);
}

void setup() {

  Serial.begin(9600);

  // Teste inicial dos motores
  testMotors();

  // Define as coordenadas da estrela
  // RA em horas e Dec em graus
  float star_RA_hours = 5 + (55 / 60.0);
  float star_Dec_deg = 7.407;

  bool h12;
  bool PM_time;

  int hours = rtc.getHour(h12, PM_time);
  int minutes = rtc.getMinute();
  int seconds = rtc.getSecond();

  float siderealTime =
    calculateSiderealTime(
      hours,
      minutes,
      seconds,
      observer_longitude
    );

  calculateStarCoordinates(
    star_RA_hours,
    star_Dec_deg,
    siderealTime
  );

  Serial.print("Coordenadas da Estrela: ");
  Serial.print("RA: ");
  Serial.print(star_RA);
  Serial.print(" graus, Dec: ");
  Serial.println(star_Dec);

  moveToStar();
}

void loop() {

  delay(5000);

  bool h12;
  bool PM_time;

  int hours = rtc.getHour(h12, PM_time);
  int minutes = rtc.getMinute();
  int seconds = rtc.getSecond();

  float siderealTime =
    calculateSiderealTime(
      hours,
      minutes,
      seconds,
      observer_longitude
    );

  calculateStarCoordinates(
    6 + (46 / 60.0),
    -16.7161,
    siderealTime
  );

  moveToStar();
}
