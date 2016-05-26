/*---------------------------------------------------------------------
A simple emulation of MS-DOS based Conio Library in LINUX using ANSI 
Escape Sequences.
Autor: Sayan Mahapatra
Date: 4/04/2016
Copyright © 2016 Sayan Mahapatra
-----------------------------------------------------------------------
*/

#include <stdio.h>
#include "../include/conux.h"
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

inline void clrscr()
{
	printf("\e[2J\e[0;0H");
}
//Function to get a character from input buffer without waiting for 
//return key to be pressed
char getch()
{
	char c;
	system("stty raw -echo");
	c=getchar();
	system("stty cooked echo");
	return c;
}
//Function to move cursor around
inline void gotoxy(unsigned int x,unsigned int y)
{
	printf("\e[%u;%uH",abs(x),abs(y));
}
//Functions to control text color and formating
int hex_to_rgb(char *s)
{
	int i,j,x,rgb=(2<<24),temp=0;
	if(*s=='#')
	{
		 for(j=0;j<3;j++)
         {
            for(i=0;i<2;i++)
            {
             x=(s[(2*j+1)+i]>='A'&&s[(2*j+1)+i]<='F')?
               (s[(2*j+1)+i])-55:(s[(2*j+1)+i]>='0'&&s[(2*j+1)+i]<='9')?
               (s[(j*2+1)+i]-48):-1;
             temp+=x*(int)pow(16,1-i);
            }
            rgb=rgb^(temp<<((2-j)*8));
            temp=0;
         }
	 return rgb;
	 }
	 return DEFAULT;
}
		
			
void textcolor(unsigned int code)
{	
    
    unsigned int mode=code>>24;
	
	if(mode==0) // For Simple Colors
		printf("\e[3%dm",(code<<24)>>24);
	
	else if(mode==1) // For 256 Colors
		printf("\e[38;5;%dm",(code<<24)>>24);
	
	else if(mode==2) //For rgb colors
	{
		printf("\e[38;2;%d;%d;%dm",(code<<8)>>24,(code<<16)>>24,
				(code<<24)>>24);
	}
}

void textbackground(unsigned int code)
{	
    
    unsigned int mode=code>>24;
	
	if(mode==0) // For Simple Colors
		printf("\e[4%dm",(code<<24)>>24);
	
	else if(mode==1) // For 256 Colors
		printf("\e[48;5;%dm",(code<<24)>>24);
	
	else if(mode==2) //For RGB colors
	{
		printf("\e[48;2;%d;%d;%dm",(code<<8)>>24,(code<<16)>>24,
				(code<<24)>>24);
	}
}

inline void textformat(char *a)
{
	printf("%s",a);
}

inline void cursor_up(unsigned int lines)
{
	printf("\e[%uA",abs(lines));
}

inline void cursor_down(unsigned int lines)
{
	printf("\e[%uB",abs(lines));
}

inline void cursor_forward(unsigned int columns)
{
	printf("\e[%uC",abs(columns));
}

inline void cursor_backword(unsigned int columns)
{
	printf("\e[%uD",abs(columns));
}

void eraseline(unsigned int lineno)
{
	printf("\e[s");
	gotoxy(abs(lineno),0);
	printf("\e[2K");
	printf("\e[u");
	
}

inline void scroll_up(unsigned int lines)
{
    printf("\e[%dS",abs(lines));
}

inline void scroll_down(unsigned int lines)
{
    printf("\e[%dT",abs(lines));
}
