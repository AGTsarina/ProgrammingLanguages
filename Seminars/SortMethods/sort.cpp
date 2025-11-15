#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
using namespace std;

typedef void(*sort_method)(vector<int>&);

void sotr_exchange(vector<int> &v){
    int n = v.size();
    for(int i = 1; i < n; i++){
        for(int j = 0;j < n - i; j++){
            if (v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
                /*int x = v[j];
                v[j] = v[j + 1];
                v[j + 1] = x;*/
            }
        }
    }
}
void sotr_select(vector<int> &v){
    int n = v.size();
    for(int i=0; i< n - 1; i++){
        int min_value = v[i];
        int min_index = i;
        for(int j = i + 1; j < n; j++){
            if (v[j] < min_value){
                min_value = v[j];
                min_index = j;
            }
        }
        v[min_index] = v[i];
        v[i] = min_value;
    }
}

void sort_insert(vector<int> &v){
    int n = v.size();
    for(int i=1; i<n; i++){
        int x = v[i];
        int j = i - 1;
        for(; j >= 0 && v[j] > x; j--){
            v[j+1] = v[j];
        }
        v[j + 1] = x;
    }
}

void buildTree(vector<int> &v, int &L, int &R){
    int i = L;
    int left = 2 * i + 1, right = 2 * i + 2;
    int max = v[left];
    int imax = left;
    if (right <= R && v[right] > max){
         max = v[right];
         imax = right;
    }
    while(i <= R && v[i] < max){
        swap(v[i], v[imax]);
        i = imax;
        left = 2 * i + 1; right = 2 * i + 2;
        if (left <=R){
            max = v[left];
            imax = left;
            if (right <= R && v[right] > max){
                max = v[right];
                imax = right;
            }
        }
        else break;
    }
}

void heap_sort(vector<int> &v){
    int L = v.size() / 2, R = v.size() - 1;
    // построение бинарного дерева
    while(L > 0){
        L-- ;
        buildTree(v, L, R);         
    }
    while(true){   // главный цикл сортировки
        swap(v[L], v[R]);
        R--;
        if (R == 1) break;
        buildTree(v, L, R);
    }
}




bool check(const vector<int>& v){
    for(int i=1; i<v.size(); i++){
        if (v[i] < v[i-1]) return false;
    }
    return true;
}
vector<int> generate(int n, mt19937& engine, uniform_int_distribution<int> &distribution){
    vector<int> res(n);
    for(int i=0; i<n; i++){
        res[i] = distribution(engine);
    }
    return res;
}

double sortTime(const vector<int>& v_init,
                sort_method method, bool &correct){
    vector<int> v(v_init);
    const auto start{chrono::steady_clock::now()};
    method(v);
    const auto finish{chrono::steady_clock::now()};
    const chrono::duration<double> elapsed_seconds{finish - start};
    correct = check(v);
    return elapsed_seconds.count();
}


int main(){
     vector<int> v({4,2,7,8,1,3,5,6});
     heap_sort(v);
     return 0;
}

/*int main(){
    random_device random_device;
    mt19937 engine(random_device());
    uniform_int_distribution<int> distribution(0, 1000);
    auto value = distribution(engine);
    vector<sort_method> methods({
        sotr_exchange,
        sotr_select,
        sort_insert
    });
    vector<string> names({"sotr_exchange",
        "sotr_select",
        "sort_insert"});
    int size = 20000;
    vector<int> v_init = generate(size, engine, distribution);
    for(int i=0; i < methods.size(); i++){
        bool correct;
        double time = sortTime(v_init, methods[i], correct);
        if (correct){
            cout <<"Метод " << names[i];
            cout <<" выполняет работу за " << time << " c.\n";
        }
        else cout << "Ошибка!\n";
    }
    
    return 0;
}*/
