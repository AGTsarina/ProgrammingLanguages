#pragma once

#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int random(int min, int max){
    return rand() % (max - min + 1) + min;
}

// случайная строка
string get_random_str(){
    string res = "";
    int n = random(4, 10);
    for(int i=0; i<n; i++){
        res += static_cast<char>(random('a', 'z'));
    }
    res[0] += 'A' - 'a';
    return res;
}
// случайный вектор
vector<int> get_random_vector(int min=5, int max=30){
    vector<int> res;
    int n = random(0, 5);
    for(int i=1; i<=n; i++){
        res.push_back(random(min, max));
    }    
    return res;
}
int random_class(const vector<int> & v){
    int p = random(0, 99);
    int i=0;
    for(; p > 0; i++){
        p-=v[i];
    }
    return i;
}