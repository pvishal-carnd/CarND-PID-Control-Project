#include "PID.h"

using namespace std;

/*
 * TODO: Complete the PID class.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    cfilt = 0.15;

    this->efilt = 0;
    p_error = i_error = d_error = 0;
}

void PID::UpdateError(double cte) {

    // previous cte is already stored in p_error. We reuse it
    cte = cfilt*efilt + (1-cfilt)*cte;
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return -1*(Kp*p_error + Ki*i_error + Kd*d_error);
}

