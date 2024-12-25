#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

string menu[11] = {"0.Введите 1 число(от 1 до 20)", "1.Введите 2 число(от 1 до 20)", "2.По часовой внутрь",
                   "3.Против часовой внутрь",
                   "4.Против часовой наружу", "5.По часовой наружу",
                   "6.Открыть файл со спиралью(итоговый вывод) txt", "7.Открыть файл со спиралью(итоговый вывод) bin",
                   "8.Открытие файла для редактирования txt", "9.Открытие файла для редактирования  bin",
                   "q.Выход"};
int m, n, n1, m1;

void savef(int **spiral) {
    string filename = "spiral.txt";
    // Открытие файла для записи
    ofstream file(filename);
    file << m << " " << n << " ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { file << spiral[i][j] << " "; }
    }
    // Закрытие файла
    file.close();
}

void savefbin(int **spiral) {
    // Открытие файла в режиме двоичной записи
    ofstream outputFile("spiralb.bin", ios::binary);

    outputFile.write(reinterpret_cast<char *>(&m), sizeof(m));
    outputFile.write(reinterpret_cast<char *>(&n), sizeof(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { outputFile.write(reinterpret_cast<char *>(&spiral[i][j]), sizeof(spiral[i][j])); }
    }
    // Закрытие файла
    outputFile.close();
}

void openfbin() {
    // Открытие файла в режиме двоичного чтения
    ifstream inputFile("spiralb.bin", ios::binary);
    int number;
    int spiral1[n1][m1];
    inputFile.read(reinterpret_cast<char *>(&m1), sizeof(m1));
    inputFile.read(reinterpret_cast<char *>(&n1), sizeof(n1));
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            inputFile.read(reinterpret_cast<char *>(&number), sizeof(number));
            spiral1[i][j] = number;
            cout << setw(4) << spiral1[i][j];
        }
        cout << endl;
    }
    // Проверка на ошибки чтения
    if (inputFile.eof()) {
        cout << endl; // Вывод новой строки после последнего числа
    } else {
        cerr << " " << endl;
    }
    // Закройте файл
    inputFile.close();
}

void openf() {
    // !F.eof();
    fstream F;
    F.open("spiral.txt");
    if (F.is_open()) {
        F >> m1 >> n1; // Считываем первые два числа
        int spiral[n1][m1];
        int num;
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m1; ++j) {
                F >> num;
                spiral[i][j] = num;
                cout << setw(4) << spiral[i][j];
            }
            cout << endl;
        }
    } else {
        cout << " Файл не существует" << endl;
    }
}

int changesf() {
    int x = 0, y = 0, a;
    fstream F;

    F.open("spiral.txt");
        F >> m1 >> n1; // Считываем первые два числа
        int num;
    int spiral[n1][m1];
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m1; ++j) {
                F >> num;
                spiral[i][j] = num;
                cout << setw(4) << spiral[i][j];
            }
            cout << endl;
        }
    while (true) {
        system("cls");
        cout << "Enter - Изменить(максимум 3 символа) и сохранить, esc-вернуться в главное меню\n";
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                if (i == x && j == y) {
                    cout << (char) 3;
                } else {
                    cout << setw(4) << spiral[i][j];}
                }
                cout << endl;
            }
            switch (_getch()) {
                case 72://up
                    if (x > 0) { x--; }
                    break;
                case 80://down
                    if (x < n1-1) { x++; }
                    break;
                case 77://right
                    if (y < m1-1) { y++; }
                    break;
                case 75://left
                    if (y > 0) { y--; }
                    break;
                case 27:
                    return 0;
            case 13:
                cout<<"введите новое число(максимум 3 символа)"<<endl;
                    while (!(cin >> a) || a < 0 || a > 999 || cin.peek() != '\n') {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ты не ёжик - читать умеешь. ВВеди число нормальное" << endl;
                    }
                spiral[x][y]=a;
                    string filename = "spiral.txt";
                    // Открытие файла для записи
                    ofstream file(filename);
                    file << m << " " << n << " ";
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) { file << spiral[i][j] << " "; }
                    }
                    // Закрытие файла
                    file.close();

            }
        }

    }

int changesfbin(){
    int x = 0, y = 0, a;
    ifstream inputFile("spiralb.bin", ios::binary);
    int number;
    int spiral1[n1][m1];
    inputFile.read(reinterpret_cast<char *>(&m1), sizeof(m1));
    inputFile.read(reinterpret_cast<char *>(&n1), sizeof(n1));
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            inputFile.read(reinterpret_cast<char *>(&number), sizeof(number));
            spiral1[i][j] = number;
            cout << setw(4) << spiral1[i][j];
        }
        cout << endl;
    }
    // Проверка на ошибки чтения
    if (inputFile.eof()) {
        cout << endl; // Вывод новой строки после последнего числа
    } else {
        cerr << " " << endl;
    }
    // Закройте файл
    inputFile.close();
    while (true) {
        system("cls");
        cout << "Enter - Изменить(максимум 3 символа) и сохранить, esc-вернуться в главное меню\n";
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                if (i == x && j == y) {
                    cout << (char) 3;
                } else {
                    cout << setw(4) << spiral1[i][j];}
            }
            cout << endl;
        }
        switch (_getch()) {
            case 72://up
                if (x > 0) { x--; }
                break;
            case 80://down
                if (x < n1-1) { x++; }
                break;
            case 77://right
                if (y < m1-1) { y++; }
                break;
            case 75://left
                if (y > 0) { y--; }
                break;
            case 27:
                return 0;
            case 13:
                cout<<"введите новое число(максимум 3 символа)"<<endl;
                while (!(cin >> a) || a < 0 || a > 999 || cin.peek() != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ты не ёжик - читать умеешь. ВВеди число нормальное" << endl;
                }
                spiral1[x][y]=a;
                ofstream outputFile("spiralb.bin", ios::binary);

                outputFile.write(reinterpret_cast<char *>(&m1), sizeof(m1));
                outputFile.write(reinterpret_cast<char *>(&n1), sizeof(n1));
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) { outputFile.write(reinterpret_cast<char *>(&spiral1[i][j]), sizeof(spiral1[i][j])); }
                }
                // Закрытие файла
                outputFile.close();

        }
    }

}

void spiral3(int m, int n) {

    int **spiral = new int *[n];
    for (int i = 0; i < n; i++) {
        spiral[i] = new int[m];
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++)
            spiral[x][y] = 0;
    }
    int start = 1;
    int minRow = 0, maxRow = n - 1, minCol = 0, maxCol = m - 1;

    while (start <= m * n) {
        Sleep(1);
        // Заполняем верхнюю строку слева направо
        for (int i = minCol; i <= maxCol; ++i)
            if (spiral[minRow][i] == 0) { spiral[minRow][i] = start++; }
        ++minRow;

        // Заполняем правый столбец сверху вниз
        for (int i = minRow; i <= maxRow; ++i)
            if (spiral[i][maxCol] == 0) {
                spiral[i][maxCol] = start++;
            }
        --maxCol;

        // Заполняем нижнюю строку справа налево
        for (int i = maxCol; i >= minCol; --i)
            if (spiral[maxRow][i] == 0) { spiral[maxRow][i] = start++; }
        --maxRow;

        // Заполняем левый столбец снизу вверх
        for (int i = maxRow; i >= minRow; --i)
            if (spiral[i][minCol] == 0) { spiral[i][minCol] = start++; }
        ++minCol;
    }

    // Вывод спирали
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(4) << spiral[i][j];
        }
        cout << endl;
    }
    savef(spiral);
    savefbin(spiral);

}

void spiral4(int m, int n) {
    int **spiral = new int *[n];
    for (int i = 0; i < n; i++) {
        spiral[i] = new int[m];
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++)
            spiral[x][y] = 0;
    }

    int start = 1;
    int minRow = 0, maxRow = n - 1, minCol = 0, maxCol = m - 1;

    while (start <= m * n) {
        // Заполняем верхнюю строку справа налево
        for (int i = maxCol; i >= minCol; --i)
            if (spiral[minRow][i] == 0) { spiral[minRow][i] = start++; }
        ++minRow;

        // Заполняем левый столбец сверху вниз
        for (int i = minRow; i <= maxRow; ++i)
            if (spiral[i][minCol] == 0) { spiral[i][minCol] = start++; }
        ++minCol;
        // Заполняем нижнюю строку слева направо
        for (int i = minCol; i <= maxCol; ++i)
            if (spiral[maxRow][i] == 0) { spiral[maxRow][i] = start++; }
        --maxRow;

        // Заполняем Правый столбец снизу вверх
        for (int i = maxRow; i >= minRow; --i)
            if (spiral[i][maxCol] == 0) { spiral[i][maxCol] = start++; }
        --maxCol;
    }
    // Вывод спирали
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(4) << spiral[i][j];
        }
        cout << endl;
    }

    savef(spiral);
    savefbin(spiral);
}

void spiral5(int m, int n) {
    int **spiral = new int *[n];
    for (int i = 0; i < n; i++) {
        spiral[i] = new int[m];
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++)
            spiral[x][y] = 0;
    }
    int start = m * n;
    int minRow = 0, maxRow = n - 1, minCol = 0, maxCol = m - 1;

    while (start >= 1) {
        // Заполняем верхнюю строку справа налево
        for (int i = maxCol; i >= minCol; --i)
            if (spiral[minRow][i] == 0) { spiral[minRow][i] = start--; }
        ++minRow;

        // Заполняем левый столбец сверху вниз
        for (int i = minRow; i <= maxRow; ++i)
            if (spiral[i][minCol] == 0) { spiral[i][minCol] = start--; }
        ++minCol;

        // Заполняем нижнюю строку слева направо
        for (int i = minCol; i <= maxCol; ++i)
            if (spiral[maxRow][i] == 0) { spiral[maxRow][i] = start--; }
        --maxRow;

        // Заполняем правый столбец снизу вверх
        for (int i = maxRow; i >= minRow; --i)
            if (spiral[i][maxCol] == 0) { spiral[i][maxCol] = start--; }
        --maxCol;
    }

    // Вывод спирали
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(4) << spiral[i][j];
        }
        cout << endl;
    }
    savef(spiral);
    savefbin(spiral);
}

void spiral6(int m, int n) {
    int **spiral = new int *[n];
    for (int i = 0; i < n; i++) {
        spiral[i] = new int[m];
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++)
            spiral[x][y] = 0;
    }
    int start = m * n;
    int minRow = 0, maxRow = n - 1, minCol = 0, maxCol = m - 1;

    while (start >= 1) {
        Sleep(1);
        // Заполняем верхнюю строку слева направо
        for (int i = minCol; i <= maxCol; ++i)
            if (spiral[minRow][i] == 0) { spiral[minRow][i] = start--; }
        ++minRow;

        // Заполняем правый столбец сверху вниз
        for (int i = minRow; i <= maxRow; ++i)
            if (spiral[i][maxCol] == 0) { spiral[i][maxCol] = start--; }
        --maxCol;

        // Заполняем нижнюю строку справа налево
        for (int i = maxCol; i >= minCol; --i)
            if (spiral[maxRow][i] == 0) { spiral[maxRow][i] = start--; }
        --maxRow;

        // Заполняем левый столбец снизу вверх
        for (int i = maxRow; i >= minRow; --i)
            if (spiral[i][minCol] == 0) { spiral[i][minCol] = start--; }
        ++minCol;
    }

    // Вывод спирали
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(4) << spiral[i][j];
        }
        cout << endl;
    }
    savef(spiral);
    savefbin(spiral);

}

int q() {
    int userInput;
    while (!(cin >> userInput) || userInput < 1 || userInput > 20 || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ты не ёжик - читать умеешь. ВВеди число нормальное" << endl;
    }
    cout << "Вы ввели: " << userInput << endl;

    return userInput;
}

void str1(int qwe) {

    system("cls");
    for (int j = 0; j < 11; j++) {
        cout << menu[j];
        if (j == qwe) { cout << " <--" << endl; }
        else { cout << endl; }
    }

};

int main() {
    int qwe = 0;
    while (true) {
        str1(qwe);
        char c;
        c = getch();
        switch ((int) c) {
            case 27:
                cout << "Выход";
                Sleep(3000);
                return 0;
            case 72:
                if (qwe == 0) { qwe = 10; }
                else { qwe = qwe - 1; };
                break;
            case 80:
                if (qwe == 10) { qwe = 0; }
                else { qwe = qwe + 1; };
                break;
            case 48:
                qwe = 0;
                goto switcher;
            case 49:
                qwe = 1;
                goto switcher;
            case 50:
                qwe = 2;
                goto switcher;
            case 51:
                qwe = 3;
                goto switcher;
            case 52:
                qwe = 4;
                goto switcher;
            case 53:
                qwe = 5;
                goto switcher;
            case 54:
                qwe = 6;
                goto switcher;
            case 55:
                qwe = 7;
                goto switcher;
            case 56:
                qwe = 8;
                goto switcher;
            case 57:
                qwe = 9;
                goto switcher;
            case 113:
                qwe = 10; //выход
                goto switcher;

            case 13:
            switcher:
                str1(qwe);
                switch (qwe) {
                    case 0:
                        cout << "Введите число 1" << endl;
                        m = q();
                        system("pause");
                        break;
                    case 1:
                        cout << "Введите число 2" << endl;
                        n = q();
                        system("pause");
                        break;
                    case 2:
                        spiral3(m, n);
                        system("pause");
                        break;
                    case 3:
                        spiral4(m, n);
                        system("pause");
                        break;
                    case 4:
                        spiral5(m, n);
                        system("pause");
                        break;
                    case 5:
                        spiral6(m, n);
                        system("pause");
                        break;
                    case 6:
                        openf();
                        system("pause");
                        break;
                    case 7:
                        openfbin();
                        system("pause");
                        break;
                    case 8:
                        changesf();
                        system("pause");
                        break;
                    case 9:
                        changesfbin();
                        system("pause");
                        break;
                    case 10:
                        cout << "ВЫХОД";
                        Sleep(3000);
                        return 0;

                }
        }
    }
}