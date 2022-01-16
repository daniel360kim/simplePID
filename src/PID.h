
#ifndef PID_H
#define PID_H

#include <math.h>

class PID {
public:

    double kp, ki, kd; //PID gains
    PID(double kp, double ki, double kd);
    void setOffset(double offset);
    void setRatio(double ratio);
    double updateSetpoint(double setpoint); //updates and returns setpoint
    double updatePID(double input, double dt);

private:
    double _p, _i, _d; //PID constants
    double sp;
    double pre_error;
    double offset;
    double ratio;
};

#endif
