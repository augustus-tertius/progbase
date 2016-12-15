#include "lab_3.h"
#include "func.h"
#include "test.h"
#include <assert.h>

void tests(void){
  testCopyStruct();
  testRefillParam();
  testStructToStr();
}

void testCopyStruct(void){
  struct lectureCourse oldStr  = {"Bla", "", "mama", "no", 45, 9, 5.0};
  struct lectureCourse newStr;

  copyStruct(&newStr, &oldStr);

  assert(strcmp(oldStr.courseName, oldStr.courseName ) == 0);
  assert(strcmp(oldStr.lecturer.surname, oldStr.lecturer.surname ) == 0);
  assert(newStr.lecturer.age == 45);
  assert(newStr.rating == 5.0);
  assert(newStr.length == oldStr.length);
}

void testRefillParam(void){
  struct lectureCourse test;

  char cname [300] = "some course name";
  refillParam(&test, 1, cname);
  assert(strcmp(test.courseName, cname) == 0);

  char age [300] = "50";
  refillParam(&test, 5, age);
  assert(test.lecturer.age == 50);

  char empty [300] = "";
  refillParam(&test, 4, empty);
  assert(strcmp(test.lecturer.middlen, empty) == 0);

  char numbers [300] = "123";
  refillParam(&test, 2, numbers);
  assert(strcmp(test.lecturer.surname, numbers) == 0);

  char letters [300] = "abc";
  refillParam(&test, 6, letters);
  assert(test.length == 0);
}

void testStructToStr(void) {
  struct lectureCourse test1 = { "Електротехніка", "Бужко", "Олена", "Миколаївна", 51, 48, 4.8};
  char str1 [1000];

  structToStr(&test1, str1);
  assert(strcmp(str1, "Електротехніка Бужко Олена Миколаївна 51 48 4.800000") == 0);


  struct lectureCourse* test2 = NULL;
  char str2 [1000];

  structToStr(test2, str2);
  assert(strcmp(str2, "") == 0);


}
