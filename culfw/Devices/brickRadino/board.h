#ifndef _BOARD_H
#define _BOARD_H

#include <stdint.h>

/* if you have an Arduino with only 8MHz disable the next line */
//#define HAS_16MHZ_CLOCK

/* if you are using a CC1101 module for 868MHz disable the next line */
//#define HAS_CC1100_433


#define SPI_PORT		PORTB
#define SPI_DDR			DDRB
#define SPI_SS			4
#define SPI_MISO		3
#define SPI_MOSI		2
/* die aufgelötete gelbe LED ist an PB5/SCLK angeschlossen! */
#define SPI_SCLK		1

#define CC1100_CS_DDR		SPI_DDR
#define CC1100_CS_PORT          SPI_PORT
#define CC1100_CS_PIN		SPI_SS


/* CC1101 GDO0 Tx / Temperature Sensor */
#if 0
#define CC1100_OUT_DDR		DDRC
#define CC1100_OUT_PORT         PORTC
#define CC1100_OUT_PIN          PC0
#define CC1100_OUT_IN           PINC
#define CCTEMP_MUX              CC1100_OUT_PIN
#else
#define CC1100_OUT_DDR		DDRB
#define CC1100_OUT_PORT         PORTB
#define CC1100_OUT_PIN          PB5
#define CC1100_OUT_IN           PINB
#define CCTEMP_MUX              CC1100_OUT_PIN
#endif

/* CC1101 GDO2 Rx Interrupt */
#define CC1100_IN_DDR		DDRE
#define CC1100_IN_PORT          PINE
#define CC1100_IN_PIN           PE6
#define CC1100_IN_IN            PINE

#define CC1100_INT		INT0
#define CC1100_INTVECT          INT0_vect
#define CC1100_ISC		ISC00
#define CC1100_EICR             EICRA

/* externe LED */
#define LED_DDR                 DDRD
#define LED_PORT                PORTD
#define LED_PIN                 7

//#define LED_ON_DDR              DDRB
//#define LED_ON_PORT             PORTB
//#define LED_ON_PIN              1



#define BOARD_ID_STR            "brickRadino868"
//#define BOARD_ID_STR433         "brickRadino433"

/* define this device as a 433 MHz one */
/* this isn't done like a CUL by reading a port pin but instead a fixed value of 0 for mark433_pin is used */
//#define MULTI_FREQ_DEVICE
//#define MARK433_PIN 			mark433_pin
//#define MARK433_BIT             0
//extern const uint8_t mark433_pin;

#define HAS_UART
#define UART_BAUD_RATE          38400
#define USART_RX_vect           USART1_RX_vect
#define USART_UDRE_vect         USART1_UDRE_vect


// we map uart 1 => uart 0 here (which is not existing)
#define UDR0 UDR1
#define UCSR0B UCSR1B
#define UDRIE0 UDRIE1
#define UCSR0A UCSR1A
#define FE0 FE1
#define DOR0 DOR1
#define U2X0 U2X1
#define UBRR0 UBRR1
#define RXCIE0 RXCIE1
#define RXEN0 RXEN1
#define TXEN0 TXEN1
#define UCSR0C UCSR1C
#define UCSZ00 UCSZ10
#define UCSZ01 UCSZ11
#define UDRIE0 UDRIE1


#define TTY_BUFSIZE             64

#define TTY_BUFSIZE_TX          514

#define RCV_BUCKETS            0      //                 RAM: 25b * bucket
//#define FULL_CC1100_PA                // PROGMEM:  108b
//#define HAS_CC1101_RX_PLL_LOCK_CHECK_TASK_WAIT
//#define HAS_CC1101_PLL_LOCK_CHECK_MSG
//#define HAS_CC1101_PLL_LOCK_CHECK_MSG_SW
#define HAS_MBUS

#endif
