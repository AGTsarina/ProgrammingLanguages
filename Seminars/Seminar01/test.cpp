#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    unsigned int ui = 256+176+2; // rand() % 1000 + 100;
    int pi = 3 * 256+160 + 13; // rand() % 1000 + 100
    int ni = -(2 * 256 + 13 * 16 + 3); //-(rand() % 1000 + 100);
    float f =1.0/4.0 + 1.0/16.0; //rand() * 2.0 / RAND_MAX - 1.0;

    unsigned char * p; // переменная, в которую можно записать 
    // ардес в памяти любой другой переменной.
    // Если переменная имеет другой тип данных,
    // то требуется преобрадование типов указателей

    // 1. unsigned int ui
    p = reinterpret_cast<unsigned char*>(&f);
    for(int i=3; i>-1; i--){
        cout << hex <<setw(2) << setfill('0') << (int)p[i] <<" "; 
    }
    cout << endl;
    ofstream output("res.bin", ios::binary);
    output.write(reinterpret_cast<char*>(&f), 100);
    return 0;
}