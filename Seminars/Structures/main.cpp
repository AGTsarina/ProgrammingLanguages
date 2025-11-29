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
bool operator < (const Date &d1, const Date&d2){
    if (d1.year < d2.year) return true;
    if (d1.year > d2.year) return false;
    if (d1.month < d2.month) return true;
    if (d1.month > d2.month) return false;
    return d1.day < d2.day;
}
// d1 < d2

struct Student
{
    /* свойства объекта (по умолчанию свойства открытого доступа) */
    /* свойство объекта описано как поле, для которого заданы тип и имя*/
    string name;
    string group;
    Date dayOfBirth;
    int age;
    float averageGrade;
    vector<int> grades;    
    // перегрузка оператора (внутрений оператор)
    bool operator < (const Student &other) const{
        return averageGrade > other.averageGrade;
    }
};

void Print(const Student &student, ostream &fout=cout){    
    fout << student.name<<endl;    
}

void Read(Student &student, istream &fin=cin){    
    fin >> student.name >> student.group;   
}

Student Read(istream &fin=cin){   
    Student student;  
    fin >> student.name >> student.group;
    return student;   
}


int main(){
    // создание объекта типа структуры
    Student student{"Name", "M-25", {1, 1, 2007}, 18, 100.0, {100, 100, 100}},
    anotherStudent{"AnotherName", "M-25", {1, 1, 2007}, 18, 90.0, {90, 90, 90}};
    Print(student);
    /*student.name = "NameOfStudent";
    student.age = 20;
    student.group = "M-25";
    student.grades = {100,100,100};*/

    vector<Student> students{student, anotherStudent};
    sort(students.begin(), students.end());
    ofstream out("students.txt");
    for(auto s: students){
        Print(s, out);
    }
    student.group = "VT-25";
    Read(student);
    Student st = Read();
    int a = 5, b = 7;
    auto res = a < b;
    // 'a' сравнить с 'b' (внутренний оператор сравнения для объекта а, b - параметр);
    // сравнить 'a' и 'b' (врешний оператор, где a и b являются параметрами)

    
    return 0;
}



