/*********************** HNIT 3103 Application Team **************************
 * 文 件 名 ：main.c
 * 描    述 ：OV7725_DCMI摄像头驱动  
 * 实验平台 ：STM32F407开发板
 * 库 版 本 ：ST1.4.0
 * 时    间 ：2016.3.19
 * 作    者 ：3103创新团队
 * 修改记录 ：无
******************************************************************************/

//BUG Attention : disnum 不可以显示数字0

#include "stm32_sys.h"
#include "stm32_delay.h"
#include "stm32_usart.h"
#include "hnit_led.h" 
#include "hnit_key.h"
#include "hnit_lcd.h"
#include "hnit_ov7725.h"
#include "hnit_sccb.h"
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
    SCCB_GPIO_Config();    // IN MODE
    LCD_Clear(BLACK); 
    POINT_COLOR = WHITE; BACK_COLOR = BLACK; 
    
	while(Ov7725_Init() != SUCCESS);
   
//    LCD_DisImg(imgData);  
    while(1)
    {
        LED0 = ~LED0;
		Delay_ms(500);
		t++;
	}
}

/******************************* END OF FILE *********************************/
