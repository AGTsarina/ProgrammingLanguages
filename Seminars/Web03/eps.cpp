#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int main(){
    // машинное eps: наименьшее значение eps
    // при котором выполняется условие 1 + eps > 1
    double d = 1.0;
    float f = 1.0f;
    cout << "Double:\n";
    while(1.0 + d > 1.0){
        cout << d << endl;
        d /= 2.0;
    }

    cout << "Float:\n";
    while(1.0f + f > 1.0f){
        cout << f << endl;
        f /= 2.0f;
    }

    double y = sin(0.5);
    double z = exp(3.5);
    double t = pow(0.5, 7);

}