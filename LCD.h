#ifndef LiquidCrystal_h
#define LiquidCrystal_h

#include <inttypes.h>
#include "Print.h"

//return values for ReadButtons()
typedef enum {
  BUTTON_NONE = 0, 
  BUTTON_RIGHT,
  BUTTON_UP,
  BUTTON_DOWN,
  BUTTON_LEFT,
  BUTTON_SELECT
} LCD_Button;

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

void LCD_setCursor_high(uint8_t, uint8_t); 
void LCD_setCursor_low(uint8_t, uint8_t); 
void LCD_setCursor(uint8_t, uint8_t); 

void LCD_write_high(uint8_t value);
void LCD_write_low(uint8_t value);
void LCD_write(uint8_t);
void LCD_print(char*);

void LCD_command(uint8_t);

void LCD_send_high(uint8_t, uint8_t);
void LCD_send_low(uint8_t);
void LCD_send(uint8_t, uint8_t);

void LCD_write4bits(uint8_t);
void LCD_write8bits(uint8_t);
void LCD_pulseEnable();

unsigned long LCD_UpdateTask( unsigned long timeWeHave );

LCD_Button LCD_ButtonTask( );

void LCD_SetStatus( const char *str, int offset = 0 );

void ShowError( int ErrNo, uint8_t code1, uint8_t code2, uint8_t code3 );
void LCD_Init( void );
void LCD_Clear( void );
LCD_Button LCD_ScanButtons( void );

#endif
