#include <iostream>
#include <windows.h>
#include <limits>
#include <conio.h>

using namespace std;

int q() {
    int userInput;
    while (!(cin >> userInput) || userInput < -2147483648 || userInput > 2147483648) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "�� �� 񦨪 - ���� 㬥���. ����� �᫮ ��ଠ�쭮�" << endl;
    }
    cout << "�� �����: " << userInput << endl;

    return userInput;
}



int main() {
    long long int q1, q2, w1, w2;
    int input;
    while (true) {
        cout << "1.������ 1 �᫮" << endl << "2.������ 2 �᫮" << endl << "3.�㬬�" << endl << "4.�ந��������"
             << endl << "5.��室" << endl;
        cout << "������ �᫮ �� 1 �� 5: ";
        input = q();

        system("cls");
        cout << "1.������ 1 �᫮" << endl << "2.������ 2 �᫮" << endl << "3.�㬬�" << endl << "4.�ந��������"
             << endl << "5.��室" << endl;
        switch (input) {
            case 1:
                cout << "1 �᫮=";
                q1 = q();
                break;
            case 2:
                cout << "2 �᫮=";
                q2 = q();
                break;
            case 3:
                w2 = q1 + q2;
                cout << "a+b=" << w2;
                cout << endl << "1 �᫮=" << q1 << "; 2 �᫮=" << q2 << endl;
                break;
            case 4:
                w1 = q1 * q2;
                cout << "a*b=" << w1;
                cout << endl << "1 �᫮=" << q1 << "; 2 �᫮=" << q2 << endl;
                break;
            case 5:
                cout << "�����";
                Sleep(3000);
                return 0;
            default:
                cout << "�� �� 񦨪 - ���� 㬥���. ����� �᫮ �� 1 �� 5" << endl;
                break;
        }

        char c;
        cout << "������ ���� �������...";
        c = getch();

        system("cls");

    }
}
