#include <iostream>
#include <conio.h>
#include "windows.h"
#include <cmath>

using namespace std;

string menu[8] = {"1.������ 1 �᫮", "2.������ 2 �᫮", "3.�㬬�", "4.���������", "5.�������", "6.���⠭��",
                  "7.���������� � �⥯���(a  � �⥯��� c)", "8.��室"};

void str1(int qwe) {

    system("cls");
    for (int j = 0; j < 8; j++) {
        cout << menu[j];
        if (j == qwe) { cout << " <--" << endl; }
        else { cout << endl; }
    }

}

int q() {
    int userInput;
    while (!(cin >> userInput) || userInput < -2147483648 || userInput > 2147483648 || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "�� �� 񦨪 - ���� 㬥���. ����� �᫮ ��ଠ�쭮�" << endl;
    }
    cout << "�� �����: " << userInput << endl;

    return userInput;
}


int main() {
    long long int qwe = 0, w1, a, b;
    while (true) {
        str1(qwe);
        char c;
        c = getch();
        switch ((int) c) {
            case 27:
                cout << "��室";
                Sleep(3000);
                return 0;
            case 72:
                if (qwe == 0) { qwe = 7; }
                else { qwe = qwe - 1; }
                break;
            case 80:
                if (qwe == 7) { qwe = 0; }
                else { qwe = qwe + 1; }
                break;
            case 49:
                qwe = 0;
                goto switcher;
            case 50:
                qwe = 1;
                goto switcher;
            case 51:
                qwe = 2;
                goto switcher;
            case 52:
                qwe = 3;
                goto switcher;
            case 53:
                qwe = 4;
                goto switcher;
            case 54:
                qwe = 5;
                goto switcher;
            case 55:
                qwe = 6;
                goto switcher;
            case 56:
                qwe = 7;
                goto switcher;

            case 13:
            switcher:
                str1(qwe);
                switch (qwe) {
                    case 0:
                        cout << "������ �᫮ 1" << endl;
                        a = q();
                        system("pause");
                        break;
                    case 1:
                        cout << "������ �᫮ 2" << endl;
                        b = q();
                        system("pause");
                        break;
                    case 2:
                        cout << "a=" << a << " b=" << b << endl;
                        cout << "a+b=";
                        w1 = a + b;
                        cout << w1 << endl;
                        system("pause");
                        break;
                    case 3:
                        cout << "a=" << a << " b=" << b << endl;
                        cout << "a*b=";
                        w1 = a * b;
                        cout << w1 << endl;
                        system("pause");
                        break;
                    case 4:
                        cout << "a=" << a << " b=" << b << endl;
                        cout << "a/b=";
                        float w;
                        w = float(a) / float(b);
                        cout << w << endl;
                        system("pause");
                        break;
                    case 5:
                        cout << "a=" << a << " b=" << b << endl;
                        cout << "a-b=";
                        w1 = a - b;
                        cout << w1 << endl;
                        system("pause");
                        break;
                    case 6:
                        cout << "a=" << a << " b=" << b << endl;
                        if (pow(a, b) == numeric_limits<double>::infinity()) {
                            cout << "���������� �������\n";
                        } else {
                            cout << "a � �⥯��� b = ";
                            cout << pow(a, b) << endl;
                        }
                        system("pause");
                        break;
                    case 7:
                        cout << "�����";
                        Sleep(3000);
                        return 0;

                }
        }
    }

}