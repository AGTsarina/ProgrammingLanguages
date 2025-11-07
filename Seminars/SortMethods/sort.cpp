#include <vector>
#include <algorithm>
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


int main(){
    
    vector<sort_method> methods({
        sotr_exchange,
        sotr_select,
        sort_insert
    });
    sort_method method = sort_insert;
    // sotr_exchange(v);
    // sotr_select(v);
    for(int i=0; i < 3; i++){
        vector<int> v({5, 7, 2, 3, 1, 9, 8, 4, 6, 10});
        methods[i](v);
        check(v);
    }
    
    return 0;
}

