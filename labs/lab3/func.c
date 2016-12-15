#include "lab_3.h"
#include "func.h"

struct lectureCourse* makePArr(int quan){
  struct lectureCourse* pArr = NULL;
  pArr = (struct lectureCourse*) malloc(quan * sizeof(struct lectureCourse));

  if (NULL == pArr){
        printf("Problems allocating memory");
        return NULL;
  } else {
    return pArr;
  }
  // обязательно в конце кода сделать free!
}


int saveToFile(struct lectureCourse* pArr, int quan, const char * FileName){
  int number = 0;

  FILE * fout = fopen(FileName, "w");
	if (fout == NULL){
    printf("Error opening file\n");
    return 0;
	}

  for(int i = 0; i < quan; i++){
    number = i + 1;

    fprintf(fout, "Lecture course № %i", number);
    fprintf(fout, "\ncourse name: %s", pArr[i].courseName);
    fprintf(fout, "\nlecturer`s surname:  %s", pArr[i].lecturer.surname);
    fprintf(fout, "\nlecturer`s name: %s", pArr[i].lecturer.name);
    fprintf(fout, "\nlecturer`s middle name: %s", pArr[i].lecturer.middlen);
    fprintf(fout, "\nlecturer`s age: %i", pArr[i].lecturer.age);
    fprintf(fout, "\ncourse length: %i", pArr[i].length);
    fprintf(fout, "\ncourse rating: %f", pArr[i].rating);
    fprintf(fout, "\n\n");
  }

  fclose(fout);
  return 1;
}

int readFromFile (struct lectureCourse* pArr, int quan, const char * FileName) {
  FILE * fr = fopen(FileName, "r");
  if (fr == NULL){
    printf("Error opening file \n");
    return 1;
  }
  char temp [5];
  for(int i = 0; i < quan && (!feof(fr)); i++){

    fgets(pArr[i].courseName, 300, fr);
    pArr[i].courseName[strlen(pArr[i].courseName) - 1] = '\0';
    fscanf(fr, "%s", pArr[i].lecturer.surname);
    fscanf(fr, "%s", pArr[i].lecturer.name);
    fscanf(fr, "%s", pArr[i].lecturer.middlen);
    fscanf(fr, "%i", &pArr[i].lecturer.age);
    fscanf(fr, "%d", &pArr[i].length);
    fscanf(fr, "%f", &pArr[i].rating);
    fgets(temp, 5, fr);
  }

  fclose(fr);
  return 0;
}


void copyStruct (struct lectureCourse* newStr, struct lectureCourse* oldStr){
  strcpy(newStr->courseName, oldStr->courseName);
  strcpy(newStr->lecturer.surname, oldStr->lecturer.surname);
  strcpy(newStr->lecturer.name, oldStr->lecturer.name);
  strcpy(newStr->lecturer.middlen, oldStr->lecturer.middlen);

  newStr->lecturer.age = oldStr->lecturer.age;
  newStr->length = oldStr->length;
  newStr->rating = oldStr->rating;
}

struct lectureCourse*  deleteStruct(struct lectureCourse* pArr, int* quan, int delnum){
  struct lectureCourse temp [*quan - 1];

  for(int i = 0; i < delnum - 1; i ++){
    copyStruct(&temp[i], &pArr[i]);
  }

  for(int i = delnum; i < *quan; i ++){
    copyStruct(&temp[i -1], &pArr[i]);
  }

  *quan = *quan - 1;

  pArr = (struct lectureCourse*) realloc(pArr, *(quan) * sizeof(struct lectureCourse));

  for(int i = 0; i < *quan && i != delnum + 1; i ++){
    copyStruct(&pArr[i], &temp[i]);
  }

  return pArr;
}

void refillParam(struct lectureCourse* course, int line, char str [300]){
  int var = 0;

  switch(line){
    case 1:
      strcpy(course ->courseName, str);
      break;
    case 2:
      strcpy(course ->lecturer.surname, str);
      break;
    case 3:
      strcpy(course ->lecturer.name, str);
      break;
    case 4:
      strcpy(course ->lecturer.middlen, str);
      break;
    case 5:
      var = atoi(str);
      course ->lecturer.age = var;
      break;
    case 6:
      var = atoi(str);
      course ->length = var;
      break;
    case 7:
      var = atof(str);
      course ->rating = var;
      break;
  }
}

int searchStr(struct lectureCourse* pArr, int quan, int x, struct lectureCourse* res[]){
  int count = 0;

  for(int i = 0; i < quan; i++){
    if(pArr[i].length > x) {
      res[count] = &pArr[i];
      count++;
    }
  }

  return count;
}

 char* structToStr(struct lectureCourse* lC, char str [1000]){
   char buffer [20] = "";
   str[0] = '\0';

   if(lC == NULL){
     return str;
   }


   strcat(str,  lC->courseName);
   strcat(str,  " ");
   strcat(str,  lC->lecturer.surname);
   strcat(str,  " ");
   strcat(str,  lC->lecturer.name);
   strcat(str,  " ");
   strcat(str,  lC->lecturer.middlen);
   strcat(str,  " ");

   sprintf(buffer, "%i ", lC ->lecturer.age);
   strcat(str,  buffer);
   sprintf(buffer, "%i ", lC ->length);
   strcat(str,  buffer);
   sprintf(buffer, "%5f", lC ->rating);
   strcat(str,  buffer);

   return str;
 }
