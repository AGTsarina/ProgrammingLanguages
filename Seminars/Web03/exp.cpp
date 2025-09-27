#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;


double Exp(double x, int &N, double eps = 1.0e-10){
    double y = x >= 0? x: -x;
    double S = 1.0;
    double a = 1.0;
    N = 0;
    for(double k = 1;k < 100 && abs(a) > eps; k++, N++){
        a *= y / k;
        S += a;
    }
    return x >= 0? S: 1.0 / S;
}

int main(){
    for(double x = 0; x > -30; x -= 0.5){
        int K;
        cout << setprecision(20) << x << "\t" << Exp(x, K) << "\t" << exp(x) ;
        cout << "\t"<< K <<endl;
    }
}