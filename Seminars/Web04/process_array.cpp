#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Создание массива (чтение из файла)
// результат - массив => указатель на первый элемент массива
int * readFromFile(const string &filename, int &n){
    ifstream in(filename);
    in >> n; // считываем кол-во элементов
    int * res = new int [n]; // cоздаем массив из n элементов
    for(int i=0; i<n; i++){
        in >> res[i];
    }
    return res;
}
// вычисление среднего значения
double mean(int * A, int n){
    double res = 0;
    for(int i=0; i<n; i++){
        res += A[i];
    }
    return res / n;
}
// содержит ли массив возрастающую последовательность
bool isGrowing(int *A, int n){
    for(int i=1; i<n; i++){
        if (A[i-1] >= A[i]) return false;
    }
    return true;
}

// добавить в массив из n элементов элемент x. (Расширяем массив, в нем в результате будет n + 1 элемент)
// Новый массив возвращаем как результат, старый массив остается
int *add(int *A, int n, int x){
    int *res = new int[n + 1];
    for(int i=0; i<n; i++){
        res[i] = A[i];
    }
    res[n] = x;
    return res;
}

// добавить в массив из n элементов элемент x. (Расширяем массив, в нем в результате будет n + 1 элемент)
// функция меняет переданный массив на новый и меняет количество элементов
void addLast(int * &A, int &n, int x){    
    int *res = new int[n + 1];
    for(int i=0; i<n; i++){
        res[i] = A[i];
    }
    res[n] = x;
    n++;
    delete[]A;
    A = res;    
}

int main(){
    int n = 0;
    int * A = readFromFile("input.txt", n);
    cout <<"Mean = " << mean(A, n) << endl;
    delete [] A;
    A = readFromFile("in.txt", n);
    cout <<"Mean = " << mean(A, n) << endl;
    int B[10]{1,2,3,4,5,9,7,8,9,10};
    cout <<"Mean = " << mean(B, sizeof(B) / sizeof(int)) << endl;
    cout << "Размер массива статического " << sizeof(B) << endl;
    cout << "Размер указателя на целое, который показывает на массив в динамической памяти " << sizeof(A) << endl;
    cout << boolalpha << isGrowing(A, n) << " " << isGrowing(B, 10) << endl;
    int *C = add(A, n, 100);
    addLast(A, n, 50);
    cout <<"Mean = " << mean(A, n) << endl;
    delete[]A;
    return 0;
}