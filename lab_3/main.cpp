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
        cout << "Ты не ёжик - читать умеешь. ВВеди число нормальное" << endl;
    }
    cout << "Вы ввели: " << userInput << endl;

    return userInput;
}



int main() {
    long long int q1, q2, w1, w2;
    int input;
    while (true) {
        cout << "1.введите 1 число" << endl << "2.введите 2 число" << endl << "3.Сумма" << endl << "4.Произведение"
             << endl << "5.Выход" << endl;
        cout << "Введите число от 1 до 5: ";
        input = q();

        system("cls");
        cout << "1.введите 1 число" << endl << "2.введите 2 число" << endl << "3.Сумма" << endl << "4.Произведение"
             << endl << "5.Выход" << endl;
        switch (input) {
            case 1:
                cout << "1 число=";
                q1 = q();
                break;
            case 2:
                cout << "2 число=";
                q2 = q();
                break;
            case 3:
                w2 = q1 + q2;
                cout << "a+b=" << w2;
                cout << endl << "1 число=" << q1 << "; 2 число=" << q2 << endl;
                break;
            case 4:
                w1 = q1 * q2;
                cout << "a*b=" << w1;
                cout << endl << "1 число=" << q1 << "; 2 число=" << q2 << endl;
                break;
            case 5:
                cout << "ВЫХОД";
                Sleep(3000);
                return 0;
            default:
                cout << "Ты не ёжик - читать умеешь. ВВеди число от 1 до 5" << endl;
                break;
        }

        char c;
        cout << "Нажмите любую клавишу...";
        c = getch();

        system("cls");

    }
}
