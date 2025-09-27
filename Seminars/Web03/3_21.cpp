#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

double writeToFileIterations(const string &filename, int n,
 double x = 1.0, double eps=1.0e-10){
    ofstream out(filename);
      
    double a_prev = 0.25 * x * x; 
    double S = a_prev;

    out << a_prev << "\n";
    double x2, k1;
    for(double k = 1;abs(a_prev) > eps && k <= n; k++){
        x2 = 0.5 * x;
        k1 = k + 1;
        double a_cur = (-1.0) / (k1 * k1) * x2 *x2 * a_prev;
        out << a_cur << "\n";
        S += a_cur; 
        a_prev = a_cur;       
    }  
    return S;
}

int main(){
    int n = 500;
    // double eps = 1.0e-10;
    clock_t t1 = clock();    
    t1 = clock();
    double S = writeToFileIterations("output_321.txt", n);
    double S1 = writeToFileIterations("output_321_1.txt", n, 1.0, 1.0e-7);
    clock_t t2 = clock();
    cout <<"Время выполнения: " << t2 - t1 << endl;
    cout << "Сумма элементов (1): " <<fixed << setprecision(15)<< S << endl;
    cout << "Сумма элементов (2): " <<fixed << setprecision(15)<< S1 << endl;
}