#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int part(double *x, int L, int R){
    int m = (L+R)/ 2;
    double p = x[m]; // значение, относительно которого делим массив на
    // две подпоследовательности a[i] < p и a[j] >= p
    int i = L, j = R;
    while(i < j){
        // !!! Изменены границы поиска
        // ищем элемент слева, который больше чем опорный (нарушает порядок)
        for(;i <= R && x[i] < p; i++);
        // ищем элемент справа, который меньше чем опорный (нарушает порядок)
        for(; j >= L && x[j] > p; j--);
        // меняем местами, если i < j
        if (i <= j){
            double temp = x[i]; x[i] = x[j]; x[j] = temp;
            i++;
            j--;
        }

    }
    // !!! Изменено определение границы разделения
    return x[i] > p? i: min(i+1, R);
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

void quickSort(double *x, int L, int R){
    if (L >= R) return;
    int i = part(x, L, R);
    // cout << "Index i "<< i << "[ " << L << ", " << R << "]" << endl;
    // print(x, 10);
    quickSort(x, L, i-1);
    quickSort(x, i, R);
}

void quickSort(double *x, int n){
    quickSort(x, 0, n-1);
}

// !!! Добавлена проверка на упорядоченность
bool ascending(double * x, int n){
    for(int i=0, j =1; j < n; i++, j++){
        if (x[i] > x[j]) return false;
    }
    return true;
}




int main(){
    srand(time(NULL));
    int n = 100;
    double * x = create(n);
    //double x[]{92, 92, 92, 92, 2, 92, 1, 92, 92, 92}; // тестовая последовательность
    print(x, n);
    quickSort(x, 0, n-1);
    print(x, n);
    cout << boolalpha << ascending(x, n);
}
