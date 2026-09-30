#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

void calculation(){
    double d = 0.5;
    double *pDouble = &d;

    double d1 = 1.5;
    pDouble = &d1;
    double S = 0.0;
    for(int i=0; i<10; i++){
        double x = i * 0.1;
        if (i % 2 == 0){
            pDouble = &x;
        }else{
            pDouble = &d1;
        }
        *pDouble += i;
        S += x;
    }
    cout << d1 << " " << S << endl;
}

void memoryPrint(){
    // есть переменная простого числового типа
    // (double, float, long, ...)
    // Надо вывести на экран ее представление в памяти
    // в hex формате

    double value = 20;
    double *pValue = &value;
    // совместили два указателя, они указывают на одну область
    // памяти
    unsigned char *p = reinterpret_cast<unsigned char*>(pValue);
    // проходим по каждому байту (прямой порядок)
    for(int i=0; i< sizeof(double); i++){
        // по адресу p смотрим на значение
        *p = 10;
        cout <<setw(2) <<setfill('0') << hex << static_cast<int>(*p) << " ";
        // переводим указатель p на следующую компоненту
        // то есть к текущему адресу p добавляем
        // sizeof (unsigned char) = 1 байт
        p++;
    }
    cout << endl;
    p = reinterpret_cast<unsigned char*>(pValue) + sizeof(double) - 1;
    // проходим по каждому байту (обратный порядок)
    for(int i=0; i< sizeof(double); i++){
        // по адресу p смотрим на значение

        cout <<setw(2) <<setfill('0') << hex << static_cast<int>(*p) << " ";
        // переводим указатель p на предыдущую компоненту
        // то есть от текущего адреса p отнимаем
        // sizeof (unsigned char) = 1 байт
        p--;
    }
    cout << endl;
}

void references(){
    // ссылки = "оболочка" для указателя
    // ссылка = альтернативное имя объекта
    // чтобы определить ссылку на объект
    // надо указать тип объекта и символ &
    // в момент объявления ссылка должна быть инициализирована
    double value = 20; // объект
    {
        double &nameOfValue = value; // даем переменной (объекту)
        // value альтернативное (другое) имя
        // ...
        nameOfValue += 1;
    }
    {
        double &anotherName = value; // еще одно имя value
        double a = 1;
        anotherName = a;

    }
}

// Механизмы передачи параметров в функцию
// - по значению (выделяются ресурсы для хранения каждого объекта
// по значению), значение копируется из аргумента
// - по адресу (низкоуровневая передача) - будем использовать
// для массивов в стиле С (динамические массивы), ресурсы занимаются
// под хранениеадреса, копируется адрес объектов
// - по ссылке - в функции передаваемому объекту
// назначается альтернативное имя

// Задача: определить цифры некоторого целого числа
// 23452467 -> 2, 3, 4, 5, 2, 4, 6, 7
// Входная информация: число в формате long
// Выходная информация: массив цифр + количество цифр
// Главный результат: массив цифр типа [char] = char *

// Объявление функции
// тип_рез-та имя_функции (перечисление параметров с их типами)
char * getDigits(long value, // по значению
                 char &numDigits) // по ссылке
{
    cout << "Адрес numDigits " << reinterpret_cast<void *>(&numDigits) << endl;
    cout << "Адрес value " << reinterpret_cast<void *>(&value) << endl;
    numDigits = 0;
    for(long temp = abs(value);temp > 0; temp /= 10, numDigits++);
    cout << numDigits << "\n";
    if (!numDigits){
        numDigits = 1;
    }
    // знаем количество цифр -> создаем массив с numDigits элементов
    char * res = new char[numDigits]; // выделяем память по numDigits байт
    // заносим цифры в массив
    for (int i = numDigits - 1; i > -1; --i, value /= 10) { // i - номер цифры
        res[i] = value % 10;
    }
    return res;
    // return nullptr; // константа = нулевой адрес = ничего не возвращаем
        // 23452 4 6 7
}

// сумма элементов массива
int sum(const char * a, // массив = адрес первого элемента -> по адресу передаем параметр
        int n) // количество элементов передаем по значению
{
    int s = 0;
    for(int i=0; i<n; i++){
        s += a[i];
    }
    return s;
}

void print(const char* title, const char *a, int n){
    cout << title << ":\n";
    for(int i=0; i<n; i++){
        cout << static_cast<int>(a[i]) << " ";
        //cout << (char)(digits[i] + '0') << " ";
    }
}


int main(){
    // вызов функции
    char num;
    long value = 563278;
    cout << "Адрес num " << reinterpret_cast<void *>(&num) << endl;
    cout << "Адрес value " << reinterpret_cast<void *>(&value) << endl;
    char * digits = getDigits(value, num);
    print("цифры числа", digits, num);
    cout << endl;
    // Определить сумму цифр числа
    cout << "Сумма цифр массива: " << sum(digits, num)<< endl;

    print("Коды букв", "абвг", 4);

    return 0;

}

//
