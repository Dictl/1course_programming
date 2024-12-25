#include <iostream>
#include <conio.h>
#include "windows.h"
#include <unistd.h>
#include <limits>
#include <vector>

using namespace std;
int xGame = 0, yGame = 0, walls = 0, food = 0, snakes[2] = {0, 0}, tx, ty;
char pole[22][22];
bool goThrowWall = false;
COORD snakeOne, snakeTwo;
vector<COORD> tail1, tail2;

string menu_str[] = {"1. ‘â¥­ª¨",
                     "2. …¤ ",
                     "3. ‡¬¥©ª ",
                     "4. à®å®¤ áª¢®§ì à ¬ªã",
                     "5. ‘â àâ ¨£àë",
                     "0. ‚ëå®¤"};

int btn_take() {
    int btn;
    btn = getch();
    return btn;
}

int intInput() {
    int userInput;
    while (!(cin >> userInput) || userInput < -2147483648 || userInput > 2147483648 || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "’ë ­¥ ñ¦¨ª - ç¨â âì ã¬¥¥èì. ‚¢¥¤¨ ç¨á«® ­®à¬ «ì­®¥" << endl;
    }
    cout << "‚ë ¢¢¥«¨: " << userInput << endl;

    return userInput;
}

bool isTailOnField(int x, int y) {
    for (int i = 0; i < tail1.size(); i++) {
        if (x == tail1[i].X && y == tail1[i].Y)
            return true;
    }
    for (int i = 0; i < tail2.size(); i++) {
        if (x == tail2[i].X && y == tail2[i].Y)
            return true;
    }
    return false;
}

void printPole() {
    system("cls");
    for (int i = 0; i < xGame; i++) {
        for (int j = 0; j < yGame; j++) {
            if (isTailOnField(i, j)) {
                cout << (char) 197;
            } else {
                cout << pole[i][j];
            }
        }
        cout << endl;
    }

}


void gameOver() {
    system("cls");
    printf("°Ûßß°ÛßÛ°ÛÜÛ°Ûßß°°°ÛßÛ°Û°Û°Ûßß°ÛßÜ°Û\n"
           "°Û°Û°ÛßÛ°Û°Û°Ûßß°°°Û°Û°ßÜß°Ûßß°ÛßÜ°ß\n"
           "°ßßß°ß°ß°ß°ß°ßßß°°°ßßß°°ß°°ßßß°ß°ß°ß\n");
    sleep(7);
    exit(1);
}

void gameWin() {
    system("cls");
    printf("                                          \n"
           "  _____            ____  _____   ______   \n"
           " |\\    \\   _____  |    ||\\    \\ |\\     \\  \n"
           " | |    | /    /| |    | \\\\    \\| \\     \\ \n"
           " \\/     / |    || |    |  \\|    \\  \\     |\n"
           " /     /_  \\   \\/ |    |   |     \\  |    |\n"
           "|     // \\  \\   \\ |    |   |      \\ |    |\n"
           "|    |/   \\ |    ||    |   |    |\\ \\|    |\n"
           "|\\ ___/\\   \\|   /||____|   |____||\\_____/|\n"
           "| |   | \\______/ ||    |   |    |/ \\|   ||\n"
           " \\|___|/\\ |    | ||____|   |____|   |___|/\n"
           "    \\(   \\|____|/   \\(       \\(       )/  \n"
           "     '      )/       '        '       '   ");

    sleep(7);
    exit(1);
}

void printPoleWCurs(int maxX, int maxY, int x, int y) {
    system("cls");
    cout << "Enter - ãáâ ­®¢¨âì(ã¤ «¨âì) Esc - ‚ëå®¤\n";
    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            if (i == x && j == y) {
                cout << "*";
            } else { cout << pole[i][j]; }
        }
        cout << endl;
    }
}

bool spaceLeft() {
    for (int i = 0; i < xGame; i++) {
        for (int j = 0; j < yGame; j++) {
            if (pole[i][j] == (char) 250 && !isTailOnField(i, j)) {
                return true;
            }
        }
    }
    return false;
}


void move(int snake, int where) {//186 205 201 200 187 188 áâ¥­ë
    if (snake == 1) {//253 228 §¬¥¨
        switch (where) {
            case 1:
                if ((pole[snakeOne.X - 1][snakeOne.Y] == (char) 250 ||
                     pole[snakeOne.X - 1][snakeOne.Y] == (char) 111 || (goThrowWall &&
                                                                        (pole[snakeOne.X - 1][snakeOne.Y] ==
                                                                         (char) 186 ||
                                                                         pole[snakeOne.X - 1][snakeOne.Y] ==
                                                                         (char) 205 ||
                                                                         pole[snakeOne.X - 1][snakeOne.Y] ==
                                                                         (char) 201 ||
                                                                         pole[snakeOne.X - 1][snakeOne.Y] ==
                                                                         (char) 200 ||
                                                                         pole[snakeOne.X - 1][snakeOne.Y] ==
                                                                         (char) 187 ||
                                                                         pole[snakeOne.X - 1][snakeOne.Y] ==
                                                                         (char) 188))) && snakes[0] == 1 &&
                    !isTailOnField(snakeOne.X - 1, snakeOne.Y)) {
                    COORD newtail{snakeOne.X, snakeOne.Y};
                    tail1.push_back(newtail);
                    pole[snakeOne.X][snakeOne.Y] = (char) 250;
                    if (pole[snakeOne.X - 1][snakeOne.Y] == (char) 250) {
                        tail1.erase(tail1.begin());
                        pole[snakeOne.X - 1][snakeOne.Y] = (char) 228;
                        snakeOne.X--;
                    } else {
                        if (pole[snakeOne.X - 1][snakeOne.Y] == 111) {
                            food--;
                            pole[snakeOne.X - 1][snakeOne.Y] = (char) 228;
                            snakeOne.X--;
                        } else {
                            snakeOne.X = xGame - 2;
                            tail1.erase(tail1.begin());
                            pole[snakeOne.X][snakeOne.Y] = (char) 228;
                        }
                    }


                } else { snakes[0] = 0; }
                break;
            case 2:
                if ((pole[snakeOne.X + 1][snakeOne.Y] == (char) 250 ||
                     pole[snakeOne.X + 1][snakeOne.Y] == (char) 111 || (goThrowWall &&
                                                                        (pole[snakeOne.X + 1][snakeOne.Y] ==
                                                                         (char) 186 ||
                                                                         pole[snakeOne.X + 1][snakeOne.Y] ==
                                                                         (char) 205 ||
                                                                         pole[snakeOne.X + 1][snakeOne.Y] ==
                                                                         (char) 201 ||
                                                                         pole[snakeOne.X + 1][snakeOne.Y] ==
                                                                         (char) 200 ||
                                                                         pole[snakeOne.X + 1][snakeOne.Y] ==
                                                                         (char) 187 ||
                                                                         pole[snakeOne.X + 1][snakeOne.Y] ==
                                                                         (char) 188))) && snakes[0] == 1 &&
                    !isTailOnField(snakeOne.X + 1, snakeOne.Y)) {
                    COORD newtail{snakeOne.X, snakeOne.Y};
                    tail1.push_back(newtail);
                    pole[snakeOne.X][snakeOne.Y] = (char) 250;
                    if (pole[snakeOne.X + 1][snakeOne.Y] == (char) 250) {
                        tail1.erase(tail1.begin());
                        pole[snakeOne.X + 1][snakeOne.Y] = (char) 228;
                        snakeOne.X++;
                    } else {
                        if (pole[snakeOne.X + 1][snakeOne.Y] == 111) {
                            food--;
                            pole[snakeOne.X + 1][snakeOne.Y] = (char) 228;
                            snakeOne.X++;
                        } else {
                            snakeOne.X = 1;
                            tail1.erase(tail1.begin());
                            pole[snakeOne.X][snakeOne.Y] = (char) 228;
                        }
                    }
                } else { snakes[0] = 0; }
                break;
            case 3:
                if ((pole[snakeOne.X][snakeOne.Y - 1] == (char) 250 ||
                     pole[snakeOne.X][snakeOne.Y - 1] == (char) 111 || (goThrowWall &&
                                                                        (pole[snakeOne.X][snakeOne.Y - 1] ==
                                                                         (char) 186 ||
                                                                         pole[snakeOne.X][snakeOne.Y - 1] ==
                                                                         (char) 205 ||
                                                                         pole[snakeOne.X][snakeOne.Y - 1] ==
                                                                         (char) 201 ||
                                                                         pole[snakeOne.X][snakeOne.Y - 1] ==
                                                                         (char) 200 ||
                                                                         pole[snakeOne.X][snakeOne.Y - 1] ==
                                                                         (char) 187 ||
                                                                         pole[snakeOne.X][snakeOne.Y - 1] ==
                                                                         (char) 188))) && snakes[0] == 1 &&
                    !isTailOnField(snakeOne.X, snakeOne.Y - 1)) {
                    COORD newtail{snakeOne.X, snakeOne.Y};
                    tail1.push_back(newtail);
                    pole[snakeOne.X][snakeOne.Y] = (char) 250;
                    if (pole[snakeOne.X][snakeOne.Y - 1] == (char) 250) {
                        tail1.erase(tail1.begin());
                        pole[snakeOne.X][snakeOne.Y - 1] = (char) 228;
                        snakeOne.Y--;
                    } else {
                        if (pole[snakeOne.X][snakeOne.Y - 1] == 111) {
                            food--;
                            pole[snakeOne.X][snakeOne.Y - 1] = (char) 228;
                            snakeOne.Y--;
                        } else {
                            snakeOne.Y = yGame - 2;
                            tail1.erase(tail1.begin());
                            pole[snakeOne.X][snakeOne.Y] = (char) 228;
                        }
                    }
                } else { snakes[0] = 0; }

                break;
            case 4:
                if ((pole[snakeOne.X][snakeOne.Y + 1] == (char) 250 ||
                     pole[snakeOne.X][snakeOne.Y + 1] == (char) 111 || (goThrowWall &&
                                                                        (pole[snakeOne.X][snakeOne.Y + 1] ==
                                                                         (char) 186 ||
                                                                         pole[snakeOne.X][snakeOne.Y + 1] ==
                                                                         (char) 205 ||
                                                                         pole[snakeOne.X][snakeOne.Y + 1] ==
                                                                         (char) 201 ||
                                                                         pole[snakeOne.X][snakeOne.Y + 1] ==
                                                                         (char) 200 ||
                                                                         pole[snakeOne.X][snakeOne.Y + 1] ==
                                                                         (char) 187 ||
                                                                         pole[snakeOne.X][snakeOne.Y + 1] ==
                                                                         (char) 188))) && snakes[0] == 1 &&
                    !isTailOnField(snakeOne.X, snakeOne.Y + 1)) {
                    COORD newtail{snakeOne.X, snakeOne.Y};
                    tail1.push_back(newtail);
                    pole[snakeOne.X][snakeOne.Y] = (char) 250;
                    if (pole[snakeOne.X][snakeOne.Y + 1] == (char) 250) {
                        tail1.erase(tail1.begin());
                        pole[snakeOne.X][snakeOne.Y + 1] = (char) 228;
                        snakeOne.Y++;
                    } else {
                        if (pole[snakeOne.X][snakeOne.Y + 1] == 111) {
                            food--;
                            pole[snakeOne.X][snakeOne.Y + 1] = (char) 228;
                            snakeOne.Y++;
                        } else {
                            snakeOne.Y = 1;
                            tail1.erase(tail1.begin());
                            pole[snakeOne.X][snakeOne.Y] = (char) 228;
                        }
                    }
                } else { snakes[0] = 0; }

                break;

        }
    }
    if (snake == 2) {
        switch (where) {
            case 1:
                if ((pole[snakeTwo.X - 1][snakeTwo.Y] == (char) 250 ||
                     pole[snakeTwo.X - 1][snakeTwo.Y] == (char) 111 || (goThrowWall &&
                                                                        (pole[snakeTwo.X - 1][snakeTwo.Y] ==
                                                                         (char) 186 ||
                                                                         pole[snakeTwo.X - 1][snakeTwo.Y] ==
                                                                         (char) 205 ||
                                                                         pole[snakeTwo.X - 1][snakeTwo.Y] ==
                                                                         (char) 201 ||
                                                                         pole[snakeTwo.X - 1][snakeTwo.Y] ==
                                                                         (char) 200 ||
                                                                         pole[snakeTwo.X - 1][snakeTwo.Y] ==
                                                                         (char) 187 ||
                                                                         pole[snakeTwo.X - 1][snakeTwo.Y] ==
                                                                         (char) 188))) && snakes[1] == 1 &&
                    !isTailOnField(snakeTwo.X - 1, snakeTwo.Y)) {
                    COORD newtail{snakeTwo.X, snakeTwo.Y};
                    tail2.push_back(newtail);
                    pole[snakeTwo.X][snakeTwo.Y] = (char) 250;
                    if (pole[snakeTwo.X - 1][snakeTwo.Y] == (char) 250) {
                        tail2.erase(tail2.begin());
                        pole[snakeTwo.X - 1][snakeTwo.Y] = (char) 253;
                        snakeTwo.X--;
                    } else {
                        if (pole[snakeTwo.X - 1][snakeTwo.Y] == 111) {
                            food--;
                            pole[snakeTwo.X - 1][snakeTwo.Y] = (char) 253;
                            snakeTwo.X--;
                        } else {
                            snakeTwo.X = xGame - 2;
                            tail2.erase(tail2.begin());
                            pole[snakeTwo.X][snakeTwo.Y] = (char) 253;
                        }
                    }


                } else { snakes[1] = 0; }
                break;
            case 2:
                if ((pole[snakeTwo.X + 1][snakeTwo.Y] == (char) 250 ||
                     pole[snakeTwo.X + 1][snakeTwo.Y] == (char) 111 || (goThrowWall &&
                                                                        (pole[snakeTwo.X + 1][snakeTwo.Y] ==
                                                                         (char) 186 ||
                                                                         pole[snakeTwo.X + 1][snakeTwo.Y] ==
                                                                         (char) 205 ||
                                                                         pole[snakeTwo.X + 1][snakeTwo.Y] ==
                                                                         (char) 201 ||
                                                                         pole[snakeTwo.X + 1][snakeTwo.Y] ==
                                                                         (char) 200 ||
                                                                         pole[snakeTwo.X + 1][snakeTwo.Y] ==
                                                                         (char) 187 ||
                                                                         pole[snakeTwo.X + 1][snakeTwo.Y] ==
                                                                         (char) 188))) && snakes[1] == 1 &&
                    !isTailOnField(snakeTwo.X + 1, snakeTwo.Y)) {
                    COORD newtail{snakeTwo.X, snakeTwo.Y};
                    tail2.push_back(newtail);
                    pole[snakeTwo.X][snakeTwo.Y] = (char) 250;
                    if (pole[snakeTwo.X + 1][snakeTwo.Y] == (char) 250) {
                        tail2.erase(tail2.begin());
                        pole[snakeTwo.X + 1][snakeTwo.Y] = (char) 253;
                        snakeTwo.X++;
                    } else {
                        if (pole[snakeTwo.X + 1][snakeTwo.Y] == 111) {
                            food--;
                            pole[snakeTwo.X + 1][snakeTwo.Y] = (char) 253;
                            snakeTwo.X++;
                        } else {
                            snakeTwo.X = 1;
                            tail2.erase(tail2.begin());
                            pole[snakeTwo.X][snakeTwo.Y] = (char) 253;
                        }
                    }
                } else { snakes[1] = 0; }
                break;
            case 3:
                if ((pole[snakeTwo.X][snakeTwo.Y - 1] == (char) 250 ||
                     pole[snakeTwo.X][snakeTwo.Y - 1] == (char) 111 || (goThrowWall &&
                                                                        (pole[snakeTwo.X][snakeTwo.Y - 1] ==
                                                                         (char) 186 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y - 1] ==
                                                                         (char) 205 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y - 1] ==
                                                                         (char) 201 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y - 1] ==
                                                                         (char) 200 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y - 1] ==
                                                                         (char) 187 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y - 1] ==
                                                                         (char) 188))) && snakes[1] == 1 &&
                    !isTailOnField(snakeTwo.X, snakeTwo.Y - 1)) {
                    COORD newtail{snakeTwo.X, snakeTwo.Y};
                    tail2.push_back(newtail);
                    pole[snakeTwo.X][snakeTwo.Y] = (char) 250;
                    if (pole[snakeTwo.X][snakeTwo.Y - 1] == (char) 250) {
                        tail2.erase(tail2.begin());
                        pole[snakeTwo.X][snakeTwo.Y - 1] = (char) 253;
                        snakeTwo.Y--;
                    } else {
                        if (pole[snakeTwo.X][snakeTwo.Y - 1] == 111) {
                            food--;
                            pole[snakeTwo.X][snakeTwo.Y - 1] = (char) 253;
                            snakeTwo.Y--;
                        } else {
                            snakeTwo.Y = yGame - 2;
                            tail2.erase(tail2.begin());
                            pole[snakeTwo.X][snakeTwo.Y] = (char) 253;
                        }
                    }
                } else { snakes[1] = 0; }

                break;
            case 4:
                if ((pole[snakeTwo.X][snakeTwo.Y + 1] == (char) 250 ||
                     pole[snakeTwo.X][snakeTwo.Y + 1] == (char) 111 || (goThrowWall &&
                                                                        (pole[snakeTwo.X][snakeTwo.Y + 1] ==
                                                                         (char) 186 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y + 1] ==
                                                                         (char) 205 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y + 1] ==
                                                                         (char) 201 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y + 1] ==
                                                                         (char) 200 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y + 1] ==
                                                                         (char) 187 ||
                                                                         pole[snakeTwo.X][snakeTwo.Y + 1] ==
                                                                         (char) 188))) && snakes[1] == 1 &&
                    !isTailOnField(snakeTwo.X, snakeTwo.Y + 1)) {
                    COORD newtail{snakeTwo.X, snakeTwo.Y};
                    tail2.push_back(newtail);
                    pole[snakeTwo.X][snakeTwo.Y] = (char) 250;
                    if (pole[snakeTwo.X][snakeTwo.Y + 1] == (char) 250) {
                        tail2.erase(tail2.begin());
                        pole[snakeTwo.X][snakeTwo.Y + 1] = (char) 253;
                        snakeTwo.Y++;
                    } else {
                        if (pole[snakeTwo.X][snakeTwo.Y + 1] == 111) {
                            food--;
                            pole[snakeTwo.X][snakeTwo.Y + 1] = (char) 253;
                            snakeTwo.Y++;
                        } else {
                            snakeTwo.Y = 1;
                            tail2.erase(tail2.begin());
                            pole[snakeTwo.X][snakeTwo.Y] = (char) 253;
                        }
                    }
                } else { snakes[1] = 0; }

                break;

        }
    }

    while (food < 4 && spaceLeft()) {

        tx = rand() % (xGame - 2) + 1;
        ty = rand() % (yGame - 2) + 1;
        if (pole[tx][ty] == (char) 250 && !isTailOnField(tx, ty)) {
            pole[tx][ty] = (char) 111;
            food++;
        }
    }
    if (!spaceLeft() && food == 0) {
        gameWin();
    }
    if (snakes[0] == 0 && snakes[1] == 0) {
        gameOver();
    }
}

//253 228
void game() {
    while (walls != 4 || food != 4 || snakes[0] != 1 || snakes[1] != 1) {
        if (walls < 4) {
            tx = rand() % (xGame - 2) + 1;
            ty = rand() % (yGame - 2) + 1;
            if (pole[tx][ty] == (char) 250) {
                pole[tx][ty] = (char) 219;
                walls++;
            }
        }
        if (food < 4) {
            tx = rand() % (xGame - 2) + 1;
            ty = rand() % (yGame - 2) + 1;
            if (pole[tx][ty] == (char) 250) {
                pole[tx][ty] = (char) 111;
                food++;
            }
        }
        if (snakes[0] == 0) {
            tx = rand() % (xGame - 2) + 1;
            ty = rand() % (yGame - 2) + 1;
            if (pole[tx][ty] == (char) 250) {
                pole[tx][ty] = (char) 253;
                snakes[0] = 1;
            }
        }
        if (snakes[1] == 0) {
            tx = rand() % (xGame - 2) + 1;
            ty = rand() % (yGame - 2) + 1;
            if (pole[tx][ty] == (char) 250) {
                pole[tx][ty] = (char) 228;
                snakes[1] = 1;
            }
        }
    }
    for (int i = 0; i < xGame; i++) {
        for (int j = 0; j < yGame; j++) {
            if (pole[i][j] == (char) 228) {
                snakeOne.X = i;
                snakeOne.Y = j;
            } else {
                if (pole[i][j] == (char) 253) {
                    snakeTwo.X = i;
                    snakeTwo.Y = j;
                }
            }
        }
    }
    printPole();
    cout<<endl<< "§¬¥©ª  1 " << (char) 228 <<"- WASD ";if(snakes[0] == 1){cout << "†¨¢ ";}else{cout << "Œ¥àâ¢ ";}
    cout<<endl;
    cout<<endl<< "§¬¥©ª  2 " << (char) 253 <<"- ‘âà¥«®çª¨";if(snakes[1] == 1){cout << "†¨¢ ";}else{cout << "Œ¥àâ¢ ";}
    cout<<endl;
    while (true) {
        char btn;

        btn = btn_take();
        switch (btn) {
            case 72://up 2
                move(2, 1);
                break;
            case 80://down 2
                move(2, 2);
                break;
            case 75://left 2
                move(2, 3);
                break;
            case 77://right 2
                move(2, 4);
                break;
            case 119://up 1
                move(1, 1);
                break;
            case 115://down 1
                move(1, 2);
                break;
            case 97://left 1
                move(1, 3);
                break;
            case 100://right 1
                move(1, 4);
                break;
            case 27:
                cout<<"‚ëå®¤";
                sleep(3);
                exit(1);

        }
        printPole();
        cout<<endl<< "§¬¥©ª  1 " << (char) 228 <<"- WASD ";if(snakes[0] == 1){cout << "(†¨¢ )";}else{cout << "(Œ¥àâ¢ )";}
        cout<<endl;
        cout<<endl<< "§¬¥©ª  2 " << (char) 253 <<"- ‘âà¥«®çª¨ ";if(snakes[1] == 1){cout << "(†¨¢ )";}else{cout << "(Œ¥àâ¢ )";}
        cout<<endl;
    }


}

int wallsSet() {
    int btn = 0;
    int x = 1, y = 1;
    while (true) {
        printPoleWCurs(xGame, yGame, x, y);
        switch (btn_take()) {
            case 72://up
                if (x > 1) { x--; };
                break;
            case 80://down
                if (x < xGame - 2) { x++; };
                break;
            case 77://right
                if (y < yGame - 2) { y++; };

                break;
            case 75://left
                if (y > 1) { y--; };

                break;
            case 13:
                if (pole[x][y] == (char) 219) {
                    pole[x][y] = (char) 250;
                    walls--;
                } else {
                    if (pole[x][y] == (char) 250 && walls < 4) {
                        pole[x][y] = (char) 219;
                        walls++;
                    }
                }
                break;
            case 27:
                return 0;
        }
    }
}

int foodSet() {
    int btn = 0;
    int x = 1, y = 1;
    while (true) {
        printPoleWCurs(xGame, yGame, x, y);
        switch (btn_take()) {
            case 72://up
                if (x > 1) { x--; };
                break;
            case 80://down
                if (x < xGame - 2) { x++; };
                break;
            case 77://right
                if (y < yGame - 2) { y++; };

                break;
            case 75://left
                if (y > 1) { y--; };

                break;
            case 13:
                if (pole[x][y] == (char) 111) {
                    pole[x][y] = (char) 250;
                    food--;
                } else {
                    if (pole[x][y] == (char) 250 && food < 4) {
                        pole[x][y] = (char) 111;
                        food++;
                    }
                }


                break;
            case 27:
                return 0;
        }
    }
}

int snakeSet() {
    int btn = 0;
    int x = 1, y = 1;
    while (true) {
        printPoleWCurs(xGame, yGame, x, y);
        switch (btn_take()) {
            case 72://up
                if (x > 1) { x--; };
                break;
            case 80://down
                if (x < xGame - 2) { x++; };
                break;
            case 77://right
                if (y < yGame - 2) { y++; };

                break;
            case 75://left
                if (y > 1) { y--; };

                break;
            case 13:
                //253 228
                if ((snakes[0] == 0 || snakes[1] == 0) && pole[x][y] == (char) 250) {
                    if (snakes[0] == 0) {
                        pole[x][y] = (char) 253;
                        snakes[0] = 1;
                    } else {
                        snakes[1] = 1;
                        pole[x][y] = (char) 228;
                    }
                } else {
                    if (pole[x][y] == (char) 253) {
                        pole[x][y] = (char) 250;
                        snakes[0] = 0;

                    }
                    if (pole[x][y] == (char) 228) {
                        pole[x][y] = (char) 250;
                        snakes[1] = 0;
                    }
                }
                break;
            case 27:
                return 0;
        }
    }
}

void printMenu(int point) {

    system("cls");
    for (int j = 0; j < 9; j++) {
        cout << menu_str[j];
        if (j == point) { cout << " <--" << endl; }
        else { cout << endl; }
    }

}

int work(int point) {
    printMenu(point);
    switch (point) {
        case 0:
            wallsSet();
            break;
        case 1:
            foodSet();
            break;
        case 2:
            snakeSet();
            break;
        case 3:
            goThrowWall = !goThrowWall;
            if (goThrowWall) {
                cout << "‚ª«îç¥­®" << endl;
            } else {
                cout << "‚ëª«îç¥­®" << endl;
            }
            break;
        case 4:
            game();
            break;
        case 5:
            cout<<"‚ëå®¤";
            sleep(3);
            exit(1);


    }
    cout << " ¦¬¨â¥ «î¡ãî ª« ¢¨èã...";
    getch();
    return 0;
}

int menu() {

    int menuPoint = 0;
    int btn = 0;
    while (true) {
        printMenu(menuPoint);
        btn = btn_take();
        switch (btn) {
            case 72:
                if (menuPoint == 0) {
                    menuPoint = 5;
                } else {
                    menuPoint--;
                }
                break;
            case 80:
                if (menuPoint == 5) {
                    menuPoint = 0;
                } else {
                    menuPoint++;
                }
                break;
            case 27:
                cout << "‚ëå®¤";
                return 1;
            case 13:
                work(menuPoint) ;
                break;
            case 49:
                menuPoint = 0;
                if (work(menuPoint) == 1) { return 1; };
                break;
            case 50:
                menuPoint = 1;
                if (work(menuPoint) == 1) { return 1; };
                break;
            case 51:
                menuPoint = 2;
                if (work(menuPoint) == 1) { return 1; };
                break;
            case 52:
                menuPoint = 3;
                if (work(menuPoint) == 1) { return 1; };
                break;
            case 53:
                menuPoint = 4;
                if (work(menuPoint) == 1) { return 1; };
                break;
            case 48:
                menuPoint = 5;
                if (work(menuPoint) == 1) { return 1; };
                return 0;
        }
    }
}

int main() {
    cout << "‚¢¥¤¨â¥ à §¬¥àë ¯®«ï"<<endl;

    for (int it = 0; it < 22; it++) {
        for (int iy = 0; iy < 22; iy++) {
            pole[it][iy] = (char) 250;
        }
    }
    do {
        cout << "‚¢¥¤¨â¥ ç¨á«® ®â 6 ¤® 20: ";
        xGame = intInput();
        if (xGame < 6 || xGame > 20) {
            cout << "¥¢¥à­®¥ ç¨á«®! ®¢â®à¨â¥ ¢¢®¤." << endl;
        }
    } while (xGame < 6 || xGame > 20);
    do {
        cout << "‚¢¥¤¨â¥ ç¨á«® ®â 6 ¤® 20: ";
        yGame = intInput();
        if (yGame < 6 || yGame > 20) {
            cout << "¥¢¥à­®¥ ç¨á«®! ®¢â®à¨â¥ ¢¢®¤." << endl;
        }
    } while (yGame < 6 || yGame > 20);
    xGame += 2;
    yGame += 2;

    for (int i = 0; i < yGame; i++) {
        pole[i][0] = (char) 186;
        pole[i][xGame - 1] = (char) 186;
    }

    for (int i = 1; i < xGame - 1; i++) {
        pole[0][i] = (char) 205;
        pole[yGame - 1][i] = (char) 205;
    }
    pole[0][0] = (char) 201;
    pole[yGame - 1][0] = (char) 200;
    pole[0][xGame - 1] = (char) 187;
    pole[yGame - 1][xGame - 1] = (char) 188;
    menu();
    //186 205 201 200 187 188
    sleep(7);
    return 0;
}
