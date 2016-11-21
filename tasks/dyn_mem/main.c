#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {
    STRING_SIZE = 50
};

int main(void){
  char * inputStr = NULL;
  char ** shiftPtr = NULL;

  const char * symbols = "0123456789abcdf";
  const char * task = "Користувач вводить строку.\nВивести умову завдання і \
введену користувачем строку.\nНа основі введеної строки обчислити і \
вивести більше зі значень, яким відповідають перший і останній шістнадцятковий \
цифровий символи строки.\nВся виділена пам'ять перед закічненням роботи програми \
повинна бути звільнена.";
  int * firstVal = NULL;
  int * lastVal = NULL;
  int * position = NULL;
  char * ch = NULL;


  inputStr = (char *) malloc(STRING_SIZE * sizeof(char));
  shiftPtr = (char **) malloc(sizeof(char));
  firstVal = (int * )  malloc(sizeof(int));
  lastVal = (int * )  malloc(sizeof(int));
  position = (int * )  malloc(sizeof(int));
  ch = (char * )  malloc(sizeof(char));



  if (NULL == inputStr || NULL == shiftPtr || NULL == firstVal|| NULL == lastVal \
  || NULL == position || NULL == ch){
        printf("Alloc error");
        return EXIT_FAILURE;
  }

  puts(task);

  printf("\nPlease, input string: ");
  fgets(inputStr, sizeof(inputStr), stdin);

  puts("Your string is:");
  puts(inputStr);

  (*shiftPtr) = strpbrk(inputStr, symbols);
  (*ch) = inputStr[(**shiftPtr) - (*inputStr)];
  (* firstVal) =  strtol(ch, NULL, 16);


  for((*position) = strlen(inputStr); (*position) > 0 ; (*position)--){
    if(isxdigit(inputStr[(*position)])) {
      (*ch) = inputStr[(*position)];
      break;
    }
  }

  (*lastVal) = strtol(ch, NULL, 16);

  printf("\nValue of first symbol: %i \t\tValue of last symbol: %i\n(values are\
 presented in decimal notation)\n", (* firstVal), (* lastVal));
  if((* firstVal) > (* lastVal)){
    printf("First value is greater\n");
  } else {
    printf("Last value is greater\n");
  }

  free(inputStr);
  free(firstVal);
  free(lastVal);
  free(shiftPtr);
  free(position);
  free(ch);

  return EXIT_SUCCESS;
}
