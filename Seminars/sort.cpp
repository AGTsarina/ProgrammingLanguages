#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// определяем функциональный тип для работы с массивами
// любая функция, не возвращающая значение и имеющая
// два параметра типа double *, int будет относится к этому типу
typedef void (*arrayFunction)(double * x, int n);

void sortBubble(double *x, int n){
    bool flag = true; // предполагаем, что последовательность не упорядочена
    for(int i=1; flag && i<n; i++){ // количество проходов по массиву n - 1
        flag = false; // предполагаем, что элементы упорядочены, не будет обменов
        for(int j=0; j < n - i; j++){
            if (x[j] > x[j+1]){
                double temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
                flag = true; // произошел обмен
            }
        }
    }
}

void sortSelect(double *x, int n){  // сигнатура = набор параметров и
    // тип возвращаемого значения, которые определяют тип фукции
    for(int i=0; i<n-1;i++){
        double min = x[i];
        int imin = i;
        for(int j=i+1; j<n; j++){  // поиск минимального элемента
            if(x[j] < min){
                min = x[j]; imin = j;
            }
        }
        // меняем местами минимальный и i-ый
        x[imin] = x[i];
        x[i] = min;
    }
}

void sortInsert(double *x, int n){
    for(int i=1; i<n; i++){ // i - начало неупорядоченной последовательности
        double temp = x[i];
        int j = i-1;
        for(; j > -1 && x[j] > temp; j--){
            x[j+1] = x[j];
        }
        x[j+1] = temp;
    }
}



double * create(int n){
    double* res = new double[n];
    for(int i=0; i<n; i++){
        res[i] = rand() % 100 + 1;
    }
    return res;
}
void print(double *x, int n){
    cout << "\n============================\n";
    for(int i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << "\n\n";
}

int main(){
    srand(time(NULL));
     int n = 10000;
    // собираем методы сортировки в единый массив, который называется
    // methods
    arrayFunction methods[3] {sortSelect, sortBubble, sortInsert};
    for(; n < 1000000; n *=10){
        for(int i=0; i<3; i++){ // перебираем методы сортировки
        double * x = create(n);
        //print(x, n);
        auto f = methods[i]; // f - текущий метод сортироки
        clock_t t1 = clock();
        f(x, n); // вызов метода
        clock_t t2 = clock();
        cout << "Sort " << i + 1 << ": " << t2 - t1 << endl;
        //print(x, n);
        delete [] x;
        }
    }
}

