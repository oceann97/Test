#include "gpio.h"
#include "stm32f10x.h"

struct GPIO_PIN_Type_Def GPIO_PIN0 = { 0, 0};
struct GPIO_PIN_Type_Def GPIO_PIN1 = { 1, 4};
struct GPIO_PIN_Type_Def GPIO_PIN2 = { 2, 8};
struct GPIO_PIN_Type_Def GPIO_PIN3 = { 3, 12};
struct GPIO_PIN_Type_Def GPIO_PIN4 = { 4, 16};
struct GPIO_PIN_Type_Def GPIO_PIN5 = { 5, 20};
struct GPIO_PIN_Type_Def GPIO_PIN6 = { 6, 24};
struct GPIO_PIN_Type_Def GPIO_PIN7 = { 7, 28};

struct GPIO_PIN_Type_Def GPIO_PIN8  = { 8, 0};
struct GPIO_PIN_Type_Def GPIO_PIN9  = { 9, 4};
struct GPIO_PIN_Type_Def GPIO_PIN10 = { 10, 8};
struct GPIO_PIN_Type_Def GPIO_PIN11 = { 11, 12};
struct GPIO_PIN_Type_Def GPIO_PIN12 = { 12, 16};
struct GPIO_PIN_Type_Def GPIO_PIN13 = { 13, 20};
struct GPIO_PIN_Type_Def GPIO_PIN14 = { 14, 24};
struct GPIO_PIN_Type_Def GPIO_PIN15 = { 16, 28};

void gpio_enable_clk (uint8_t port){
		switch ( port ){
			case GPIO_PORTA : RCC->APB2ENR |= 1 << 2;break;
			case GPIO_PORTB : RCC->APB2ENR |= 1 << 3;break;
			case GPIO_PORTC : RCC->APB2ENR |= 1 << 4;break;
			case GPIO_PORTD : RCC->APB2ENR |= 1 << 5;
		}
}

void gpio_set_mode(GPIO_TypeDef * port, GPIO_PIN_Type_Def pin, uint8_t mode){
		if(pin.number < 8)
			port->CRL |= (mode & 0xF) << pin.offset;
		else
			port->CRH |= (mode & 0xF) << pin.offset;
}
	
uint8_t gpio_read_pin(GPIO_TypeDef * port, GPIO_PIN_Type_Def pin){
		return (port->IDR >> (pin.number)) & 0x1;
}

void gpio_write_pin(GPIO_TypeDef * port, GPIO_PIN_Type_Def pin, uint8_t value){
		if(value)port->ODR |= value << pin.number;
		else port->ODR &= value << pin.number;
}
