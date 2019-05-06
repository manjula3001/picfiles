
#if defined(__PCB__)
//#device PIC12F508
#include <12F508.h>

#fuses NOWDT,INTRC,NOPROTECT

#use delay(clock = 4000000)

#define uint unsigned int
#define uchar unsigned char

#define relay PIN_B0
#define process_led PIN_B2

#define oper_key PIN_B3
#define main_menu_mode 0x00

uchar rtc_sec,process_on,one_sec_cnt;
uchar b_onesec_flag;

uchar togle,ct_min,uc_mode;
///////////////////////////////////////////////////////////////////////////////
void millisec_delay(uchar cnt1)
{
//delay_ms(cnt1); 
//delay_ms(cnt1); 

   unsigned char m;
   unsigned int h;
   for(m = 0;m<cnt1;m++)
   {
      for(h = 0;h<50000;h++);
   }   
}
///////////////////////////////////////////////////////////////////////////
void main()
{
      set_tris_b(0x00);
      output_b(0x07);
     // output_high(relay);
    //  output_high(process_led);
      while(1);
}
/*
      delay_ms(500);
      output_low(relay);
      output_low(process_led);
      uc_mode = 1;
      while(1)
      {
          if(uc_mode == 2)
          {
          
          output_high(relay);
          output_high(process_led);
          }
          if((input(oper_key)) == 0)
          {
            ++uc_mode;
            while((input(oper_key)) == 0);
          }
          if(uc_mode == 3)
          {
          
          output_low(relay);
          output_low(process_led);
          }
      }
}
///////////////////////////////////////////////////////////////////////////////
/*#INT_TMR0
void timer0_isr(void)
{
  //clear_interrupt(INT_TIMER0);    // Clear timer0 interrupt flag bit
  set_timer0(61);
  
  if(++one_sec_cnt > 19)
  {
    one_sec_cnt = 0;
    b_onesec_flag = 1;
    
  }
}*/
//////////////////////////////////////////////////
/*
/////////////////////////////////////////////////////////
void main()
{
  
  set_tris_b(0x08);
  output_b(0x08);
  
 
 // millisec_delay(5);
  
//  delay_ms(500);
 
  
  b_onesec_flag = 0;
  one_sec_cnt = 0;
  //setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);
 // set_timer0(61);                // Timer0 preload value
  //clear_interrupt(INT_TIMER0);   // Clear timer0 interrupt flag bit
  //enable_interrupts(INT_TIMER0); // Enable timer0 interrupt
  //enable_interrupts(GLOBAL);     // Enable all unmasked interrupt
  
   
     
     
     process_on = 0;
     output_high(relay);
     togle = 0x00;
  while(1)
  { 
    
     if(b_onesec_flag == 0x01)
     {
       b_onesec_flag = 0;
       output_high(process_led);
       togle = togle ^ 0x01;
    
     if(process_on == 0x01)
     {
     //output_toggle(process_led);
      
     if(++rtc_sec > 59)
     {
        rtc_sec = 0;
        
     if(++ct_min == 1)
     {
      process_on = 0;
      output_low(relay);
      output_low(process_led);
     }//min
     }//sec
     }//process
     
     
     }//one_sec
    /*  if((input(oper_key)) == 0)
     {
     //delay_ms(30);
     if(process_on == 0x00)
     {
     
     uc_mode = main_menu_mode;
     output_high(process_led);
     output_high(relay);
     rtc_sec = 0;
     ct_min = 0; 
     
     process_on = 1;
     
     
     }
     else if(process_on == 0x01)
     {
       rtc_sec = 0;
       ct_min = 0; 
       output_high(process_led);
     }
       
     while((input(oper_key)) == 0);
     }
     
    /*
    if((get_timer0()) > 254)
     {
     set_timer0(61); 
     b_onesec_flag = 1;
     }
     
     delay_ms(1000);
     b_onesec_flag = 1;
  }//while(1)

}//main*/
