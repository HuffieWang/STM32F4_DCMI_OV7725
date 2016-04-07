/*********************** HNIT 3103 Application Team **************************
 * 文 件 名 ：main.c
 * 描    述 ：液晶显示    
 * 实验平台 ：STM32F407开发板
 * 库 版 本 ：ST1.4.0
 * 时    间 ：2016.3.19
 * 作    者 ：3103创新团队
 * 修改记录 ：无
******************************************************************************/

#include "stm32_sys.h"
#include "stm32_delay.h"
#include "stm32_usart.h"
#include "hnit_led.h" 
#include "hnit_key.h"
#include "hnit_lcd.h"

u16 imgData[80][80] = {0};

/*****************************************************************************
*	函 数 名: main
*	功    能: c程序入口
*   调用函数：无
*	形    参：无
*	返 回 值: 错误代码
******************************************************************************/	
int main(void)
{
	u32 t = 0;
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Delay_Init(168);
    USART1_Init(115200);		
    LCD_Init();
    LED_Init();
    KEY_Init();
    
    LCD_Clear(BLACK);   
    POINT_COLOR = BLACK;	
    BACK_COLOR = WHITE;
    
    while(KEY0 == 1);
    
    imgData[0][0] = 1;
    imgData[79][0] = 1;
    imgData[0][79] = 1;
    imgData[79][79] = 1;
    
    LCD_DisImg(imgData);
    LCD_DisNum(50,50,66666);

    while(1)
    {
        LED0 = ~LED0;
		Delay_ms(500);
		t++;
	}
}

/******************************* END OF FILE *********************************/
