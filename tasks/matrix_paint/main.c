#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>

int main(void) {
    /* colors encoding table */

    const char colorsTable[16][2] = {
        {'0', BG_BLACK},
	{'2', BG_RED},
	{'4', BG_GREEN}, 
	{'3', BG_YELLOW},
	{'8', BG_BLUE},
	{'A', BG_MAGENTA},
	{'6', BG_CYAN},
	{'B', BG_WHITE},
        {'1', BG_INTENSITY_BLACK},
	{'9', BG_INTENSITY_RED},
	{'5', BG_INTENSITY_GREEN}, 
	{'7', BG_INTENSITY_YELLOW},
	{'C', BG_INTENSITY_BLUE},
	{'D', BG_INTENSITY_MAGENTA},
	{'E', BG_INTENSITY_CYAN},
        {'F', BG_INTENSITY_WHITE}
    };
    int colorsTableLength = sizeof(colorsTable) / sizeof(colorsTable[0]);
    char colorsPalette[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int colorsPaletteLength = sizeof(colorsPalette) / sizeof(colorsPalette[0]);
    int i = 0;
    int j = 0;
    int colorPairIndex = 0;
    int size = 28;
    int x, y;
    int count = 0;
    int idir = 0;
    int jdir = 0;
    int lim = 0; 
    int tmp;
    char image[28][28] = {
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { 'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F' },
    { 'F','F','F','2','2','2','2','2','2','2','F','F','F','F','F','F','F','F','5','5','5','5','5','5','5','F','F','F' },
    { 'F','F','2','2','2','2','2','2','2','2','2','2','2','F','F','5','5','5','5','5','5','5','5','5','5','5','F','F' },
    { 'F','3','3','3','7','7','7','0','7','F','F','F','F','F','F','F','F','F','F','7','0','7','7','7','3','3','3','F' },
    { '3','7','3','7','7','7','7','0','7','7','7','F','F','F','F','F','F','7','7','7','0','7','7','7','7','3','7','3' },
    { '3','7','3','3','7','7','7','7','0','7','7','7','F','F','F','F','7','7','7','0','7','7','7','7','3','3','7','3' },
    { 'F','3','7','7','7','7','7','0','0','0','0','F','F','F','F','F','F','0','0','0','0','7','7','7','7','7','3','F' },
    { 'F','F','7','7','7','7','7','7','7','7','F','F','F','F','F','F','F','F','7','7','7','7','7','7','7','7','F','F' },
    { 'F','F','2','2','8','2','2','8','2','2','F','F','F','F','F','F','F','F','5','5','A','5','5','A','5','5','F','F' },
    { 'F','2','2','2','8','2','2','8','2','2','2','F','F','F','F','F','F','5','5','5','A','5','5','A','5','5','5','F' },
    { '2','2','2','2','8','8','8','8','2','2','2','2','F','F','F','F','5','5','5','5','A','A','A','A','5','5','5','5' },
    { '7','7','2','8','6','8','8','6','8','2','7','7','F','F','F','F','7','7','5','A','C','A','A','C','A','5','7','7' },
    { '7','7','7','8','8','8','8','8','8','7','7','7','F','F','F','F','7','7','7','A','A','A','A','A','A','7','7','7' },
    { '7','7','8','8','8','8','8','8','8','F','7','F','F','F','F','F','F','7','F','A','A','A','A','A','A','A','7','7' },
    { 'F','F','8','8','8','F','F','F','8','8','8','F','F','F','F','F','F','A','A','A','F','F','F','A','A','A','F','F' },
    { 'A','A','A','A','A','F','F','F','A','A','A','A','A','F','F','B','B','B','B','B','F','F','F','B','B','B','B','B' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' }
    };
    
    conClear();
    for (i = 0; i < colorsPaletteLength; i++)
    {
        char colorCode = '\0';
        char color = '\0';
        /* get current color code from colorsPalette */
        colorCode = colorsPalette[i];
        /* find corresponding color in table */
        for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++) 
        {
            char colorPairCode = colorsTable[colorPairIndex][0];
            char colorPairColor = colorsTable[colorPairIndex][1];
            if (colorCode == colorPairCode) 
            {
                color = colorPairColor;
                break;  /* we have found our color, break the loop */
            }
        }
        /* print space with founded color background */
        conSetAttr(color);
        putchar(' ');
    }
    conReset();
    printf(" \n \n \n");
    
    /* task 2 */
    
    for (i = 0; i < size; i++) 
    {
    	for(j = 0; j < size; j++)
	{
		char colorCode = '\0';
		char color = '\0';
		colorCode = image[i][j];
		for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++) 
		{
		    char colorPairCode = colorsTable[colorPairIndex][0];
		    char colorPairColor = colorsTable[colorPairIndex][1];
		    if (colorCode == colorPairCode) 
		    {
		        color = colorPairColor;
		        break;
		    }
		}
		conSetAttr(color);
		putchar(' ');
	}
    puts("");
    conReset();
    }
    printf(" \n \n \n");
     conClear();

    /* task 3 */
    
    i = size - 1;
    j = 0;
    idir = 0;
    jdir = 1;
    lim = 0;

    for (count = 0; count <= size * size; count++) {
       
	char colorCode = '\0';
	char color = '\0';
	colorCode = image[i][j];
	for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++) 
	{
		char colorPairCode = colorsTable[colorPairIndex][0];
		char colorPairColor = colorsTable[colorPairIndex][1];
		if (colorCode == colorPairCode) 
		{
		        color = colorPairColor;
		        break;
		}
	}
	conSetAttr(color);
	
	x = j + 1;
        y = i + 1;
        conMove(y, x);
        fflush(stdout);  
        sleepMillis(25);
        putchar(' ');
       
        i += idir;
        j += jdir;


        if (j == size  - lim) {
            j--;
            i--;
            jdir = 0;
            idir = -1;
        }
        if (i == -1 + lim) {
            i++;
            j--;
            idir = 0;
            jdir = -1;
        }
	if (j == -1 + lim) {
            j++;
            i++;
            idir = 1;
            jdir = 0;
        }
        if (i == (size - 2 - lim) && j == lim) {
            lim++;
            idir = 0;
            jdir = 1;
        }
    }

    conReset();
    conMove( size * 3, 1);
    
    
    /*task 4*/
    
    for (i = 0; i < size / 2; i++) {
        for (j = i + 1; j < size - i; j++) {
          
            tmp = image[size - 1 - i][size - 1 - j];
            image[size - 1 - i][size - 1 - j]= image[size - 1 - j][i];
            image[size - 1 - j][i] = tmp;
            
            tmp =  image[size - 1 - j][i];
            image[size - 1 - j][i] = image[i][j];
            image[i][j] = tmp;
            
            tmp = image[i][j];
            image[i][j] = image[j][size - 1 - i];
            image[j][size - 1 - i] = tmp;
        }
    }
    
   for (i = 0; i < size; i++) 
    {
    	for(j = 0; j < size; j++)
	{
		char colorCode = '\0';
		char color = '\0';
		colorCode = image[i][j];
		for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++) 
		{
		    char colorPairCode = colorsTable[colorPairIndex][0];
		    char colorPairColor = colorsTable[colorPairIndex][1];
		    if (colorCode == colorPairCode) 
		    {
		        color = colorPairColor;
		        break;
		    }
		}
		conSetAttr(color);
		putchar(' ');
		conReset();
	}
    puts("");
    }
    printf(" \n \n \n");   
  	
    return 0;
}
