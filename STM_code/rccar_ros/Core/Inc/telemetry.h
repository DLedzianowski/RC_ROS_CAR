// telemetry.h
#pragma once
#include "main.h"
#include "stm32f1xx_hal_uart.h"

extern uint8_t rx_data[64];
extern uint8_t rx_buffer;


void telemetry_send_delta(int16_t delta);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);