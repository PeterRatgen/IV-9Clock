#define F_CPU 16000000UL
#define BAUD 9600UL
#define LSBFIRST 1
#define HIGH 0x1
#define LOW  0x0
#define INPUT 0x0
#define OUTPUT 0x1

#include <avr/io.h>
#include <avr/interrupt.h>

#define SHIFT_REGISTER DDRB
#define SHIFT_PORT PORTB
#define DATA (1<<PB3)     //MOSI (SI)
#define LATCH (1<<PB2)        //SS   (RCK)
#define CLOCK (1<<PB5)        //SCK  (SCK)

#define ONE 0b00011000

int i = 0;

int main(void)
{
	//Setup IO
	SHIFT_REGISTER |= (DATA | LATCH | CLOCK); //Set control pins as outputs
	SHIFT_PORT &= ~(DATA | LATCH | CLOCK);        //Set control pins low
	
	//Setup SPI
	SPCR = (1<<SPE) | (1<<MSTR)  ;  //Start SPI as Master, 
	
	//Pull LATCH low (Important: this is necessary to start the SPI transfer!)
	SHIFT_PORT &= ~LATCH; // the ~ is a bitwise NOT
	
	//Shift in some data
	SPDR = 0b00111100;        //This should light alternating LEDs
	//Wait for SPI process to finish
	while(!(SPSR & (1<<SPIF)));
	
	//Shift in some more data since I have two shift registers hooked up
	SPDR = ONE;        //This should light alternating LEDs
	//Wait for SPI process to finish
	while(!(SPSR & (1<<SPIF)));
	
	//Toggle latch to copy data to the storage register
	SHIFT_PORT |= LATCH;
	SHIFT_PORT &= ~LATCH;
	
	cli();			//Disable global interrupts
		TCCR1B |= 1<<CS12;  //| 1<<CS10;	//Divide by 1024
		OCR1A = 15624;		//Count 15624 cycles for 1 second interrupt
		TCCR1B |= 1<<WGM12;		//Put Timer/Counter1 in CTC mode
		TIMSK1 |= 1<<OCIE1A;		//enable timer compare interrupt
	sei();			//Enable global interrupts
	
	DDRD |= (1<<0);		//Set PortD Pin0 as an output
	PORTD |= (1<<0);		//Set PortD Pin0 high to turn on LED
	
	while(1)
	{
	
	}
}

void  spiWait(void){
	while(!(SPSR & (1<<SPIF)));
}

ISR(TIMER1_COMPA_vect)		//Interrupt Service Routine
{
	PORTD ^= (1<<0);
	
}