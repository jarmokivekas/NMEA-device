// main.h

// this is the maximum string length for nmea read
#define MAX_STRLEN 120 
void Delay(__IO uint32_t nCount);
void init_GPIO();
void init_USART1(uint32_t baudrate);
void USART_puts(USART_TypeDef* USARTx, volatile char *s);

