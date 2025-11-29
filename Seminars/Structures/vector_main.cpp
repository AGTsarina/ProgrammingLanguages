#include "vector.h"

int main(){
    Vector v1, v2, v3;
    vector<Vector> V({v1, v2, v3});
    ifstream in("input.txt");
    for(int i=0; i < V.size(); i++){
        in >> V[i];
    }
    for(const Vector &v: V){
        cout << v.size;
    }
    return 0;
}