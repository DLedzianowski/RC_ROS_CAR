// motor.h
#pragma once

#include "main.h"

uint8_t get_target_speed(void);
uint16_t get_target_angle(void);
void set_target_speed(uint8_t val);
void set_target_angle(uint16_t val);

void motor_set(void);
void servo_set(void);