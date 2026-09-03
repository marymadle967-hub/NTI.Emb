#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidIntinitialization(void){
 
 DDRA = DIO_PORTA_DIRECTION ;
 DDRB = DIO_PORTB_DIRECTION ;
 DDRC = DIO_PORTC_DIRECTION ;
 DDRD = DIO_PORTD_DIRECTION ;
}
//OUT OR IN
void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction)
{   if(PortID < 4 && PinID < 8)
    {
 if(Direction == OUTPUT)
 {
  switch(PortID)
  {
   case DPORTA: SET_BIT(DDRA, PinID); break;
   case DPORTB: SET_BIT(DDRB, PinID); break;
   case DPORTC: SET_BIT(DDRC, PinID); break;
   case DPORTD: SET_BIT(DDRD, PinID); break;
  }
 }
    else if(Direction == INPUT)
 {
  switch(PortID)
  {
   case DPORTA: CLR_BIT(DDRA, PinID); break;
   case DPORTB: CLR_BIT(DDRB, PinID); break;
   case DPORTC: CLR_BIT(DDRC, PinID); break;
   case DPORTD: CLR_BIT(DDRD, PinID); break;
  }
 }
    else 
 {
  /**No Code */
 }
    }
    else 
    {
  /**No Code */
    }
}

/**Output Mode*/
//5V OR 0V

void DIO_voidSetPinValue(u8 PortID, u8 PinID, u8 Value)
{
   if(PortID < 4 && PinID < 8)
   {
    if(Value == HIGH)
    {
     switch(PortID)
  {
   case DPORTA: SET_BIT(PORTA, PinID); break;
   case DPORTB: SET_BIT(PORTB, PinID); break;
   case DPORTC: SET_BIT(PORTC, PinID); break;
   case DPORTD: SET_BIT(PORTD, PinID); break;
  }
    }
    else if(Value == LOW)
       {
      switch(PortID)
  {
   case DPORTA: CLR_BIT(PORTA, PinID); break;
   case DPORTB: CLR_BIT(PORTB, PinID); break;
   case DPORTC: CLR_BIT(PORTC, PinID); break;
   case DPORTD: CLR_BIT(PORTD, PinID); break;
  }
    }
       else 
    {
     
    }     
   }
   else
   {
    
   }
   
}
u8 DIO_u8ReadPinValue(u8 PortID,u8 PinID)
{   u8 U8_Result =0;
 if(PortID < 4 && PinID < 8 )
 {      
            switch(PortID)
  {
   case DPORTA: U8_Result = GET_BIT(PINA, PinID); break;
   case DPORTB: U8_Result = GET_BIT(PINB, PinID); break;
   case DPORTC: U8_Result = GET_BIT(PINC, PinID); break;
   case DPORTD: U8_Result = GET_BIT(PIND, PinID); break;
  }
  
 }
 else
 {
  
 }
 return U8_Result;
}

void DIO_voidSetPortDirection(u8 PortID, u8 Direction)
{
 if(PortID < 4)
    {
  switch(PortID)
  {
   case DPORTA: DDRA = Direction; break;
   case DPORTB: DDRB = Direction; break;
   case DPORTC: DDRC = Direction; break;
   case DPORTD: DDRD = Direction; break;
  }
 }
 
}
void DIO_voidSetPortValue(u8 PortID, u8 Value)
{
    if(PortID < 4)
    {
  switch(PortID)
  {
   case DPORTA: PORTA = Value; break;
   case DPORTB: PORTB = Value; break;
   case DPORTC: PORTC = Value; break;
   case DPORTD: PORTD = Value; break;
  }
 }
 
}
u8 DIO_u8ReadPortValue(u8 PortID)
{
 u8 U8_Result =0;
 if(PortID < 4)
 {      
            switch(PortID)
  {
   case DPORTA: U8_Result = PINA ; break;
   case DPORTB: U8_Result = PINB ; break;
   case DPORTC: U8_Result = PINC ; break;
   case DPORTD: U8_Result = PIND ; break;
  }
  
 }
 else
 {
  
 }
 return U8_Result;
 
}
