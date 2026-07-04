/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR_TIM2_F_Pin GPIO_PIN_0
#define MOTOR_TIM2_F_GPIO_Port GPIOA
#define MOTOR_TIM2_B_Pin GPIO_PIN_1
#define MOTOR_TIM2_B_GPIO_Port GPIOA
#define MOTOR_EN_F_Pin GPIO_PIN_1
#define MOTOR_EN_F_GPIO_Port GPIOB
#define MOTOR_EN_B_Pin GPIO_PIN_2
#define MOTOR_EN_B_GPIO_Port GPIOB
#define SERVO_PWM_TIM1_Pin GPIO_PIN_8
#define SERVO_PWM_TIM1_GPIO_Port GPIOA
#define enc_in1_Pin GPIO_PIN_6
#define enc_in1_GPIO_Port GPIOB
#define enc_in2_Pin GPIO_PIN_7
#define enc_in2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
