#include "motor.h"
#include "main.h"
#include "stm32f103xb.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc_ex.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"

#define DIR_STOP 0
#define DIR_FORWARD 1
#define DIR_BACKWARD 2

uint8_t target_speed = 100;   // 0-100-200
uint16_t target_angle = 1050; //750 1050 1350

uint8_t get_target_speed(void) {
    return target_speed;
}

uint16_t get_target_angle(void) {
    return target_angle;
}

void set_target_speed(uint8_t val) {
    target_speed = val;
}

void set_target_angle(uint16_t val) {
    target_angle = val;
}

void set_dir(uint8_t dir) {
    if (DIR_FORWARD || DIR_BACKWARD) {
        HAL_GPIO_WritePin(MOTOR_EN_B_GPIO_Port, MOTOR_EN_B_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(MOTOR_EN_F_GPIO_Port, MOTOR_EN_F_Pin, GPIO_PIN_SET);
    }
    else {
        HAL_GPIO_WritePin(MOTOR_EN_F_GPIO_Port, MOTOR_EN_F_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MOTOR_EN_B_GPIO_Port, MOTOR_EN_B_Pin, GPIO_PIN_RESET);
    }

}

void motor_set(void) {
    if (target_speed > 100 && target_speed <= 200) {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, (target_speed-100)*10);
        set_dir(DIR_FORWARD);
    }
    else if (target_speed < 100) {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, (100-target_speed)*10);
        set_dir(DIR_BACKWARD);
    } 
    else {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
        set_dir(DIR_STOP);
    }
}

void servo_set(void) {
    // int16_t value = steer + trim;
    // 500 0deg
    // 2500 180deg
    // TODO: ustawic  target_angle i w MX na 0deg
    if (target_angle < 750)
        target_angle = 750;

    if (target_angle > 1350)
        target_angle = 1350;

    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, target_angle);
}