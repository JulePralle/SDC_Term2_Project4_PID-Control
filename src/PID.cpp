#include "PID.h"
#include <iostream>

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
  is_initialized = false;
}

void PID::UpdateError(double cte) {
  if(is_initialized == false){
    prev_cte = cte;
    cte_sum = 0;
    is_initialized = true;
  }
  double diff_cte = cte - prev_cte;
  prev_cte = cte;
  cte_sum += cte;

  p_error = cte;
  d_error = diff_cte;
  i_error = cte_sum;

}

double PID::TotalError() {
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}

