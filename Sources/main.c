#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

void inicializaDisplay();
void delay1s();
void decTo7Seg(int dec);
void main(void) {
  int counter = 0;

  EnableInterrupts; /* enable interrupts */
  /* include your code here */
  
  CONFIG1_COPD=1; // Desabilita o módulo COP
  DDRB=0xFF; // Configura todos os PTBs como saida



  for(;;) {
    decTo7Seg(counter);
    delay1s();
    counter++;
    if(counter == 10)
      counter = 0;
  } 
}
void inicializaDisplay(){
  PTB = 0xFF; 
}

void delay1s(){
  _asm(    
        "LDA #20  \n"
        "Loop0: LDHX #31249    \n"
        "Loop1: AIX #-1        \n"
        "CPHX #0               \n"
        "BNE Loop1             \n"
        "DECA                  \n"
        "BNE Loop0             \n"
  );
}

void decTo7Seg(int dec){
   switch(dec){
    case 0:
      PTB = 0x1;
       break;
    case 1:
      PTB = 0xD7;
      break;
    case 2:
      PTB = 0x32;
      break;
    case 3:
      PTB = 0x92;
      break;
    case 4:
      PTB = 0xD4;
      break;
    case 5:
      PTB = 0x98;
      break;
    case 6:
      PTB = 0x18;
      break;
    case 7:
      PTB = 0xD3;
      break;
    case 8:
      PTB = 0x10;
      break;
    case 9:
      PTB = 0x90;
      break;
   }
}