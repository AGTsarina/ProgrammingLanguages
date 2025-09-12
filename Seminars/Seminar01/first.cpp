#include <iostream> // библиотека С++ для работы
                    // со стандартными потоками
#include <cmath>   // библиотека С++ математических функций
#include <math.h> // *.h = header
#include <fstream>

using namespace std;

int main(){
    float f1 = 14.125, f2 = 14.7;
    int a = 125, b = -150;
    short y = -150;
    char x = 125;
    
    char * px = &x; // адрес переменой x в оперативной памяти (ОП)
                    // px указатель на переменную x
    short *py = &y; // адрес переменой y в оперативной памяти (ОП)
                    // py указатель на переменную y
                    
    std::ofstream output("memory.bin", std::ios::binary);
    output.write(px, 100);

    if (1.0 / 3.0 == sqrt(27 * 27) * sqrt(1.0 / (81.0 * 81.0))){
        std::cout <<"Равны\n";
    }
    else{
        std::cout <<"Не равны\n";
    }
    cout << (int) x << endl;
    cin >> x;

    bool flag = true;
    bool not_flag = false;
    if(x){

    }
    
    return 0;
}