#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pbconsole.h>

int isToUpperConsonant(char ch);

int main(void) {
	
	char text[] = "I’ve watched through his eyes, I’ve listened through his ears, and I tell you he’s the one.\nOr at least as close as we’re going to get. That’s what you said about the brother.\nThe brother tested out impossible. For other reasons. Nothing to do with his ability.\nSame with the sister. And there are doubts about him. He’s too malleable.\nToo willing to submerge himself in someone else’s will.\nNot if the other person is his enemy.\nSo what do we do?\nSurround him with enemies all the time?";
	
	char ch = text[0];
	char nextCh;
	char prevCh;
	int i = 0; 
	int j = 0;
	int count = 0;
	int sent = 0;
	int row = 0;
	int len = strlen(text);
	char sentenses [20][500];
	
	
	
	/* task 1 */
	
	conSetAttr(BG_CYAN);
	printf("1. Вивести текст повністю у консолі та загальну кількість символів у тексті.");
	conReset();
	puts("");
	for(; ch != '\0'; i++) {
		ch = text[i];
	}
	
	puts(text);
	
	conSetAttr(FG_MAGENTA);
        printf("Кількість символів: %i\n\n", i);
        conReset();
	
	
	
	/* task 2 */
	
	conSetAttr(BG_CYAN);
	printf("2. Вивести текст без пробільних символів та символів пунктуації та кількість виведених символів.");
	conReset();
	puts("");
	
	for(i = 0, ch = text[0]; ch != '\0'; i++) {
		ch = text[i];
		if( 0 == isspace(ch) && 0 == ispunct(ch)) { 
			printf("%c", ch);
			count++;
		}
	}
	
	puts("");
	conSetAttr(FG_MAGENTA);
        printf("Кількість символів: %i\n\n", count);
        conReset();
	
	
	
	/* task 3 */
	
	conSetAttr(BG_CYAN);
	printf("3. Вивести всі речення тексту із відміткою про кількість символів у виведеному реченні.");
	conReset();
	puts("");
	
	for(i = 0; i < len; i++) {
		ch = text[i];
		nextCh = text[i + 1];
		if ((ch == '.' || ch == '!' || ch == '?') && (isspace(nextCh) || nextCh == '\0')) {
		    	i++; 
		    	sentenses[row][sent] = ch;
			sentenses[row][sent + 1] = '\0';
		    	row++;
		   	sent = 0;
        	} else {
            		sentenses[row][sent] = ch;
            		sent++;
        	}
    	}
    	
    	count = row;
    	
    	
   	for (row = 0; row < count; row++) {
        	puts(sentenses[row]);
        	conSetAttr(FG_MAGENTA);
        	printf("Кількість символів: %lu\n", strlen(sentenses[row]));
        	conReset();
       		puts("----//----");
    	}
	puts("");			
	
	
	
	/* task 4 */
	
	conSetAttr(BG_CYAN);
	printf("4. Вивести загальну кількість слів у тексті.");
	conReset();
	puts("");
	
	for(i = 0; i < len; i++){
		ch = text[i];
		nextCh = text[i + 1];
		if(isspace(nextCh) || ispunct(nextCh) || nextCh == '\0'){ 
			count++;
		}
	}
	
	conSetAttr(FG_MAGENTA);
	printf("Кількість слів у тексті: %i\n\n", count);
	conReset();
	
	
	/* task 5 */
	
	conSetAttr(BG_CYAN);
	printf("5. Bивести всі слова, що починаються на приголосну літеру у верхньому регістрі.");
	conReset();
	puts("");
	
	count = 0;
	
	for(i = 0; i < len; i++){
		ch = text[i];
		prevCh = text[i - 1];
		if((isspace(prevCh) || ch == text[0]) && isToUpperConsonant(ch)){ 
			for(j = i; isspace(text[j]) == 0 && text[j] != '\0'; j++){
				printf("%c",text[j]);
			}
			printf(", ");
			count++;
		}
	}
	
	conSetAttr(FG_MAGENTA);
        printf("\nКількість слів: %i\n\n", count);
        conReset();
	
	
	
	/* task 6 */
	
	conSetAttr(BG_CYAN);
	printf("6. Вивести всі слова, які закінчуються на ing.");
	conReset();
	puts("");
	
	count = 0;
	
	for(i = 0; i < len; i++){
		ch = text[i];
		if(text[i] == 'i' && text[i + 1] == 'n' && text[i + 2] == 'g'){
			count++;
			for(j = 0, prevCh = text[i - j]; isspace(prevCh) == 0; j++ ){
				prevCh = text[i - j];
			}
			for(; (i - j + 2) != (i + 3) ; j--){
				printf("%c",text[i - j + 2]);
			}
			printf(", ");
		}
	}
	
	conSetAttr(FG_MAGENTA);
        printf("\nКількість слів: %i\n\n", count);
        conReset();
	
	return 0; 
}


int isToUpperConsonant(char ch){
	if(isupper(ch)){
		if(ch == 'A' || ch == 'E' || ch == 'O' || ch == 'I' || ch == 'U' || ch == 'Y') {
			return 0;
		} else {
			return 1;
		}
	}
	return 0;
}
