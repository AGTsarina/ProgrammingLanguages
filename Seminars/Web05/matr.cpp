#include <iostream>
using namespace std;

// создать матрицу целых элементов
// с n строками и m столбцами
int ** create(int n, int m){
    // создать массив указателей
    int ** A = new int *[n];
    // создать каждую строку матрицы    
    for(int i=0; i< n; i++){
        A[i] = new int[m];
        // заполнить строку матрицы
        for(int j=0; j< m; j++){
            A[i][j] = i + j + 1;
        }
    }
    return A;
}

void destroy(int ** &A, int n){
    for(int i=0; i< n; i++){
        delete[] A[i];
    }
    delete []A;
    A = nullptr;
}
void print(int **A, int n, int m){
    for(int i=0; i< n; i++){   
        for(int j=0; j< m; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
void min_max(int **A, int n, int m, int &min, int &max){
    min = max = A[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (A[i][j] > max) max = A[i][j];
            if (A[i][j] < min) min = A[i][j];
        }
    }
}
// Сумма элементов массива
int sum(int *A, int n){
    int s = 0;
    for(int i = 0; i<n; i++){
        s += A[i];
    }
    return s;
}
// Сумма элементов по строкам
int *sum_in_rows(int **A, int n, int m){
    int * s = new int[n];
    for(int i=0; i<n; i++){
        s[i] = sum(A[i], m);
    }
    return s;
}


int main(){
    int ** A = create(3, 3);
    int min, max;
    min_max(A, 3, 3, min, max);
    cout << min << " " << max << endl;
    int *s = sum_in_rows(A, 3, 3);
    delete[]s;
    destroy(A, 3);
    return 0;
}