#include <vector>
using namespace std;

long f(long n){
    if (n < 2) return 1;
    return n * f(n - 1);
}

long fib(long n, vector<long> &mem){
    // f0 = f1 = 1; fk = fk-1 + fk-2
    long f_1, f_2;
    if (mem[n-1]) f_1 = mem[n - 1]; else {f_1 = fib(n-1, mem); mem[n-1] = f_1;}
    if (mem[n-2]) f_2 = mem[n - 2]; else {f_2 = fib(n-2, mem); mem[n-2] = f_2;}
    mem[n] = f_1 + f_2;
    return f_1 + f_2;
    // res = f(state_prev) + f(state_prev_prev);
}

int main(){
    int n = 7;
    vector<long> mem(n + 1);
    mem[0] = mem[1] = 1;
    long res = fib(n, mem);
    return 0;
}