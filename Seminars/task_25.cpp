#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int main(){
    ifstream input("/home/u614/tsarina/firstApp/input");
    int n(0), k=1;
    input >> n;
    double s = 0.0;
    for(int i=0; i<n; i++){
        double a;
        input >> a;
        s += a;
        cout << cos(a) << " ";

    }
    cout <<"Среднее арифметическое " << s / n << endl;
    return 0;
}
