#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

double * create(int n);
void print(double *x, int n);
double *createLayer(double *x, int n, int& nL);

int main(){
    int n=21, nL;
    double *x = create(n); 
    int numLayers = ceil(log2(n)) + 1;   // v = 2.1; floor(v)=2 , ceil(v)=3
    double **pyramid = new double*[numLayers]; //создаем массив указателей
    // массив = адрес первого элемента, каждый элемент имеет тип (double*)
    // соответственно указатель на элемент имеет тип double **
    int *sizes = new int[numLayers];
    pyramid[0] = x; // в основании пирамиды исходный массив
    sizes[0] = n;
    print(x, n);
    for(int i =1; i<numLayers; i++){ // создаем каждый следующий слой
        double *layer = createLayer(pyramid[i-1], sizes[i-1], nL);
        print(layer, nL);
        pyramid[i] = layer;
        sizes[i] = nL;
    }
    for(int i=0; i<numLayers; i++){
        delete[] pyramid[i];
    }
    delete[]pyramid;
}

double *createLayer(double *x, int n, int& nL){
    /*создаем слой, в котором из каждой пары элементов
массива x[n]  выбираем наименьший. В новом слое nL элементов.*/
    nL = n / 2 + n % 2; // (n+1)/2
    double *layer = new double[nL];
    for(int i=0; i<nL; i++){
        int leftIndex = i * 2;
        int rightIndex = leftIndex + 1;
        if (rightIndex < n){ // у элемента layer[i] есть оба потомка
            layer[i] = min(x[leftIndex], x[rightIndex]);
        }
        else layer[i] = x[leftIndex];
    }
    return layer;

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


