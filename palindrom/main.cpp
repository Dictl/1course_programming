#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char input[9000], reversed[9000];
    int end, maxi = 0, count = 0, flag = 1;
    for (int i = 0; i < 9000; i++) input[i] = -1;
    cout << "Введите строку до 70-ти символов:\n";
    cin.getline(input, sizeof(input));
    for (int i = 0; input[i] != -1; i++)
        if (input[i + 1] == -1) end = i - 1;
    if (end > 70)
    {
        cout << "Введена строка слишком большого размера, а именно:" << end;
        return 0;
    }
    for (int i = 0; i <= end; i++)
    {
        for (int j = end; j > i; j--)
        {
            if (input[i] == input[j])
                for (int k = i, l = j; l > k; k++, l--)
                {
                    if ((k + l) % 2 == 0) break;
                    if (input[k] == input[l]) count++;
                    else if (input[k] != input[l])
                    {
                        flag = 0; count = 0;
                        break;
                    }
                }
            else  flag = 0;
            maxi = max(count, maxi);
            if (flag == 1 && maxi == count)
            {
                for (int m = 0; m < count; m++)
                    reversed[m] = input[i + m];
            }
            maxi = max(count, maxi); count = 0;  flag = 1;
        }
    }
    if (maxi < 1)
        cout << "В данной строке нет палиндромов";
    else
    {
        cout << "Количество символов в самом длинном палиндроме: " << maxi << endl;
        cout << "Самый длинный палиндром:";
        for (int i = 0; i < maxi; i++) cout << reversed[i];
    }
    cout << endl;
    system("Pause");
}