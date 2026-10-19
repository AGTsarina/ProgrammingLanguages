#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void readFile(const string& filename,
    vector<double> &T, vector<double>&P, vector<double>&U){

    ifstream input(filename);
    //ofstream output("output.txt");   
    string line; // объявляем строку
    // input >> line; // чтение по словам
    // input.getline()  // чтение на низком уровне, в динамический массив
    bool header = false;
    while(getline(input, line)){
        // 1. скопируем в файл output все строки, не начинающиеся с #
        if(line[0] != '#' /* 0x23*/){
            //output << line << endl;        
            if (!header){
                header = true;
            }
            else{                
                // разбор строки на составляющие
                // 2. Формируем "вокруг" строки файловый поток
                stringstream streamLine(line); // поток коструируется
                // вокрук строки line, поэтому line указана в ()
                string date;
                getline(streamLine, date, ';');
                // 3. Разбираем строку на нужные нас составляющие
                // T, P, U
                string strT, strP, strU, tmp;
                getline(streamLine, strT, ';');
                getline(streamLine, strP, ';');
                getline(streamLine, tmp, ';');
                getline(streamLine, tmp, ';');
                getline(streamLine, strU, ';');
                // 4. Переводим прочитанные значения из 
                // строки в число
                //tmp = strT.substr(1, strT.size()-2);
                if (strT != "" && strP != "" && strU != "" ){
                    cout << date << endl;
                    double t = stod(strT.substr(1, strT.size()-2));
                    double p = stod(strP.substr(1, strP.size()-2));
                    double u = stod(strU.substr(1, strU.size()-2));
                    // 5. Записываем значения T, P, U в массивы
                    T.push_back(t);
                    P.push_back(p);
                    U.push_back(u);
                }
            }
        }
    }
    }

// перегруженная функция
vector<vector<double>> readFile(const string& filename){
    vector<double> T, P, U;
    // вызов  перегруженной функции (с другим набором параметров)
    readFile(filename, T, P, U);
    return {T, P, U};
}

int main(){
    vector<double> T, P, U;
    readFile("27705.01.09.2026.30.09.2026.1.0.0.ru.ansi.00000000.csv",
    T, P, U);

    auto Res =  readFile("27705.01.09.2026.30.09.2026.1.0.0.ru.ansi.00000000.csv");
    return 0;
}