#include "stm32f10x.h"
#include "gpio.h" 
#include "timer.h"



void TIM2_IRQHandler (void){
		timer_clr_irq_flag (TIM2);;
		if(gpio_read_pin(GPIOC, GPIO_PIN13))
			gpio_write_pin(GPIOC, GPIO_PIN13,0);
		else 
			gpio_write_pin(GPIOC, GPIO_PIN13,1);	
}


	
int main(void)
{
		
	
	//gpio_enable_clk (GPIO_PORTA);
	gpio_enable_clk (GPIO_PORTC);
	gpio_set_mode(GPIOC, GPIO_PIN13, GPIO_PURPOSE_OUT_PUSHPULL_10MHz);
	gpio_write_pin(GPIOC, GPIO_PIN13,1);
	
	Timer_Init_Type_Def TIMER;
	TIMER.number = TIMER2;
	TIMER.period = 0x2328;
	TIMER.prescaler = 0xFA0;
	TIMER.mode_IRQ = TIMER_MODE_IRQ_UIF;
	
	timer_init (TIM2, &TIMER );
	
	timer_start (TIM2);
	
	NVIC_EnableIRQ (TIM2_IRQn);//razreshenie na obrabotku interrupt
		

while(1);


}
