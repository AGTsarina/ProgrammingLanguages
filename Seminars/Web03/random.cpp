#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;
// генератор вещественных чисел от a до b
double random(double a, double b){
    return rand() * (b - a) / RAND_MAX + a;
}
// функция записи в файл случайных чисел
void writeToFile(const string& filename, int n=100, double a=0.0, double b=1.0){
    ofstream out(filename);    
    for(int i=0; i<n; i++){
        double x = random(a, b);
        out <<fixed<<setw(7) << setprecision(2)<< x << " ";
    }
}

// функция записи в файл случайных чисел
void writeToFile(ofstream& out, int n, double a, double b){        
    for(int i=0; i<n; i++){
        double x = random(a, b);
        out <<fixed<<setw(7) << setprecision(2)<< x << "\n";
    }
}

int main(){
    int n = 10;
    double a = -10.0, b = 10.0;
    writeToFile("output.txt");
    ofstream out("another_output.txt");
    writeToFile(out, n, a, b);
    writeToFile(out, n, 0, 2);
    writeToFile(out, n, -1.0, 1.0);
    writeToFile(out, n, 0.0, b - a);
}