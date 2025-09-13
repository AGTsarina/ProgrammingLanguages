#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

// 1. Определить количество цифр в числе
// 2. Среди цифр числа найти максимальное
// 3. Найти знакопеременную сумму цифр числа
// 4. Определить, выстроены ли цифры числа по возрастанию

int main(){
    long n;
    ifstream in("input.txt");
    while(in >> n){
        // 1. Определить количество цифр в числе
        long m = n;
        int ndigits = 0;
        for(;m > 0; m/=10, ndigits++);
        cout << "Количество цифр в числе "<< n << " = " << ndigits<< endl;
        // 2. Среди цифр числа найти максимальное
        m = n;
        int max = 0;
        for(;m > 0; m/=10)
            if (m % 10 > max) max = m % 10;
        cout << "Максимальная цифра: " << max << endl;
        // 3. Найти знакопеременную сумму цифр числа
        int sum = 0;
        char sign = 1;
        for(m = n;m > 0; m/=10, sign *= -1){
            sum += m % 10 * sign;
        }
        if (ndigits % 2 == 0) sum *= -1;
        cout << "Знакопеременная сумма цифр: " << sum << endl;
        // 4. Определить, выстроены ли цифры числа по возрастанию
        int d = n % 10;
        bool flag = true;
        for(m = n / 10; m > 0; m /= 10){
            if (m % 10 >= d){
                flag = false;
                break;
            }
            else d = m % 10;
        }
        if (flag) cout << "Да\n"; else cout << "Нет\n";
        cout << (flag? "Да\n": "Нет\n");
    }
}
