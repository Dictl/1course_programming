#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <iomanip>

using namespace std;

string menu[9] = {"1.������ M", "2.������ N", "3.�����", "4.�⥭��", "5.����⠢��� ���", "6.��ᯮ������� ������ 1",
                 "7.��ᯮ������� ������ 2","8.����� ����", "!!! �⮡� �४���� ���� ������ ESC"};

int limit() {
    int userInput;
    while (!(cin >> userInput) || userInput < 6 || userInput > 20 || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "�� �� 񦨪 - ���� 㬥���. ����� �᫮ ��ଠ�쭮�" << endl;
    }
    cout << "�� �����: " << userInput << endl;

    return userInput;
}

void str1(int qwe) {

    system("cls");
    for (int j = 0; j < 9; j++) {
        cout << menu[j];
        if (j == qwe) { cout << " <--" << endl; }
        else { cout << endl; }
    }

};

int main() {
 int qwe=0;
    while (true) {
        str1(qwe);
        char c;
        c = getch();
        switch ((int) c){
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
            case 13:
            switcher:
                str1(qwe);
                switch (qwe) {
                    case 0:

                    case 1:

                    case 2:

                    case 3:

                    case 4:

                    case 5:

                    case 6:

                    case 7:

        }
    }

}






/*#include <iostream>
void drawSquare(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                std::cout << '-';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}*/

/*int main() {
    // ��ᮢ���� ������� ������ � ���᮫�
    int size = 8;  // ������ ������

    drawSquare(size);
    system("Pause");
    return 0;

}*/