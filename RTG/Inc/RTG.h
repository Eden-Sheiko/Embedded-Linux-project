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
/**
 * The HRNG is utilized for generating random numbers
 * , while the HUART3 is utilized for printing on the STM32.
 *  The HUART4, on the other hand, is utilized
 *  for communication with the BBG.
 */
extern RNG_HandleTypeDef hrng;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
/*--------------------*/
#define ID_SIZE 6
/*--------------------*/
/*
 * The 'data' structure encompasses four components:
 * m_x is an 8-bit unsigned integer that represents the x-coordinate.
 * m_y is an 8-bit unsigned integer that represents the y-coordinate.
 * m_id is an array that holds the unique MAC address, consisting of 6 bytes.
 * m_bit is a single byte indicating either a start signal or a stop signal.
 */
typedef struct data {
	uint8_t m_x;
	uint8_t m_y;
	uint8_t m_id[ID_SIZE];
	bool m_bit;
} data_t;
/*--------------------*/
/*
 * private defines
 */
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

/*
 * Main Program Loop
 */
void rtg_main();

/*
 * The 'send_data' function is responsible for transmitting data through UART4 at a bit rate
 * of 115200. The function employs the 'interrupt' method to accomplish this task, and
 * includes error checking measures in the event of a failure.
 */
void send_data();

/*
 * The 'receive_data' function is responsible for receiving data through UART4 at a bit rate
 * of 115200. The function employs the 'interrupt' method to accomplish this task, and
 * includes error checking measures in the event of a failure.
 */
void receive_data();

/*
 * The 'RNG_GetRandomNumber' function retrieves a random number using the RNG hardware.
 * It returns a 32-bit unsigned integer as the result.
 */
uint32_t RNG_GetRandomNumber(void);

/*
 * The 'update_data' function updates the 'm_x' and 'm_y' coordinates by utilizing the RNG hardware.
 * Please refer to the 'RNG_GetRandomNumber' function for additional information.
 */
void update_data();
/*--------------------*/
#endif /* INC_RTG_H_ */
