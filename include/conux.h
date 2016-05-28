#ifndef CONUX_H
#define CONUX_H
//Macro Definations Start
//For Backward Compatibility with old TURBO Code
#define BLACK			0
#define RED				1
#define GREEN			2
#define YELLOW			3
#define BLUE			4
#define MAGENTA			5
#define CYAN			6	
#define GREY			7
#define DEFAULT			9
//Macro for Single Index Colors
#define CI(x)       	(x)|(1<<24)
//Macro for RGB Colors
#define RGB(x,y,z) 		(((z)|((y)<<8))|((x)<<16))|(2<<24)
//Macro For RGB Colors in Hexadecimal Format
#define HEX(X)          hex_to_rgb(#X)
//Macros for Text Formatting
#define BOLD			      "\e[1m"
#define UNDERSCORE		  "\e[4m"
#define BLINK			      "\e[5m"
#define RESET			      "\e[0m"
#define FAINT       	  "\e[2m"
#define INVERSE     	  "\e[7m"
#define HIDDEN			    "\e[8m" 
#define BOLD_OFF		    "\e[21m"
#define UNDERSCORE_OFF  "\e[24m"
#define BLINK_OFF       "\e[25m"
#define FAINT_OFF		    "\e[22m"
#define SHOW			      "\e[28m"
//Macros for Miscel
//Functions
void clrscr();
char getch();
void textcolor(unsigned int code);
void textbackground(unsigned int code);
void gotoxy(unsigned int x,unsigned int y);
void textformat(char *a);
void cursor_up(unsigned int lines);
void cursor_down(unsigned int lines);
void cursor_forward(unsigned int columns);
void cursor_backword(unsigned int columns);
void scroll_up(unsigned int lines);
void scroll_down(unsigned int lines);
void eraseline(unsigned int lineno);
#endif
