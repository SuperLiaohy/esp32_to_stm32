//
// Created by 24106 on 2024/3/27.
//

#include "pid.h"


float myabs(float input){
    return input<0?-input:input;
}

encoder encoder1;
encoder encoder2;

float limit(float min,float input,float max){
    if (input<min)
        return min;
    if (max<input)
        return max;
    return input;
}

PID::PID(float mp,float mi,float md,float mtarget,float ma):p(mp),i(mi),d(md),target(mtarget),a(ma){
    err = 0;
    last_err = 0;
    previous_err = 0;
    sum_err = 0;
    out = 0;
};

void PID::Pchange(float val){
    p = val;
};
void PID::Ichange(float val){
    i = val;
};
void PID::Dchange(float val){
    d = val;
};
float PID::targetVal(void) const {
    return target;
}
float PID::Pval() {
    return p;
}
float PID::outVal(void) const {
    return out;
}
void PID::target_change(float val){
    target = val;
};

void PID::PID_relize(float input){
    err = target - input;
    sum_err += err;
    out = p * err + i * sum_err + d * (1 - a) * (err - last_err) + a * (last_err);
    last_err = err;
};

void PID::PID_relize_lvbo(int input_1,int input_2){
//    target = limit(-0,target,30);
    err_least = target - input_1 - input_2;
    err = err * 0.7 + err_least * 0.3;
    sum_err += err;
    limit(-10000,sum_err,10000);
    out = p * err + i * sum_err + d * (1 - a) * (err - last_err) + a * (last_err);
    last_err = err;
}

void PID::PID_turn(float input) {
    err = target - input;
    out = p * err;
}

PID pid_1(0,0,0,0,0);
PID pid_2(0,0,0,0,0);
PID pid_3(0,0,0,0,0);