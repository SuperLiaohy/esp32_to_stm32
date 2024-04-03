//
// Created by 24106 on 2024/3/27.
//

#ifndef ESP32_TO_STM32_PID_H
#define ESP32_TO_STM32_PID_H

float limit(float min,float input,float max);
float myabs(float input);

struct encoder{

    short speed;

};


class PID{
private:
    float p;
    float i;
    float d;

    int err;
    int err_least;
    int last_err;
    int previous_err;
    int sum_err;

    float target;
    float out;


    float a;//lv bo

public:
    PID(float mp,float mi,float md,float mtarget,float ma = 0);

    float Pval();
    float targetVal(void) const;
    float outVal(void) const;

    void Pchange(float val);
    void Ichange(float val);
    void Dchange(float val);
    void target_change(float val);

    void PID_relize(float input);
    void PID_relize_lvbo(int input_1,int input_2);
    void PID_turn(float input);
};


extern encoder encoder1;
extern encoder encoder2;


extern PID pid_1;
extern PID pid_2;
extern PID pid_3;




#endif //ESP32_TO_STM32_PID_H
