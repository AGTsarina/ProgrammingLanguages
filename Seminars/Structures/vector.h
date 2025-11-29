#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

// файл заголовков 
// описание пользовательского типа данных
// заголовки функций, которые обеспечивают работу для этого типа данных
struct Vector{
    double * data;
    int size;
    int capacity;
};
Vector Read(istream &);
istream& operator >> (istream&, Vector&);
ostream& operator << (ostream&, const Vector&);
void Destroy(Vector &);


// реализация

Vector Read(istream &in){
    Vector res;
    in >> res.size;
    res.capacity = res.size;
    res.data = new double[res.size];
    for(int i=0; i< res.size; i++){
        in >> res.data[i];
    }
    return res;
}

istream& operator >> (istream& in, Vector& v){
    v = Read(in);
    return in;
}

ostream& operator << (ostream& out, const Vector& v){
    out << "Size: "<< v.size <<"; Capacity: " << v.capacity<< endl;
    for(int i=0; i<v.size; i++){
        out << v.data[i] << " ";
    }
    out << endl;
    return out;
}

void Destroy(Vector &v){
    v.size = v.capacity = 0;
    delete[] v.data;
    v.data = nullptr;
}

