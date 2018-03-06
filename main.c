#include "stm32f4xx_gpio.h"  // file header untuk akses PORT I/O
#include "stm32f4xx.h"       // file header basic system STM32F4
#include "stm32f4xx_rcc.h"

#define LED_BLUE_ON   GPIOD->BSRRL = GPIO_Pin_15;  // led biru on
#define LED_BLUE_OFF  GPIOD->BSRRH = GPIO_Pin_15;  // led biru off
#define LED_RED_ON   GPIOD->BSRRL = GPIO_Pin_14;   // dst
#define LED_RED_OFF  GPIOD->BSRRH = GPIO_Pin_14;
#define LED_ORANGE_ON   GPIOD->BSRRL = GPIO_Pin_13;
#define LED_ORANGE_OFF  GPIOD->BSRRH = GPIO_Pin_13;
#define LED_GREEN_ON   GPIOD->BSRRL = GPIO_Pin_12;
#define LED_GREEN_OFF  GPIOD->BSRRH = GPIO_Pin_12;

void inisialisasi() // Inisialisasi port D, port tempat LED berada
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14|GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void delay(uint32_t ulang) // procedure delay
{
   while (ulang > 0)
   {ulang--;}
}

int main(void)
{  inisialisasi();        //memanggil fungsi inisialisasi
   while(1)               //proses berulang terus menerus
    {   LED_BLUE_ON;
        LED_RED_OFF;
        delay(1000000);
        LED_BLUE_OFF;
        LED_GREEN_ON;
        delay(1000000);
        LED_GREEN_OFF;
        LED_ORANGE_ON;
        delay(1000000);
        LED_ORANGE_OFF;
        LED_RED_ON;
        delay(1000000);
    }
}
