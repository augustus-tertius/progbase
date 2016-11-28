#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int vovelsCount(const char * str, int * qptr);

int main(void){

  char str[100];
  int quan = 0;
  printf("PLease, enter a string: ");
  fgets(str, 100, stdin);
  str[strlen(str) - 1] = '\0';
  printf("\nYou've entered: %s\n", str);


  printf("\nTask: get number of all vovels in string\n\n");

  vovelsCount(str, &quan);

  printf("Quantity of vovels in the string is %i\n", quan);
  return EXIT_SUCCESS;
}

int isVovel(char ch){
  if(isupper(ch)){
    if(ch == 'A' || ch == 'E' || ch == 'O' || ch == 'I' || ch == 'U' || ch == 'Y'){
      return 1;
    }
  } else if(islower(ch)){
    if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u' || ch == 'y'){
      return 1;
    }
  }
  return 0;
}

 int vovelsCount(const char * str, int * qptr) {
    char firstChar = str[0];
    int quan = *qptr;

    if (firstChar == '\0') {
        return 0;
    } else {
      if(isVovel(firstChar)){
        quan ++;
        *qptr = quan;

        vovelsCount(str + 1, qptr);
      } else{
        vovelsCount(str + 1, qptr);
      }
    }
    return 0;
}
