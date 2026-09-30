// Работа с вещественными числами,
// точность представления
#include <cmath>
int main(){
    double a = 1.0;
    // машинное эпсилон: eps  + 1 = 1
    while (a + 1 > 1){
        a /= 2.0;
    }
    // сравнение
    double a1 = 1.0 / 3.0;
    double a2 = (float)pow(pow (a1, 77.0), 1.0/77.0);
    bool res = fabs(a1 - a2) < 1e-08;
    return 0;
}
