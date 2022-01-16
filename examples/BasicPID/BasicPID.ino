
#include "PID.h"

PID pid(0.3, 0.1, 0.1);

unsigned long previousTime;

void setup(){
  Serial.begin(115200);

  pid.setOffset(5);
  pid.setRatio(1);

  previousTime = micros();
}

void loop(){
  unsigned long micros = micros();
  double dt = (micros - previousTime) / 1000000.0;
  previousTime = micros;

  double output = pid.updatePID(random(0,30), dt);

  Serial.print("Output is: ");
  Serial.println(output , 5);


}
