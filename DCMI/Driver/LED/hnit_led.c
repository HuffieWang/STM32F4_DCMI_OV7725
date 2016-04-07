/*********************** HNIT 3103 Application Team **************************
 * 文 件 名 ：hnit_led.c
 * 描    述 ：LED配置与操作         
 * 实验平台 ：STM32F407开发板
 * 库 版 本 ：ST1.4.0
 * 时    间 ：2016.3.19
 * 作    者 ：3103创新团队
 * 修改记录 ：无
******************************************************************************/

#include "hnit_led.h" 
	 
/*****************************************************************************
*	函 数 名: LED_Init
*	功    能: LED GPIO初始化
*   调用函数：GPIO类库函数
*	形    参：无
*	返 回 值: 无
******************************************************************************/	
void LED_Init(void)
{    	 
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);  //使能GPIOF时钟

    /* GPIOF9,F10初始化设置 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;         //普通输出模式
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;    //100MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;          //上拉
    GPIO_Init(GPIOF, &GPIO_InitStructure);                //初始化
	
    GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10);   //GPIOF9,F10设置高，灯灭
}

/******************************* END OF FILE *********************************/
