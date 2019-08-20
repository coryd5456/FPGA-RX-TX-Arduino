//This is a test program to set up transmission between FPGA and arduino uno
#include <avr/io.h>
//#include <UTFTGLUE.h> //graphics library for my touch screen 
#include <avr/interrupt.h>
// UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0); //all dummy args //Graphics library arguments
// define some macros
#define BAUD 200000                                   // define baud
#define BAUDRATE ((F_CPU)/(BAUD*8UL)-1)            // set baud rate value for UBRR
#define TX_PIN 1
int r = 0;
int c = 0;


void uart_init (void)
{
    UBRR0H = (BAUDRATE>>8);                      // shift the register right by 8 bits
    UBRR0L = BAUDRATE;                           // set baud rate
    UCSR0A|=(1<<U2X0);
    UCSR0B|= (1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);                // enable receiver and transmitter
    UCSR0C|= (1<<UCSZ00)|(1<<UCSZ01);   // 8bit data format

    DDRB = (1 << DDB0);
  sei();
    
}

// function to receive data
unsigned char uart_recieve (void)
{
    while(!(UCSR0A) & (1<<RXC0));                   // wait while data is being received
    return UDR0;                                   // return 8-bit data
}




 //int w = 0;

void main() {
  // put your setup code here, to run once:
  uart_init();
  //myGLCD.InitLCD(); // Graphics library init.
  //myGLCD.clrScr();  //Black screen for graphics
  //int i = 1;
  pinMode(LED_BUILTIN, OUTPUT);
  /* Code to check for a value. I originally used this to make sure the two boards were sinked.
  while (uart_recieve() != B11010001){
    digitalWrite(LED_BUILTIN, HIGH);
  }*/
  digitalWrite(LED_BUILTIN, LOW);
  
}


ISR(USART_RX_vect){
/* My code example for my project. Put your code here that you want to activate on interupt.
// The following code impliments similar to a double for loop. 
  r++;
 /* w++;
  if(w >250){
    w = 0;
  }*/
  if (r > 240){
    r = 0;
    if (c > 240){
      c = 0;
    }else {
      c++;
    }
  }*/
  uint8_t d = uart_recieve();//takes the recieved signal and puts it into an 8 bit int called "d". 
  /* Example of what to do with 
  myGLCD.setColor(d, 0 ,255 - d);
  myGLCD.drawPixel(40+r,c);*/
}
