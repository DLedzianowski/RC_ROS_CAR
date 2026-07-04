#include "control.h"
#include "motor.h"


#define Tp 0.02f

float Kp = 1.0f;
float Ki = 0.0f;

static float integral = 0;

int16_t control_update(int32_t delta) {
    int32_t measured_speed = delta;

    float error = get_target_speed() - measured_speed;

    integral += error * 0.02f;

    float u = Kp * error + Ki * integral;

    if (u > 100) u = 100;
    if (u < -100) u = -100;

    return (int16_t)u;
}