#define FUNC
#ifdef FUNC

struct lecturer {
  char surname [100];
  char name [100];
  char middlen [100];
  int age;
};

struct lectureCourse {
  char courseName [300];
  struct lecturer lecturer;
  int length; // тривалість курсу лекцій
  float rating; // оцінка курсу
};

struct lectureCourse* makePArr(int quan);

int saveToFile(struct lectureCourse* pArr, int quan, const char * FileName);
int readFromFile (struct lectureCourse* pArr, int quan, const char * FileName);
void copyStruct (struct lectureCourse* newStr, struct lectureCourse* oldStr);
struct lectureCourse*  deleteStruct(struct lectureCourse* pArr, int* quan, int delnum);
int searchStr(struct lectureCourse* pArr, int quan, int x, struct lectureCourse* res[]);
void refillParam(struct lectureCourse* course, int line, char str [300]);
char* structToStr(struct lectureCourse* lC, char str [1000]);

#endif
