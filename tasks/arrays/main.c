#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <progbase.h>
#include <pbconsole.h>
#include <time.h>
#include <string.h>

int main(void)
{
    
    int a[10];
    char s[10];
    int i = 0;
    int quan = 0;
    int sum = 0;
    double average = 0;
    int max = 0;
    int min = 199;
    int j = 0;

    srand(time(NULL)); 

    for(;i < 10; i++) {
        a[i] = rand()%299 - 99;
    }
    printf("1. Generate A and print it out: \n");
    
    for(i = 0; i < 10; i++) {
        printf("%i\t", a[i]);
    }
    printf("\n\n");


    printf("2. Elements in [-99; 127]: \n");
    for(i = 0; i < 10; i++) {
        if(a[i] < 127) {
            conSetAttr(BG_INTENSITY_GREEN);
            printf("%i", a[i]);
            conReset();
        } else {
            printf("%i", a[i]);
        }
       printf("\t");
    }
    printf("\n\n");
    
    
    printf("3. Elements less than '50': \n");
    for(i = 0; i < 10; i++) {
        if(a[i] < 50) {
            conSetAttr(BG_INTENSITY_YELLOW);
            printf("%i", a[i]);
            conReset();
            quan += 1;
            sum += a[i];
        } else {
            printf("%i", a[i]);
        }
       printf("\t");
    }
    
    if(quan != 0){
    	average = sum / quan;
    }
    
    printf("\n");
    printf("Count: \t\t %i \n", quan);
    printf("Sum: \t\t %i \n", sum);
    printf("Average: \t %.2f \n\n", average);
    
    
    printf("4. First maximal among [-50; 50]: \n");
    for(i = 0; i < 10; i++) {
        if(a[i] < 50 && a[i] > -50 && a[i] > max){
        	max = a[i];
        	j = i;
        }	
    }   	
    printf("Max: %i \t\t Index: %i \n\n", max, j);
    
    
    printf("5. First minimal positive: \n");
    for(i = 0; i < 10; i++) {
        if(a[i] > 0 && a[i] < min){
        	min = a[i];
        	j = i;
        }
    }
    printf("Min: %i \t\t Index: %i \n\n", min, j);
    
    
    printf("6. Array S: \n");
    for(i = 0; i < 10; i++) {
	if( i != 9){
		s[i]= abs(a[i]) % 95 + 32;
	} else {
		s[9] = '\0';
	}
    }
    puts(s);
    puts("");
    
    printf("7. Setting to zero values grater than '-25'\n");
    for(i = 0; i < 10; i++) {
        if(a[i] > -25){
        	a[i] = 0;
        	conSetAttr(BG_INTENSITY_MAGENTA);
		printf("%i", a[i]);
		conReset();
		printf("\t");
        } else {
        	printf("%i\t", a[i]);
        }
     }   
     printf("\n\n");
    
    

    return 0;
}
