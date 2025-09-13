#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iostream> // cout, cin, cerr

using namespace std;

int main(){
    srand(time(NULL));    
    double x, y;
    {
        int N = 1000;
        ofstream output("points.txt");
        for(int i=0; i<N; i++){
            x = rand() * 10.0 / RAND_MAX;
            y = rand() * 30.0 / RAND_MAX;
            output << x << "\t" << y << endl;
        }
    }
    {
        ifstream input("points.txt");
        ofstream output("res.txt");
        int count = 0, countIn = 0;
        for(;input >> x >> y;count++){   // while(input >> x >> y)
            if (5 * sin(x) - x + 20 > y){
                output << x << "\t" << y << "\tIn"<< endl;
                countIn++;
            }
            else{
                output << x << "\t" << y << "\tOut"<< endl;
            }
        }
        cout << "S = " << 300.0 * countIn / count << endl;
    }
    {
        int N = 10000000;
        int countIn = 0;
        for(int i = 0;i < N; i++){ 
            x = rand() * 10.0 / RAND_MAX;
            y = rand() * 30.0 / RAND_MAX;
            if (5 * sin(x) - x + 20 > y){                
                countIn++;
            }            
        }
        cout << "S = " << 300.0 * countIn / N << endl;
    }
    {
        // трехмерный вариант
        // z = 10 - x ^2 - y ^2
        // z = 0
        // x = y
        // x = 0
        // z = -x+1
        int N = 100000;
        int countIn = 0;
        for(int i=0; i<N; i++){
            x = rand() * 4.0 /RAND_MAX;
            y = rand() * 4.0 /RAND_MAX;  
            double z = rand() * 10.0 / RAND_MAX;
            if (z < 10 - x * x - y * y && (z > 0 || z > -x + 1)
            && (y < x))    countIn++;           
        }
        cout << "V = " << 160.0 * countIn / N << endl;
    }   



}