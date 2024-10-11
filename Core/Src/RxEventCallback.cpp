#include "main.h"
#include "usart.h"
extern DMA_HandleTypeDef hdma_usart6_rx;
extern uint8_t receivedata[50];
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if(huart->Instance == USART6)
    {
        HAL_GPIO_TogglePin(LED_G_GPIO_Port,LED_G_Pin);
        HAL_UART_Transmit_DMA(&huart6, receivedata, Size);
        HAL_UARTEx_ReceiveToIdle_DMA(&huart6,receivedata,sizeof(receivedata));
        __HAL_DMA_DISABLE_IT(&hdma_usart6_rx,DMA_IT_HT);
    }
}
