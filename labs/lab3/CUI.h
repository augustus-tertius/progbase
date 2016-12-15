#define CUI
#ifdef CUI

struct menuBox {
  int top;
  int bottom;
  int left;
  int right;
  int head;
  int down;
};

void drawBg (void);
void drawBox(struct menuBox box);
void printMainMenu(struct menuBox box);
void drawDownBox(struct menuBox box);
void pEnterOperationCode(struct menuBox box);
int printGB(struct menuBox box);
void mainMenu(void);
struct lectureCourse* startMenu(struct menuBox box, int* quan);
void drawStartMenu(struct menuBox box);
void drawFileInstructions (struct menuBox box);
void conFillArr(struct lectureCourse* pArr, int quan, struct menuBox box);
int conSaveToFile(struct menuBox box, struct lectureCourse* pArr, int quan);
struct lectureCourse* conDeleteStruct(struct menuBox box, struct lectureCourse* \
pArr, int* quan);
int checkSrt(struct menuBox box, struct lectureCourse* pArr);
void conEmptyStr(struct menuBox box);
void drawParametrsList(struct menuBox box);
void conRefillParam(struct menuBox box, struct lectureCourse* pArr, int quan);
void conRefillStruct(struct menuBox box, struct lectureCourse* pArr, int quan);
void conSearchStr(struct menuBox box, struct lectureCourse* pArr, int quan);
void conStructToStr(struct menuBox box, struct lectureCourse* pArr, int quan);

#endif
