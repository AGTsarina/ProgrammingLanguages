#include <cstdio> // ввод/вывод на С
#include <iostream> // ввод/вывод на С++
using namespace std;

int main(){
    // ввод/вывод на С
    int a = 1, b = 2;
    double c = 0.5;
    printf("Output: %d %d %lf", a, b, c);
    //scanf("%d%d%lf", &a, &b, &c);
    printf("\nOutput: %d %d %lf\n", a, b, c);

    // C++
    //cin >> a >> b >> c;
    cout << "C++ Output: a = " << a
         << " b = " <<b << " c = " << c << "\n"; // endl
}
