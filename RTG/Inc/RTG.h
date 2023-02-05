/****************************************************************************
 * RTG.H
 *
 * Author: Eden sheiko
 *
 * Implements GPS random generator
****************************************************************************/
#ifndef INC_RTG_H_
#define INC_RTG_H_
/*--------------------*/
#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
/*--------------------*/
extern RNG_HandleTypeDef hrng;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
/*--------------------*/
#define ID_SIZE 6
/*--------------------*/
typedef struct data {
	uint8_t m_x;
	uint8_t m_y;
	uint8_t m_id[ID_SIZE];
	bool m_bit;
} data_t;
/*--------------------*/
#define UART_DEBUGER &huart3
#define UART_4 &huart4
#define GPIO_BLUE_LED LD2_Pin
/*--------------------*/
#define FALSE 0
#define TRUE 1
#define DELAY_TIME 100
/*--------------------*/
#define ZERO_VAL 0
#define ONE_VAL 1
#define BITS_IN_BYTE 8
#define TEN_VAL 10
#define THIRTEEN_VAL 13
#define TRUE 1
/*--------------------*/
void rtg_main();
void send_data();
void receive_data();
uint32_t RNG_GetRandomNumber(void);
void update_data();
/*--------------------*/
#endif /* INC_RTG_H_ */
