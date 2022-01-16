#include "PID.h"

PID::PID(double kp, double ki, double kd) { //setting the PID gains
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

void PID::setOffset(double offset){ //offsets results. useful for shifting values
    this->offset = offset;
}

void PID::setRatio(double ratio){ //value multiplier (gear ratio etc.)
    this->ratio = ratio;
}

double PID::updateSetpoint(double setpoint){
    this->sp = setpoint;
    return sp;
}
double PID::updatePID(double input, double dt){
    double error = input - sp;

    _p = kp * error; //Proportion
    _i = ki * (_i + error * dt); //Integral
    _d = kd * ((error - pre_error) / dt);
    pre_error = error;
    return ratio * (_p + _i + _d) + offset;
}

