#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

double sequence(double prev, double pprev,
double q, double r, double b){
    return q * prev + r *pprev + b;
}

void writeToFile(const string &filename, int n,
double q = 1.0, double r = 1.0, double b = 0.0, double c = 1.0, double d = 1.0){
    ofstream out(filename);
    double x0 = c, x1 = d;
    out << x0 << "\n" << x1<<"\n";
    for(int i = 2; i < n; i++){
        double x = sequence(x1, x0, q, r, b);
        out << x << "\n";
        x0 = x1;
        x1 = x;
    }  
}

int main(){
    writeToFile("output_seq.txt", 200);
}