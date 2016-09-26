#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>

int main(void) 
{
    	int x = 0;
	int y = 0;
	int Wil = 28;
	int Hei = 16;
	
	conClear();
	
	conSetAttr(BG_INTENSITY_RED);

	for ( x = 1; x <= Hei; x++) {
		for ( y = 1; y <= Wil; y++) {
			conMove(x, y);
			putchar(' ');
			}
		}
	

	conSetAttr(BG_BLACK);

	for ( y = 10, x = 2; y <= Wil - 11 ; y++) {
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 8, x = 3; y <= 9; y++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 7, x = 4; y <= 8; y++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 6, x = 5; y <= 7; y++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 18, x = 3; y <= 20; y++, x++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 6, x = 6; x <= 12; x++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 21, x = 6; y <= 26; y++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 24, x = 7; y <= 26; y++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 21, x = 8; y <= 26; y++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 7, x = 9; y <= 21; y++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 21, x = 9; x <= 12; x++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 8, x = 13; y <= 19; y++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 7, x = 12; y <= 7; y++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 20, x = 12; y <= 20; y++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 9, x = 14; x <= 16; x++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 16, x = 14; x <= 16; x++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 12, x = 14; x <= 15; x++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 19, x = 14; x <= 15; x++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 10, x = 16; x <= 16; x++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 17, x = 16; x <= 16; x++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 13, x = 15; x <= 15; x++) {					
		conMove(x, y);
		putchar(' ');
		} 
	for ( y = 20, x = 15; x <= 15; x++) {					
		conMove(x, y);
		putchar(' ');
		}


	conSetAttr(BG_GREEN);
	for ( y = 7, x = 10; y <= 20; y++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 8, x = 12; y <= 19; y++) {					
		conMove(x, y);
		putchar(' ');
		}


	conSetAttr(BG_INTENSITY_YELLOW);
	for ( y = 7, x = 11; y <= 20; y++) {					
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 10, x = 3; y <= 17; y++) {
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 9, x = 4; y <= 18; y++) {
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 8, x = 5; y <= 19; y++) {
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 7; y <= 20; y++) {
		for ( x = 6; x <= 8; x++){
			conMove(x, y);
			putchar(' ');
			}
		}
	for ( y = 21, x = 7; y <= 23; y++) {
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 25, x = 7; y <= 25; y++) {
		conMove(x, y);
		putchar(' ');
		}


	conSetAttr(BG_BLACK);
	for ( y = 17, x = 6; y <= 17; y++) {
		conMove(x, y);
		putchar(' ');
		}
	for ( y = 15, x = 6; y <= 15; y++) {
		conMove(x, y);
		putchar(' ');
		}


	conMove(17, 1);
	conReset();
	puts ("");
	
	return 0;
}
