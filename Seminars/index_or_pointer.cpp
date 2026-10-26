#include<cstdlib>

double rnd(double a, double b){
    return a + rand()*(b-a) / RAND_MAX;
}

// ===========через индекс =================

double *createArray(int n){
    double * res = new double[n];
    for(int i=0; i<n; i++){
        res[i] = rnd(0, 10);
    }
    return res;
}

double minArray(double *T, int n, int &imin){    
    imin = 0; 
    for(int i=0; i<n; i++){
        if(T[imin] > T[i]){            
            imin = i; 
        }        
    }
    return T[imin];
}

// ===========через адрес =================
double *createArrayRef(int n){
    double * res = new double[n];
    for(auto p = res; p < res + n ;p++ ){
        *p = rnd(0, 10);
    }
    return res;
}

int main(){
    double *T = createArrayRef(100);
    int indexMin;
    double m = minArray(T, 100, indexMin);
    delete []T;
    T = nullptr;
    T = createArray(50);
    // ....
    delete []T;
    T = nullptr;
}