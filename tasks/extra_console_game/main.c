#include <stdlib.h>
#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>
#include <time.h>
#include <string.h>

struct point {
  int x;
  int y;
};

struct box {
  int top;
  int bottom;
  int left;
  int right;
  int down;
};

struct snakePoint{
  struct point position;
  struct point velocity;
};

struct player{
  char name [100];
  int score;
};

void drawField(struct box field);
void drawBg (void);
void drawDownBox(struct box field);
void getName(struct box field, char* name);
void printMainMenu(struct box field, char* name);
void drawSnake(struct snakePoint* snake, int length);
void updatePosition(struct snakePoint* snake, int length);
int control (struct snakePoint* snake);
void generatePoint(struct point* pfood);
void drawFood(struct point food);
void printProgress (struct box field, int score, int lvl);
int endGame(struct box field, int score, char* name);
int checkBorders(struct box field, struct snakePoint* snake, int length);
int saveScore(int score, char* name);
int game(struct box field, char* name);
int drawHighscore(struct box field);

int main(void){

  struct box field = {4, 32, 4, 65, 26};
  int quit = 0;
  int playAgain = 1;
  char name [100] = "";

  getName(field, name);
  conLockInput();
  conHideCursor();

  printMainMenu(field, name);

  while(quit == 0){
    if (conIsKeyDown()) {
      char ch = getchar();
      if (ch == 'q'){
        quit = 1;
      }
      if(ch == '1'){
        conClear();
        while(playAgain){
          playAgain = game(field, name);
        }
        playAgain = 1;
        printMainMenu(field, name);
      }
      if(ch == '2'){
        conClear();
        drawHighscore(field);
        printMainMenu(field, name);
      }
    }
  }

  conShowCursor();
  conUnlockInput();
  conMove(field.bottom + 2, 0);
  return 0;
}

void drawBg (void) {
  int x;
  int y;

  conReset();
  for (x = 0; x <= 40; x++) {
    for (y = 0; y <= 144; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }
}

void drawField(struct box field) {

  conSetAttr(BG_YELLOW);

  for (int y = field.left ; y <= field.right; y++){
    conMove(field.top - 1, y);
    putchar(' ');
    conMove(field.down + 1, y);
    putchar(' ');
  }

  for (int x = field.top - 1 ; x <= field.down + 1; x++){
    conMove(x, field.left - 1);
    putchar(' ');
    conMove(x, field.right + 1);
    putchar(' ');
  }

  conSetAttr(BG_BLACK);
  for (int x = field.top; x <= field.down; x++) {
    for (int y = field.left; y <= field.right; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }

  conReset();
}

void drawDownBox(struct box field){
  conSetAttr(BG_BLACK);
  for (int x = field.down + 2; x <= field.bottom; x++) {
    for (int y = field.left; y <= field.right; y++) {
      conMove(x, y);
      putchar(' ');
    }
  }

  conSetAttr(BG_YELLOW);
  for (int y = field.left ; y <= field.right; y++){
    conMove(field.bottom + 1, y);
    putchar(' ');
  }

  for (int x = field.down - 1 ; x <= field.bottom + 1; x++){
    conMove(x, field.left - 1);
    putchar(' ');
    conMove(x, field.right + 1);
    putchar(' ');
  }

  conReset();
}

void getName(struct box field, char* name){
  drawBg();
  drawField(field);
  conSetAttr(BG_BLACK);

  conMove((field.top + field.down)/ 2, 20);
  printf("Enter your name: ");

  fgets(name, 100, stdin);
  name[strlen(name) - 1] = '\0';
}

void printMainMenu(struct box field, char* name){
  drawBg();
  drawField(field);
  conSetAttr(BG_BLACK);

  conMove((field.top + field.down)/ 2 - 2 , 24);
  printf("Hello, %s!", name);
  conMove((field.top + field.down)/ 2 , 24);
  printf("1. Play snake");
  conMove((field.top + field.down)/ 2 + 1 , 24);
  printf("2. See records table");
  conMove((field.top + field.down)/ 2 + 3 , 24);
  printf("Press q to quit");

  conReset();
}

void drawSnake(struct snakePoint* snake, int length){
  conSetAttr(BG_INTENSITY_MAGENTA);
  for(int i = 1; i < length; i++){
    conMove(snake[i].position.x, snake[i].position.y);
    printf(".");
  }

  conSetAttr(BG_MAGENTA);
  conMove(snake[0].position.x, snake[0].position.y);
  printf(" ");

  conReset();
}

void updatePosition(struct snakePoint* snake, int length){
  for(int i = length - 1; i != 0; i--){
    snake[i].position.x = snake[i - 1].position.x;
    snake[i].position.y = snake[i - 1].position.y;

    snake[i].velocity.x = snake[i - 1].velocity.x;
    snake[i].velocity.y = snake[i - 1].velocity.y;
  }

  snake[0].position.x += snake[0].velocity.x;
  snake[0].position.y += snake[0].velocity.y;
}

int control (struct snakePoint* snake){
  const struct point dirDown = {1, 0};
  const struct point dirUp = {-1, 0};
  const struct point dirLeft = {0, -1};
  const struct point dirRight = {0, 1};

  if (conIsKeyDown()) {
      char ch = getchar();
      if (ch == 'm'){
        return 1;
      }
      if (ch == 'w'){
        snake[0].velocity = dirUp;
      }
      if (ch == 's'){
        snake[0].velocity = dirDown;
      }
      if (ch == 'd'){
        snake[0].velocity = dirRight;
      }
      if (ch == 'a'){
        snake[0].velocity = dirLeft;
      }
  }
  return 0;
}

void generatePoint(struct point* pfood){
  srand(time(NULL));
  int xmin = 4;
  int xmax = 26;
  int ymin = 4;
  int ymax = 65;

  pfood->x = xmin + rand() % (xmax + 1 - xmin);
  pfood->y = ymin + rand() % (ymax + 1 - ymin);
}

void drawFood(struct point food){
  conSetAttr(FG_WHITE);
  conSetAttr(BG_BLACK);
  conMove(food.x, food.y);
  printf("0");
  conReset();
}

void printProgress (struct box field, int score, int lvl){
  conSetAttr(BG_BLACK);

  conMove((field.down + field.bottom)/ 2, 15);
  printf("your score is %i", score);

  conMove((field.down + field.bottom)/ 2, 35);
  printf("your level is %i/9", lvl);

  conMove((field.down + field.bottom)/ 2 + 2, 12);
  printf("Use [WASD] to move, [m] to go back to main menu ");

  conReset();
}

int checkBorders(struct box field, struct snakePoint* snake, int length){
  for(int i = 1; i < length; i++){
    if(snake[0].position.x == snake[i].position.x && snake[0].position.y == snake[i].position.y){
      return 1;
    }
  }

  if(snake[0].position.x == field.top - 1 || snake[0].position.x == field.down + 1|| \
  snake[0].position.y == field.left -1 || snake[0].position.y == field.right + 1){
    return 1;
  }

  return 0;
}


int endGame(struct box field, int score, char* name){
  drawDownBox(field);
  conSetAttr(BG_BLACK);

  conMove((field.down + field.bottom)/ 2, 27);
  printf("Game over");
  conMove((field.down + field.bottom)/ 2 + 1, 24);
  printf("Your score is %i", score);
  conMove((field.down + field.bottom)/ 2 + 2, 7);
  printf("Press [p] to play once more, [m] to go back to main menu");

  conReset();

  while(1){
    char ch = getchar();
    if (ch == 'p'){
      return 1;
    }
    if (ch == 'm'){
      return 0;
    }
  }
}

int chooseLvl(struct box field){
  int lvl = 0;
  int shift = 6;

  drawDownBox(field);
  drawField(field);
  conSetAttr(BG_BLACK);
  conMove(field.top + shift, 25);
  printf("Choose level:");

  for(int i = 0; i <= 9; i++){
    shift++;
    conMove(field.top + shift, 28);
    printf("level %i", i);
  }
  conReset();

  while(1){
    if(conIsKeyDown()){
      lvl = getInt();
      break;
    }
  }

  return lvl;
}

int saveScore(int score, char* name){
  char records [10][150];
  int flag = 0;
  int i = 0;

  FILE * fr = fopen("highscore.txt", "r+");

  if (fr == NULL){
    printf("Error opening file\n");
    return EXIT_FAILURE;
  }

  while(i != 9 && (!feof(fr))){
    fgets(records[i], 150, fr);
    if(strcmp(records[i], "")){
      flag = 1;
      i++;
    }
  }

  rewind(fr);

  if(flag == 0){
    fprintf(fr, "%i \t\t\t %s\n", score, name);
  } else {
    for(int j = 0, flag = 0; j < 10 && j != i; j++){
      if(atoi(records[j]) >= score || flag == 1){
        fputs(records[j], fr);
      } else if (atoi(records[j]) <= score && flag == 0){
        flag = 1;
        fprintf(fr, "%i \t\t\t %s\n", score, name);
        fputs(records[j], fr);
      }
    }
  }

  fclose(fr);
  return 0;
}


int game(struct box field, char* name){
  int gameOver = 0;
  //int speeds [10] = {300, 285, 265, 230, 200, 185, 150, 135, 100, 85};
  int speeds [10] = {200, 185, 150, 135, 110, 95, 85, 75, 65, 55};
  int speed = 300;
  const struct point dirRight = {0, 1};
  struct snakePoint snake [500] = {
    {20, 30, dirRight},
    {20, 29, dirRight},
    {20, 28, dirRight},
    {20, 27, dirRight},
    {20, 26, dirRight},
  };
  int length = 5;
  struct point food;
  generatePoint(&food);
  int lvlCounter = 0;
  int lvl = 0;
  int score = 0;
  int playAgain = 0;

  lvl = chooseLvl(field);
  speed = speeds[lvl];

    while(gameOver == 0) {
    drawField(field);
    drawDownBox(field);
    printProgress(field, score, lvl);

    if(control(snake)){
      playAgain = 0;
      return playAgain;
    }

    updatePosition(snake, length);
    drawFood(food);
    drawSnake(snake, length);
    gameOver = checkBorders(field, snake, length);

    if(snake[0].position.x == food.x && snake[0].position.y == food.y){
      length++;
      lvlCounter++;
      score++;
      generatePoint(&food);
    }

    if(lvlCounter == 4 && lvl != 9){
      lvlCounter = 0;
      lvl++;
      speed = speeds[lvl];
    }

    sleepMillis(speed);
  }

  saveScore(score, name);
  playAgain = endGame(field, score, name);
  return playAgain;
}


int drawHighscore(struct box field){
  drawBg();
  drawField(field);
  int shift = 3;
  char str [150];
  int score = 0;
  char name [100] = "";

  conSetAttr(BG_BLACK);

  conMove(field.top + shift, 27);
  printf("Highscores:");
  shift += 3;

  FILE * fr = fopen("highscore.txt", "r");
	if (fr == NULL){
    printf("Error opening file\n");
    return EXIT_FAILURE;
	}

  int i = 0;

  while(!feof(fr) && i != 10){
    fgets(str, 150, fr);
    sscanf(str, "%i %s", &score, name);
    conMove(field.top + shift, 16);
    printf("%s ", name);
    conMove(field.top + shift, 46);
    printf("%i\t\t", score);
    shift++;
    i++;
  }

  conMove(field.top + shift + 2, 16);
  printf("press [m] to return to main menu");

  conReset();

  while(1){
    if (conIsKeyDown()){
      char ch = getchar();
      if (ch == 'm'){
        return 0;
      }
    }
  }
}
