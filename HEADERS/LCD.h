#ifndef COTS_HAL_LCD_INTERFACE_H_
#define COTS_HAL_LCD_INTERFACE_H_

#define LCD_DATA_PORT       DPORTC


#define LCD_CTRL_PORT       DPORTD


#define LCD_RS         PIN0    
#define LCD_RW        PIN1    
#define LCD_EN          PIN2   


//init
void LCD_init();
 
//char
void LCD_sendChar(u8 Data);
 
//send command
void LCD_SendCommand(u8 command);
 
//Send String
void LCD_SendString (u8 *str);
void GOTEXY(u8 x,u8 y);
void LCD_voidWriteNumber(s32 num);

#endif 