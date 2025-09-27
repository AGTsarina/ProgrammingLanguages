#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

double f(int n){
    double res = 1;
    // 1 * 2 * 3 * 4 * ... * (n-1) * n
    for(int i=2; i <= n; i++){
        res *= i;
    }
    return res;
}

double a(double x, int n){
    return x / (sqrt(n) * f(n + 2));
}

void writeToFile(const string &filename, int n, double x = 1.0){
    //ofstream out(filename);    
    for(int i = 1; i <= n; i++){
        double res = a(x, i);
    //    out << res << "\n";        
    }  
}

void writeToFileIterations(const string &filename, int n, double x = 1.0){
    //ofstream out(filename);   
    double a_prev = a(x, 1); 
    //out << a_prev << "\n";
    for(double k = 2; k <= n; k++){
        double res = sqrt((k - 1.0) / k) / (k + 2) * a_prev;
    //    out << res << "\n"; 
        a_prev = res;       
    }  
}

int main(){
    int n = 20000;
    clock_t t1 = clock();
    writeToFile("output_412.txt", n);
    clock_t t2 = clock();
    cout <<"Метод №1 " << t2 - t1 << endl;
    t1 = clock();
    writeToFileIterations("output_412_1.txt", n);
    t2 = clock();
    cout <<"Метод №2 " << t2 - t1 << endl;
}