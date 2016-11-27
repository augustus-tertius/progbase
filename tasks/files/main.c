#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int file_process(const char * readFileName, const char * writeFileName);

int main(void){
  const char * readFileName = "text.txt" ;
  const char * writeFileName = "results.txt";

  file_process(readFileName, writeFileName);

  return 0;
}

int file_process(const char * readFileName, const char * writeFileName){
  char task [] = "Записати кількість непустих рядків, які не починаються\
на число і які не містять жодних пробільних символів в собі.";
  int count = 0;
  int flag = 0;
  unsigned int i = 0;
  char str [250];
  char ch = str[i];


  FILE * fr = fopen(readFileName, "r");
  FILE * fout = fopen(writeFileName, "w");
	if (fr == NULL || fout == NULL){
    printf("Error opening file\n");
    return EXIT_FAILURE;
	}

  while (!feof(fr)) {
    fgets(str, 250, fr);
    str[strlen(str) - 1] = '\0';

    flag = 0;

    if(isdigit(str[0]) == 0 && str[0] != '\0'){
      for(i = 0, ch = str[i]; i < strlen(str); i++, ch = str[i]){
        if(ch == ' '){
          flag = 1;
          /* printf("found space\n"); */
        }
      }
      if(flag == 0){
        count++;
        fputs(str, fout);
        fprintf(fout, "\n");
      }
    }
    for (i = 0; i < strlen(str); i++) {
      str[i] = '\0';
    }
  }

  fprintf(fout, "\n\n");
  fputs(task, fout);
  fprintf(fout, "\n\n%i", count);

  fclose(fr);
  fclose(fout);

  return 0;
}
