#include <stdlib.h>
#include <math.h>
#include <iostream>


using namespace std;

bool qwe(unsigned int i);


int main() {
    locale::global(locale(""));
    unsigned int mass[1725] = {1, 2, 3, 5, 7}, end = 1, asd, i = 0, aryi = 5, maxi = 429496729, count = 5, paus = 5;
    bool flag = true;
    cout << "1\n2\n3\n5\n7\n";
    while (end != 0) {
        for (i; mass[i] != 0; i++) {
            flag = true;
            
            for (asd = 1; asd < 10; asd += 2) {
                if (qwe(mass[i] * 10 + asd) && (mass[i] < maxi)) {
                    mass[aryi] = mass[i] * 10 + asd;
                    aryi++;
                    count++;

                    paus++;
                    cout << mass[i] * 10 + asd << "\n";
                    flag = false;
                    if (paus == 20) {
                        system("Pause");
                        paus = 0;
                        system("cls");
                    }
                }
            }
        }
        if (flag) { end = 0; }
    }
    cout << "Количество гиперпростых чисел: " << count << endl;
    system("Pause");
}


bool qwe(unsigned int i) {
    if (i == 2) { return true; }
    int h = (int) sqrt(i), k = 0;
    for (int j = 2; j <= h; j++) {
        if (i % j == 0) { return false; }
    }
    return true;
}

