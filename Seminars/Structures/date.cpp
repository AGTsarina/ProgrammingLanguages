#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Date{
    int day, month, year;
};
// внешний оператор сравнения
bool operator < (const Date &d1, const Date&d2){ // d1 < d2
    if (d1.year < d2.year) return true;
    if (d1.year > d2.year) return false;
    if (d1.month < d2.month) return true;
    if (d1.month > d2.month) return false;
    return d1.day < d2.day;
}

ostream& operator << (ostream &out,const Date& d){
    out << "Date (" << d.day << "/" <<d.month<< "/" << d.year<<")";
    return out; 
}

int main(){
    Date d1{22,11, 2025}, d2{23, 11, 2026};
    vector<Date> dates {{1,1,2026}, {22,11,2025},{1,9,2025}, {23,11,2025}};
    sort(dates.begin(), dates.end()); 
    
    cout << "Dates: " << d1 << " " << d2 << endl; // вывод (поток, объект); результатом работы оператора явялется измененный поток!
    
    return 0;
}