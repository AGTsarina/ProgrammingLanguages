#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <iomanip>
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

void partition(vector<int> &v, int L, int R, int &l, int &r){
    int length = (R - L);
    int middle = (L + R) / 2; //L + length / 2;
    int x = v[middle]; // !!! ВАЖНО! запомнить элемент
    int i = L, j = R;
    do{        
        while(v[i] < x/*v[middle]*/) i++; // !!! Ошибка использовать v[middle], так он может изменить значение при обмене! 
        while(v[j] > x/*v[middle]*/) j--; // !!! Ошибка использовать v[middle], так он может изменить значение при обмене! 
        if (i <=j){
            swap(v[i], v[j]);
            i++; j--;
        }
    }while(i<=j);
    l = j; r = i;
}

void quick_sort(vector<int> &v, int L, int R){
    int l, r;
    partition(v, L, R, l, r);
    if (L < l){
        quick_sort(v, L, l);
    }
    if (r < R){
        quick_sort(v, r, R);
    }
}
void quick_sort(vector<int> &v){
    quick_sort(v, 0, v.size()-1);
}




int check(const vector<int>& v){
    for(int i=1; i<v.size(); i++){
        if (v[i] < v[i-1]) return i;
    }
    return -1;
}
vector<int> generate(int n, mt19937& engine, uniform_int_distribution<int> &distribution){
    vector<int> res(n);
    for(int i=0; i<n; i++){
        res[i] = distribution(engine);
    }
    return res;
}


void check_sort(){
    random_device random_device;
    mt19937 engine(random_device());
    uniform_int_distribution<int> distribution(0, 1000);
    while(true){
        vector<int> v_init = generate(10000, engine, distribution);
        vector<int> v({1,2,1,2,1,2,3,3,3,1,2,1,3,2,1,2,3});
        quick_sort(v_init);
        int res= check(v_init);
        if (res > 0) continue;
    }

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

void f(vector<int> v){
    int *data = v.data();
    return;
}

void evaluate_sort(int size = 20000, ostream &out=cout){
    random_device random_device;
    mt19937 engine(random_device());
    uniform_int_distribution<int> distribution(0, 1000);
    auto value = distribution(engine);
    vector<sort_method> methods({
        sotr_exchange,
        sotr_select,
        sort_insert,
        heap_sort,
        quick_sort
    });
   
    vector<int> v_init = generate(size, engine, distribution);
    for(int i=0; i < methods.size(); i++){
        bool correct;
        double time = sortTime(v_init, methods[i], correct);
        if (correct){
            // cout <<"Метод " << names[i];
            //cout <<" выполняет работу за " << time << " c.\n";
            out << time<<";";
        }
        else cout << "Ошибка!\n";
    }
    out << endl;
    
}

int main(){
    ofstream out("res.csv");
    vector<string> names({"sotr_exchange",
        "sotr_select",
        "sort_insert","heap_sort", "quick_sort"});
    out <<"N;";
    for(auto& name: names){
        out << name<<";";
    }
    out << endl;
    for(int n = 1000; n<20000; n += 1000){
        out << n<<";";
        evaluate_sort(n, out);
    } 
    
}

/*
Метод sotr_exchange выполняет работу за 0.690613 c.
Метод sotr_select выполняет работу за 0.190464 c.
Метод sort_insert выполняет работу за 0.242642 c.
Метод heap_sort выполняет работу за 0.00328803 c.
Метод quick_sort выполняет работу за 0.00181096 c.
*/