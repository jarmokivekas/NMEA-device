// main.h

// this is the maximum string length for nmea read
#define MAX_STRLEN 120 
void Delay(__IO uint32_t nCount);
void init_GPIO();
void init_USART1(uint32_t baudrate);
void USART_puts(USART_TypeDef* USARTx, volatile char *s);

#define USART_RX_LED GPIO_Pin_12
#define USART_TX_LED GPIO_Pin_13
#define ALL_LEDS GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15
