#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

double random(double a, double b);
bool isInArea(double x, double y);
bool isInArea_(double x, double y);
void Task1();
void Task2();
double CountArea(int N, double x0, double y0, double w, double h);

int main(){
    srand(time(NULL));
    // Сгенерировать M случайных **точек (x, y)** в **прямоугольнике (x0, y0, w, h)**
    // и записать их в **файл**

    Task1();
    Task2();

    cout << "\nArea (pr) = " << CountArea(1000000, 0, 0, 10, 10) << endl;

}


double random(double a, double b){
    return static_cast<double>(rand()) / RAND_MAX *(b-a) + a;
}

bool isInArea(double x, double y){
    if (0.8 * x * x -0.8 * x +5.2 > y &&
        0.13 * x * x - 2.56 * x + 16.5 > y &&
        - x * x + 20.0 * x - 96.0 < y)
        return true;
    return false;
}

bool isInArea_(double x, double y){
    if (0.8 * x * x -0.8 * x +5.2 < y) return false;
    if (0.13 * x * x - 2.56 * x + 16.5 < y) return false;
    if (- x * x + 20.0 * x + 96.0 > y) return false;
    return true;
}

void Task1(){
    // Создаем текстовый файл для записи
    ofstream output("/home/u614/tsarina/firstApp/points.txt");
    // Задаем границы прямоугольника
    const double x0=0.0, y0=0.0, w = 10.0, h = 10.0;
    // Для каждой точки 0 .. M-1
    const int M = 1000;
    for(int i = 0; i< M; i++){
        // генерируем ее координаты
        double x = random(x0, x0 + w), y = random(y0, y0 + h);
        // и записываем в файл
        output << x << "\t" << y << endl;
    }
    // закрыть файл
    // output.close();
}

void Task2(){
    // Прочитать координаты **точек** из **файла** и
    // проверить, находится ли точка в области
    // Результат проверки перенести в **новый файл**
    double x,  y;
    ifstream input("/home/u614/tsarina/firstApp/points.txt");
    ofstream result("/home/u614/tsarina/firstApp/pointsRes.txt");

    int k = 0, p = 0;
    for(int i = 0; input >> x >> y; i++, k++){
        // значения x и y прочитаны
        if(isInArea(x, y)){
            result << x << "\t" << y << "\tYes\n";
            p++;
        }
        else{
            result << x << "\t" << y << "\tNo\n";
        }
        // result << x << "\t" << y << "\t" << isInArea(x, y)<<endl;

    }
    cout << "Area = " << static_cast<double>(p) / k * 100.0;
}

double CountArea(int N, double x0, double y0, double w, double h){
    // Для N случайных расчитать площадь сложной фигуры
    int p = 0;
    for(int i=0; i<N; i++){
        double x = random(x0, x0 + w), y = random(y0, y0 + h);
        if (isInArea(x, y)) p++;
    }
    return static_cast<double>(p) / N * 100.0;
}

