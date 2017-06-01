#include "api.h"

void api_commands(void)
{
	char * ptr_buf;

	char buf[127];
	char buf2[8][63];
	UART_gets(buf, 1);
	ptr_buf = buf;
	memset(buf2,0,sizeof buf2);
	int i = 0;
	int i_old = 0;
	int j = 0;
	while(1)
	{
		if(buf[i]== ',')
		{
			strncpy(buf2[j],ptr_buf+i_old,i-i_old);
			j++;
			i_old = i+1;
		}
		else if(buf[i] == '\0')
		{
			strncpy(buf2[j],ptr_buf+i_old,i-i_old);
			break;
		}
		i++;
	}
		if(strcmp(buf2[0], "clearscherm") == 0)
		{
			int color = color_decode(buf2[1]);
			UB_VGA_FillScreen(color);
			UART_puts("clearscherm");
			UART_puts("\n");
		}
		else if(strcmp(buf2[0], "lijn") == 0)
		{
			int color = color_decode(buf2[6]);
			line_fast2(strtol(buf2[1],NULL, 0),strtol(buf2[2],NULL, 0),strtol(buf2[3],NULL, 0),strtol(buf2[4],NULL, 0),strtol(buf2[5],NULL, 0),color);//line_fast(buf2[1], buf2[2], buf2[3], buf2[4], color); //// lijnbreedte!!!!!!
			UART_puts("lijn");
			UART_puts("\n");
		}
		else if(strcmp(buf2[0], "ellips") == 0)
		{
			int color = color_decode(buf2[5]);
			ellipse(strtol(buf2[1],NULL, 0),strtol(buf2[2],NULL, 0),strtol(buf2[3],NULL, 0),strtol(buf2[4],NULL, 0),color);
			UART_puts("ellips");
			UART_puts("\n");
		}
		else if(strcmp(buf2[0], "rechthoek") == 0)
		{
			int color = color_decode(buf2[5]);
			rechthoek(strtol(buf2[1],NULL, 0),strtol(buf2[2],NULL, 0),strtol(buf2[3],NULL, 0),strtol(buf2[4],NULL, 0),color);
			UART_puts("rechthoek");
			UART_puts("\n");
		}
		else if(strcmp(buf2[0], "driehoek") == 0)
		{
			int color = color_decode(buf2[7]);
			triangle(strtol(buf2[1],NULL, 0),strtol(buf2[2],NULL, 0),strtol(buf2[3],NULL, 0),strtol(buf2[4],NULL, 0),strtol(buf2[5],NULL, 0),strtol(buf2[6],NULL, 0),color,1);
			UART_puts("driehoek");
			UART_puts("\n");
		}
		else if(strcmp(buf2[0], "tekst") == 0)
		{
			int color = color_decode(buf2[4]);
			int font = font_decode(buf2[5]);
			write_string(buf2[3], strtol(buf2[1],NULL, 0),strtol(buf2[2],NULL, 0),color);
			UART_puts("tekst");
			UART_puts("\n");
		}
		else if(strcmp(buf2[0], "bitmap") == 0)
		{
			load_bitmap(strtol(buf2[1],NULL, 0),strtol(buf2[2],NULL, 0),strtol(buf2[3],NULL, 0));
			UART_puts("bitmap");
			UART_puts("\n");
		}
		else if(strcmp(buf2[0], "wacht") == 0)
		{
			UART_puts("wacht");
			UART_puts("\n");
			DELAY_ms(strtol(buf2[1],NULL, 0));
		}
		else
		{
			UART_puts("Error, wrong command");
		}
}

int font_decode(font)
{
	if(strcmp(font, "norm") == 0)
	{
		choose_font(arial, normal, size_8p);;
	}
	if(strcmp(font, "vet") == 0)
	{
		choose_font(arial, bold, size_8p);;
	}
	if(strcmp(font, "cursief") == 0)
	{
		choose_font(arial, cursive, size_8p);;
	}
}

int color_decode(color)
{
	if(strcmp(color, "zwart") == 0)
	{
		return VGA_COL_BLACK;
	}
	else if(strcmp(color, "rood") == 0)
	{
		return VGA_COL_RED;
	}
	else if(strcmp(color, "groen") == 0)
	{
		return VGA_COL_GREEN;
	}
	else if(strcmp(color, "blauw") == 0)
	{
		return VGA_COL_BLUE;
	}
	else if(strcmp(color, "lichtrood") == 0)
	{
		return VGA_COL_LIGHTRED;
	}
	else if(strcmp(color, "wit") == 0)
	{
		return VGA_COL_WHITE;
	}
	else if(strcmp(color, "lichtblauw") == 0)
	{
		return VGA_COL_LIGHTBLUE;
	}
	else if(strcmp(color, "geel") == 0)
	{
		return VGA_COL_YELLOW;
	}
	else if(strcmp(color, "lichtmagenta") == 0)
	{
		return VGA_COL_LIGHTMAGENTA;
	}
	else if(strcmp(color, "cyaan") == 0)
	{
		return VGA_COL_CYAN;
	}
	else if(strcmp(color, "lichtgroen") == 0)
	{
		return VGA_COL_LIGHTGREEN;
	}
	else if(strcmp(color, "magenta") == 0)
	{
		return VGA_COL_MAGENTA;
	}
	else if(strcmp(color, "lichtcyaan") == 0)
	{
		return VGA_COL_LIGHTCYAN;
	}
	else if(strcmp(color, "bruin") == 0)
	{
		return VGA_COL_BROWN;
	}

}
