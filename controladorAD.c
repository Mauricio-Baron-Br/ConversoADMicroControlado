//include de bibliotecas
#include <controladorAD.h>
#include<stdio.h>
#include <stdlib.h>

//************************
//definiçoes de configuraçoes de pinos
#define LCD_ENABLE_PIN PIN_B5
#define LCD_RS_PIN PIN_B6
#define LCD_RW_PIN PIN_B7
#define LCD_DATA4 PIN_B4
#define LCD_DATA5 PIN_B3
#define LCD_DATA6 PIN_B2
#define LCD_DATA7 PIN_B1
#define PIN_ATUALIZA PIN_B0
//include de bibliotecas LCD
#include <lcd.c>
//*************************
//prototipos de funçoes
void AtualizaEstadoPino();

//*************************
void main()
{
  lcd_init();
  output_bit(PIN_B7,false);
  printf(lcd_putc,"\fImprimeValorA/D\n");
  int vdados[7];
  int i;
  
  while(TRUE){
     AtualizaEstadoPino();
    vdados[0]= input(PIN_A0);
    vdados[1]= input(PIN_A1);
    vdados[2]= input(PIN_A2);
    vdados[3]= input(PIN_A3);
    vdados[4]= input(PIN_A4);
    vdados[5]= input(PIN_A5);
    vdados[6]= input(PIN_A6);
    vdados[7]= input(PIN_A7);
     lcd_gotoxy(1,2);
     printf(lcd_putc,"Valor:");
     lcd_gotoxy(7,2);
     for(i=0;i<7;i++){
     printf(lcd_putc,"%d",vdados[i]);
     delay_ms(500);
     }
   }
}   
   void AtualizaEstadoPino(){
      output_bit(PIN_ATUALIZA,true);
      delay_ms(50);
      output_bit(PIN_ATUALIZA, false);
}
