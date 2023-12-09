/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#define LED_OPEN_Pin GPIO_PIN_13
#define LED_OPEN_GPIO_Port GPIOC
#define motor_fire_1_Pin GPIO_PIN_0
#define motor_fire_1_GPIO_Port GPIOA
#define motor_fire_2_Pin GPIO_PIN_1
#define motor_fire_2_GPIO_Port GPIOA
#define mf1_pin2_Pin GPIO_PIN_2
#define mf1_pin2_GPIO_Port GPIOA
#define mf1_pin1_Pin GPIO_PIN_3
#define mf1_pin1_GPIO_Port GPIOA
#define mf2_pin1_Pin GPIO_PIN_4
#define mf2_pin1_GPIO_Port GPIOA
#define mf2_pin2_Pin GPIO_PIN_5
#define mf2_pin2_GPIO_Port GPIOA
#define STEERING_ENGINE_Pin GPIO_PIN_6
#define STEERING_ENGINE_GPIO_Port GPIOA
#define motor3_pin1_Pin GPIO_PIN_12
#define motor3_pin1_GPIO_Port GPIOB
#define motor3_pin2_Pin GPIO_PIN_13
#define motor3_pin2_GPIO_Port GPIOB
#define motor4_pin1_Pin GPIO_PIN_14
#define motor4_pin1_GPIO_Port GPIOB
#define motor4_pin2_Pin GPIO_PIN_15
#define motor4_pin2_GPIO_Port GPIOB
#define motor_driver1_Pin GPIO_PIN_8
#define motor_driver1_GPIO_Port GPIOA
#define motor_driver2_Pin GPIO_PIN_9
#define motor_driver2_GPIO_Port GPIOA
#define motor_driver3_Pin GPIO_PIN_10
#define motor_driver3_GPIO_Port GPIOA
#define motor_driver4_Pin GPIO_PIN_11
#define motor_driver4_GPIO_Port GPIOA
#define motor1_pin1_Pin GPIO_PIN_3
#define motor1_pin1_GPIO_Port GPIOB
#define motor1_pin2_Pin GPIO_PIN_4
#define motor1_pin2_GPIO_Port GPIOB
#define motor2_pin1_Pin GPIO_PIN_5
#define motor2_pin1_GPIO_Port GPIOB
#define motor2_pin2_Pin GPIO_PIN_6
#define motor2_pin2_GPIO_Port GPIOB
#define left_track_Pin GPIO_PIN_7
#define left_track_GPIO_Port GPIOB
#define middle_track_Pin GPIO_PIN_8
#define middle_track_GPIO_Port GPIOB
#define right_track_Pin GPIO_PIN_9
#define right_track_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
