#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <limits>
#include "string.h"

using namespace std;
struct timer{
    long long int tm_sec = 0;
    long long int tm_min = 0;
    long long int tm_hour = 0;
    long long int tm_mday = 0;
    long long int tm_mon = 0;
    long long int tm_year = 0;
};
struct timer time1;
struct timer time2;

struct timer date1;
struct timer date2;


int t1, t2, t3;
int monthCode[] = {1,4,4,0,2,5,0,3,6,1,4,6};
char dayOfWeekAr[7][4] = {"Sat","Sun","Mon","Tue","Wed","Thu","Fri"};

int intInput() {
    int userInput;
    while (!(cin >> userInput) || userInput < -2147483648 || userInput > 2147483647 || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ты не ёжик - читать умеешь. Введи число нормальное" << endl;
    }
    cout << "Вы ввели: " << userInput << endl;

    return userInput;
}
const int monthDays[12] = { 31, 59, 90, 120, 151, 181, 212, 243,
                            273, 304, 334, 365
};
long long int countLeapYearDays(timer *date)
{
    long long int years = date->tm_year;
    if (date->tm_mon-1 <= 2)
        years--;
    return ( (years / 4) - (years / 100) + (years / 400) );
}
long long int countNoOfDays(timer *date11, timer *date22)
{
    long long int dayCount1 = (date11->tm_year * 365);
    dayCount1 += monthDays[date11->tm_mon - 1];
    dayCount1 += date11->tm_mday;
    dayCount1 += countLeapYearDays(date11);
    long long int dayCount2 = (date22->tm_year * 365);
    dayCount2 += monthDays[date22->tm_mon - 1];
    dayCount2 += date22->tm_mday;
    dayCount2 += countLeapYearDays(date22);
    return ( dayCount1 - dayCount2 );
}
bool leapYear(int year) {

    if ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0) { return true; } else { return false; }
}

void fixTime(timer *date) {
    bool day_good = false;
    int leapinYear;
    if (date->tm_mon == 0)
    {
        date->tm_mon++;
    }
    while (date->tm_sec > 59) {
        date->tm_sec -= 60;
        date->tm_min += 1;
    }
    while (date->tm_min > 59) {
        date->tm_min -= 60;
        date->tm_hour += 1;
    }

    while (!day_good) {
        while (date->tm_mon > 12) {
            date->tm_mon -= 12;
            date->tm_year += 1;
        }
        if (date->tm_mon == 1 || date->tm_mon == 3 || date->tm_mon == 5 || date->tm_mon == 7 || date->tm_mon == 8 ||
            date->tm_mon == 10|| date->tm_mon == 12) {
            if (date->tm_mday > 30) {
                date->tm_mday -= 31;
                date->tm_mon += 1;
            } else {
                day_good = true;
            }
        }
        if (date->tm_mon == 4 || date->tm_mon == 6 || date->tm_mon == 9 || date->tm_mon == 11 ) {
            if (date->tm_mday > 29) {
                date->tm_mday -= 30;
                date->tm_mon += 1;
            } else {
                day_good = true;
            }
        }
        if (date->tm_mon == 2) {
            leapinYear = int(leapYear(date->tm_year));
            if (date->tm_mday > (27 + leapinYear)) {
                date->tm_mday -= 28 + leapinYear;
                date->tm_mon += 1;
            } else {
                day_good = true;
            }
        }
        if(date->tm_mon == 0){day_good = true;}
    }
    while (date->tm_mon > 12) {
        date->tm_mon -= 12;
        date->tm_year += 1;
    }
    if (date->tm_mday == 0){
        date->tm_mday++;
    }

}

int btn_take() {
    int btn;
    btn = getch();
    return btn;
}

string menu_str[] = {"1. Ввод  1-го времени",
                     "2. Ввод  2-го времени",
                     "3. Ввод  1-й  даты",
                     "4. Ввод  2-й  даты",
                     "5. Время1 + время2",
                     "6. Время1 - время2",
                     "7. Дата1  + дата2",
                     "8. Дата1  - дата2",
                     "9. Выход"};

void printMenu(int point) {

    system("cls");
    for (int j = 0; j < 9; j++) {
        cout << menu_str[j];
        if (j == point) { cout << " <--" << endl; }
        else { cout << endl; }
    }

}

int dayOfWeek(timer *date){
    int day;
    day = (date->tm_mday + monthCode[date->tm_mon - 1] + ((6 + date->tm_year % 100 + date->tm_year % 100 / 4) % 7)) % 7;
    if(leapYear(date->tm_year) && date->tm_mon <= 2)
        day++;
    return day;
}

int work(int point) {
    printMenu(point);
    long long int sec1;
    long long int sec2;
    long long int sec3;
    long long int days3;
    struct timer time3;
    struct timer date3;
    switch (point) {
        case 0:
            cout << "Введите час";
            t1 = intInput();
            cout << "Введите минуты";
            t2 = intInput();
            cout << "Введите секунды";
            t3 = intInput();
            time1.tm_hour = t1;
            time1.tm_min = t2;
            time1.tm_sec = t3;
            time1.tm_year = 0;
            time1.tm_mon = 0;
            time1.tm_mday = 0;
            fixTime(&time1);
            break;
        case 1:
            cout << "Введите час";
            t1 = intInput();
            cout << "Введите минуты";
            t2 = intInput();
            cout << "Введите секунды";
            t3 = intInput();
            time2.tm_hour = t1;
            time2.tm_min = t2;
            time2.tm_sec = t3;
            time2.tm_year = 0;
            time2.tm_mon = 0;
            time2.tm_mday = 0;
            fixTime(&time2);
            break;
        case 2:
            cout << "Введите год";
            t1 = intInput();
            cout << "Введите месяц";
            t2 = intInput();
            cout << "Введите день";
            t3 = intInput();
            date1.tm_year = t1;
            date1.tm_mon = t2;
            date1.tm_mday = t3;
            date1.tm_hour = 0;
            date1.tm_min = 0;
            date1.tm_sec = 0;
            fixTime(&date1);
            break;
        case 3:
            cout << "Введите год";
            t1 = intInput();
            cout << "Введите месяц";
            t2 = intInput();
            cout << "Введите день";
            t3 = intInput();
            date2.tm_year = t1;
            date2.tm_mon = t2;
            date2.tm_mday = t3;
            date2.tm_hour = 0;
            date2.tm_min = 0;
            date2.tm_sec = 0;
            fixTime(&date2);
            break;
        case 4:
            time3 = time1;
            cout << "время1+время2\n";
            time3.tm_hour += time2.tm_hour;
            time3.tm_min += time2.tm_min;
            time3.tm_sec += time2.tm_sec;
            fixTime(&time3);
            printf("%02lld:%02lld:%02lld", time3.tm_hour, time3.tm_min, time3.tm_sec);
            break;
        case 5:
            cout << "время1-время2\n";
            sec1 = time1.tm_sec + time1.tm_min * 60 + time1.tm_hour * 3600;
            sec2 = time2.tm_sec + time2.tm_min * 60 + time2.tm_hour * 3600;
            sec3 = sec1 - sec2;
            time3.tm_sec = abs(sec3);
            fixTime(&time3);
            if (sec3 >= 0) {cout<< "  " ;}else{cout<< "- " ;}
            printf("%02lld:%02lld:%02lld", time3.tm_hour, time3.tm_min, time3.tm_sec);
            break;
        case 6:
            date3 = date1;
            cout << "дата1+дата2\n";
            date3.tm_year += date2.tm_year;
            date3.tm_mon += date2.tm_mon;
            date3.tm_mday += date2.tm_mday;
            fixTime(&date3);
            printf("%02lld-%02lld-%04lld ", date3.tm_mday, date3.tm_mon, date3.tm_year);
            cout<<dayOfWeekAr[dayOfWeek(&date3)]<<endl;
            break;
        case 7:
            cout << "дата1-дата2\n";
            days3 = countNoOfDays(&date1,&date2);
            date3.tm_mday = abs(days3);
            fixTime(&date3);
            if (days3 >= 0) {cout<< "  " ;}else{cout<< "- " ;}
            printf("%02lld-%02lld-%04lld ", date3.tm_mday, date3.tm_mon, date3.tm_year);
            cout<<dayOfWeekAr[dayOfWeek(&date3)]<<endl;
            break;
        case 8:
            return 1;
    }
    cout <<endl<< "Нажмите любую клавишу...";
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
                    menuPoint = 8;
                } else {
                    menuPoint--;
                }
                break;
            case 80:
                if (menuPoint == 8) {
                    menuPoint = 0;
                } else {
                    menuPoint++;
                }
                break;
            case 27:
                cout << "Выход";
                return 0;
            case 13:
                work(menuPoint);
                break;
            case 49:
                menuPoint = 0;
                work(menuPoint);
                break;
            case 50:
                menuPoint = 1;
                work(menuPoint);
                break;
            case 51:
                menuPoint = 2;
                work(menuPoint);
                break;
            case 52:
                menuPoint = 3;
                work(menuPoint);
                break;
            case 53:
                menuPoint = 4;
                work(menuPoint);
                break;
            case 54:
                menuPoint = 5;
                work(menuPoint);
                break;
            case 55:
                menuPoint = 6;
                work(menuPoint);
                break;
            case 56:
                menuPoint = 7;
                work(menuPoint);
                break;
            case 57:
                menuPoint = 8;
                work(menuPoint);
                break;
        }
    }

}

int main() {
    menu();
    sleep(7);
    return 0;
}

