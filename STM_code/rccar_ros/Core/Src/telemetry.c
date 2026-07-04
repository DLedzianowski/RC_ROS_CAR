#include "telemetry.h"
#include "usart.h"
#include "motor.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t rx_data[64];
uint8_t rx_buffer;

void parse_command(uint8_t *buf) {
    uint8_t var_ptr = 0;
    uint8_t char_ptr = 0;
    char var_buff[8] = {0};

    for(uint8_t *p=buf; *p != '\0'; p++) {
        if(*p == ',' || *p == '\n') {
            var_buff[char_ptr] = '\0';
            switch (var_ptr) {
                case 0: // throttle
                    set_target_speed(strtol(var_buff, NULL, 10));
                    break;
                case 1: // steer
                    set_target_angle(strtol(var_buff, NULL, 10));
                    break;
                default:
                    break;
            }
            var_ptr++;
            char_ptr = 0;
            var_buff[0] = '\0';
        }
        else {
            if (char_ptr < sizeof(var_buff) - 1) {
                var_buff[char_ptr++] = *p;
            }
        }
    }
}

void telemetry_send_delta(int16_t delta) {
    char tx[32];
    int len = snprintf(tx, sizeof(tx), "d%d\r\n", delta);

    HAL_UART_Transmit(&huart1, (uint8_t *)tx, (uint16_t)len, 10);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance != USART1)
        return;

    static uint8_t data_ptr = 0;

    if (data_ptr < sizeof(rx_data) - 1) {
        rx_data[data_ptr++] = rx_buffer;
    }
    else {
        data_ptr = 0;
        memset(rx_data, 0, sizeof(rx_data));
    }

    if (rx_buffer == '\n') {
        rx_data[data_ptr] = '\0';
        parse_command(rx_data);
        data_ptr = 0;

        char tx[32];
        int len = snprintf(tx, sizeof(tx), "speed=%d angle=%d\r\n", get_target_speed(), get_target_angle());
        HAL_UART_Transmit(&huart1, (uint8_t *)tx, (uint16_t)len, 10);

    }

    HAL_UART_Receive_IT(&huart1, &rx_buffer, 1);
}

