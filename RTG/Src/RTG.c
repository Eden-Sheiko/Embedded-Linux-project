/****************************************************************************
 * RTG.c
 *
 * Author: Eden sheiko
 *
 * Implements GPS random generator
****************************************************************************/
#include "RTG.h"

char tx_flag_callback_success = FALSE, rx_flag_callback_success = FALSE;

data_t data;

#define STRUCT_SIZE_DATA (sizeof(data))

void print_struct(data_t *ptr);

void rtg_main() {
	while (TRUE) {
		receive_data();
		update_data();
		send_data();
	}
}

void send_data() {
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buffer[STRUCT_SIZE_DATA];
	memcpy(buffer, &data, STRUCT_SIZE_DATA);

	for (;;) {
		status = HAL_UART_Transmit_IT(UART_4, buffer,
		STRUCT_SIZE_DATA);
		if (status != HAL_OK) {
			printf("Failed HAL_UART_Transmit: %d\n\r", status);
		}
		return;
	}
}

void receive_data() {
	HAL_StatusTypeDef status = HAL_OK;
	for (;;) {
		uint8_t buffer[STRUCT_SIZE_DATA];
		status = HAL_UART_Receive_IT(UART_4, buffer,
		STRUCT_SIZE_DATA);
		if (status != HAL_OK) {
			printf("Failed HAL_UART_recivie: %d\n\r", status);
		}

		if (rx_flag_callback_success) {
			HAL_UART_Receive_IT(UART_4, buffer, STRUCT_SIZE_DATA);
			memcpy(&data, buffer, STRUCT_SIZE_DATA);
			print_struct(&data);
			//return;
			rx_flag_callback_success = FALSE;
			return;
		}
		HAL_Delay(DELAY_TIME);
	}

}

void update_data() {
	data.m_x = RNG_GetRandomNumber();
	data.m_y = RNG_GetRandomNumber();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) { //got info good

	if (UART_4 == huart) {
		//HAL_GPIO_TogglePin(GPIOB, GPIO_BLUE_LED);
		rx_flag_callback_success = TRUE;
	}

}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) { // send data good
	if (UART_4 == huart) {
		tx_flag_callback_success = TRUE;
	}
}

uint32_t RNG_GetRandomNumber(void) {
	uint32_t random_number;
	if (HAL_RNG_GenerateRandomNumber(&hrng, &random_number) != HAL_OK) {
		Error_Handler();
	}
	return random_number;
}

void print_struct(data_t *ptr) {
	printf("Signal Received: %d\r\n", ptr->m_bit);
}

