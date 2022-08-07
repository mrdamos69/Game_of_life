#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define ROWS 25
#define COLS 80

void In_working_field(char one_working_field[ROWS][COLS]);
void Print_working_field(char one_working_field[ROWS][COLS]);
void Start_game(char one_working_field[ROWS][COLS], char two_working_field[ROWS][COLS], char form_life);
void Check_in(char one_working_field[ROWS][COLS], char form_life, int residents, int reproduction);
void Evolution(int b, int c, char one_working_field[ROWS][COLS], char form_life);
void Motion_life(char one_working_field[ROWS][COLS], char form_life);
void Print_nuul();
void Print_emblem();
void Print_emblem2();
void clear();

int main() {
    int residents = 0;
    int reproduction;
    srand((unsigned int) time(NULL));
    char one_working_field[ROWS][COLS];
    char two_working_field[ROWS][COLS];
    char form_life;
    int menu;
    printf("\n\n\n\n\n\t\t\t\t\t\tДОБРО ПОЖАЛОВАТЬ В ИГРУ\n\n");
    Print_emblem();
      printf("\n\n\t\t\t\t\t\tВЫБЕРИТЕ СИМВОЛ ДЛЯ ФОРМЫ ЖИЗНИ:\n\n ");
    scanf("%c", &form_life);
    printf("\n\t\t\t\t\tНАЖМИТЕ 1 ЧТОБЫ ЗАГРУЗИТЬ ПЕРВЫЙ СЦЕНАРИЙ:\n ");
    printf("\n\t\t\t\t\tНАЖМИТЕ 2 ЧТОБЫ ЗАГРУЗИТЬ ВТОРОЙ СЦЕНАРИЙ:\n ");
    printf("\n\t\t\t\t\tНАЖМИТЕ 3 ЧТОБЫ ЗАГРУЗИТЬ ТЕРЕТИЙ СЦЕНАРИЙ:\n ");
    printf("\n\t\t\t\t\tНАЖМИТЕ 4 ЧТОБЫ ЗАГРУЗИТЬ ЧЕТВЕРТЫЙ СЦЕНАРИЙ:\n ");
    printf("\n\t\t\t\t\tНАЖМИТЕ 5 ЧТОБЫ ЗАГРУЗИТЬ ПЯТЫЙ СЦЕНАРИЙ:\n ");
    printf("\n\t\t\t\t\tНАЖМИТЕ 6 ЧТОБЫ ВЫЙТИ НА ЭТАП ВЫБОРА ЖИЗНИ:\n ");
    scanf("%d", &menu);
    switch (menu) {
        case 1:
            reproduction = 1;
            In_working_field(one_working_field);
            Check_in(one_working_field, form_life, residents, reproduction);
            Start_game(one_working_field, two_working_field, form_life);
            break;
        case 2:
            reproduction = 2;
            In_working_field(one_working_field);
            Check_in(one_working_field, form_life, residents, reproduction);
            Start_game(one_working_field, two_working_field, form_life);
            break;
        case 3:
            reproduction = 3;
            In_working_field(one_working_field);
            Check_in(one_working_field, form_life, residents, reproduction);
            Start_game(one_working_field, two_working_field, form_life);
            break;
        case 4:
            reproduction = 4;
            In_working_field(one_working_field);
            Check_in(one_working_field, form_life, residents, reproduction);
            Start_game(one_working_field, two_working_field, form_life);
            break;
        case 5:
            reproduction = 5;
            In_working_field(one_working_field);
            Check_in(one_working_field, form_life, residents, reproduction);
            Start_game(one_working_field, two_working_field, form_life);
            break;
        case 6:
            break;
        default:
            printf("\n\t\t\t\t\t\tВЫ ВЫБРАЛИ НЕПРАВИЛЬНЫЙ ПУНКТ МЕНЮ !\n ");
            break;
    }
    return 0;
}

void Check_in(char one_working_field[ROWS][COLS], char form_life, int residents, int reproduction) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            residents = (rand() % 10);
            if (residents < reproduction)
                one_working_field[i][j] = form_life;
            else
                one_working_field[i][j] = ' ';
        }
    }
}

void Evolution(int b, int c, char one_working_field[ROWS][COLS], char form_life) {
    int neighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 && j == 0)|| b + j >= COLS || b + j < 0 || c + i >= ROWS || c + i < 0) {
                continue;
            }
            if (one_working_field[c + i][b + j] == form_life)
                neighbors++;
        }
    }
    if (neighbors == 3 || (neighbors == 2 && one_working_field[c][b] == form_life)) {
        one_working_field[c][b] = form_life;
    } else {
        one_working_field[c][b] = ' ';
    }
}

void Motion_life(char one_working_field[ROWS][COLS], char form_life) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Evolution(j, i, one_working_field, form_life);
        }
    }
}

void Start_game(char one_working_field[ROWS][COLS], char two_working_field[ROWS][COLS], char form_life) {
    int temp = 0;
    printf("\n\n\t\t\t\t\tНАЖМИТЕ 1, 2 ИЛИ 3 ДЛЯ ВЫБОРА СКОРОСТИ РАЗМНОЖЕНИЯ:\n ");
    int menu;
    int speed;
    scanf("%d", &menu);
    switch (menu) {
        case 1:
            speed = 300000;
            break;
        case 2:
            speed = 200000;
            break;
        case 3:
            speed = 100000;
            break;
        default:
            printf("\n\t\t\t\t\tВЫ ВЫБРАЛИ НЕПРАВИЛЬНЫЙ ПУНКТ МЕНЮ !\n ");
            temp = 1;
            break;
    }
    if (temp == 0) {
        while (temp <= 500) {
            Print_nuul();
            Print_working_field(one_working_field);
            Motion_life(one_working_field, form_life);
            usleep(speed);
            temp++;
        }
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tНАЖМИТЕ 1 ЧТОБЫ ВЫЙТИ\n ");
        printf
        ("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tНАЖМИТЕ 2 ИЛИ ДРУГУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ЦИКЛ\n");
        int action;
           scanf("%d", &action);
        switch (action) {
        case 1:
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tВЫ ВЫШЛИ !\n");
            break;
        case 2:
            Start_game(one_working_field, two_working_field, form_life);
            break;
        default:
            Start_game(one_working_field, two_working_field, form_life);
            break;
        }
    }
}

void Print_emblem() {
    printf("\t\t\t  ________                        ________   _____  .____    .__  _____       \n");
    printf("\t\t\t /  _____/_____    _____   ____   \\_____  \\_/ ____\\ |    |   |__|/ ____\\____  \n");
    printf
    ("\t\t\t/   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\   __\\  |    |   |  \\   __\\/ __ \\ \n");
    printf("\t\t\t\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\  |    |    |___|  ||  | \\  ___/ \n");
    printf("\t\t\t \\______  (____  /__|_|  /\\___  > \\_______  /__|    |_______ \\__||__|  \\___  >\n");
    printf("\t\t\t        \\/     \\/      \\/     \\/          \\/                \\/             \\/ \n\n");
}

void Print_emblem2() {
    printf("\t\t\t\t\t  __                             _____ .________\n");
    printf("\t\t\t\t\t_/  |_  ____ _____    _____     /  |  ||   ____/\n");
    printf("\t\t\t\t\t\\   __\\/ __ \\\\__  \\  /     \\   /   |  ||____  \\ \n");
    printf("\t\t\t\t\t |  | \\  ___/ / __ \\|  Y Y  \\ /    ^   /       \\\n");
    printf("\t\t\t\t\t |__|  \\___  >____  /__|_|  / \\____   /______  /\n");
    printf("\t\t\t\t\t           \\/     \\/      \\/       |__|      \\/ \n");
}
void In_working_field(char one_working_field[ROWS][COLS]) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            one_working_field[i][j] = ' ';
        }
    }
}

void Print_working_field(char one_working_field[ROWS][COLS]) {
    for (int i = 0; i < 25; i++) {
        for (int y = 0; y < 159; y++)
            printf("_");
        printf("\n");
        for (int j = 0; j < 80; j++) {
            printf("%c|", one_working_field[i][j]);
        }
        printf("\n");
    }
    for (int y = 0; y < 159; y++)
            printf("_");
    printf("\n\n\n");
    printf("\n\n\n");
    Print_emblem();
    printf("\n\n\n");
    Print_emblem2();
    clear();
}

void Print_nuul() {
    for (int i = 0; i < 25; i++) {
        for (int y = 0; y < 159; y++)
            printf(" ");
        printf("\n");
        for (int j = 0; j < 80; j++) {
            printf(" ");
        }
        printf("\n");
    }
    for (int y = 0; y < 159; y++)
            printf(" ");
    printf("\n\n\n");
    printf("\n\n\n");
    clear();
}

void clear() {
       printf("\e[1;1H\e{");
}

