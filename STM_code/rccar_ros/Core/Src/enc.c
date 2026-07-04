#include "enc.h"
#include "stm32_hal_legacy.h"
#include "tim.h"

int32_t encoder_position = 0;
int16_t encoder_delta = 0;

void encoder_sample(void) {
    static uint16_t last = 0;

    uint16_t now = (uint16_t)htim4.Instance->CNT;

    int16_t delta = (int16_t)(now - last);

    last = now;

    encoder_delta = delta;
    encoder_position += delta;
}

int16_t encoder_get_delta(void) {
    return encoder_delta;
}

int32_t encoder_get_position(void) {
    return encoder_position;
}

void encoder_set_position(int64_t pos) {
    encoder_position = pos;
}