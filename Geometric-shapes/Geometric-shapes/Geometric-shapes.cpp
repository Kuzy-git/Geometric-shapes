#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int space;

class Point//класс одной точки
{
public:
    int coordinate[50];//точка может содержать до 50 координат #x,y,z...

    void vvod()//метод ввода координат одной точки
    {
        cout << "Координаты точки" << endl;
        for (int i = 0; i < space; i++)
        {
            if (i != 2)
            {
                cout << "Введите " << i + 1 << "-ую кординату точки: ";
                cin >> coordinate[i];
            }
            else
            {
                cout << "Введите " << i + 1 << "-ю кординату точки: ";
                cin >> coordinate[i];
            }
        }
    }
};

class Shapes//класс различных фигур
{
public:
    string name;
    Point cord[4];//координата фигуры
    float dist[5] = { 0,0,0,0,0 };//расстояние между координатами
    float radius, perimetr, poluper, area, addit;// радиус окружности, периметр,полупериметр,площадь и вспомогательная переменная
    int choice;

    void Abort(int variant)
    {
        choice = 0;
    }

    void vvod_Triangle(Point X[], int variant)//метод принимающий значения координат
    {
        cout << "Введите название треугольника: ";
        cin >> name;
        choice = variant;//переменная choice принимает значения от 0 до 3, каждое из них соотвествует форме фигуры
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < space; i++)
                cord[k].coordinate[i] = X[k].coordinate[i];
        }
        Distance();//метод находит расстояние между координтами
        Specifications_Triangle();//метод рассчитывает площадь и периметр треугольника
    }

    void vvod_Circle(Point X[], int variant)//метод принимает координаты центра окружности и радиус
    {
        cout << "Введите название окружности: ";
        cin >> name;
        choice = variant;
        for (int i = 0; i < space; i++)
            cord[1].coordinate[i] = X[1].coordinate[i];
        cout << "Введите длинну радиуса: ";
        cin >> radius;
        Specifications_Circle();// метод находит длинну и площадь окружности
    }

    void vvod_Quadrilateral(Point X[], int variant)//метод принимает координаты четырехугольника
    {
        cout << "Введите название четырехугольника: ";
        cin >> name;
        choice = variant;
        for (int k = 0; k < 4; k++)
        {
            for (int i = 0; i < space; i++)
                cord[k].coordinate[i] = X[k].coordinate[i];
        }
        Distance();
        Specifications_Quadrilateral();// метод находит площадь и периметр четырехугольника
    }

    void Distance()//находит расстояние между точками
    {
        for (int i = 0; i < space; i++)//между 1 и 0 координатой
            dist[0] = dist[0] + (pow((cord[1].coordinate[i] - cord[0].coordinate[i]), 2));
        dist[0] = sqrt(dist[0]);
        for (int k = 0; k < space; k++)//между 2 и 1 координатой
            dist[1] = dist[1] + (pow((cord[2].coordinate[k] - cord[1].coordinate[k]), 2));
        dist[1] = sqrt(dist[1]);
        for (int c = 0; c < space; c++)//между 3 и 2 координатой
            dist[2] = dist[2] + (pow((cord[3].coordinate[c] - cord[2].coordinate[c]), 2));
        dist[2] = sqrt(dist[2]);
        for (int s = 0; s < space; s++)//между 3 и 0 координатой
            dist[3] = dist[3] + (pow((cord[0].coordinate[s] - cord[3].coordinate[s]), 2));
        dist[3] = sqrt(dist[3]);
        for (int f = 0; f < space; f++)//между 2 и 0 координатой
            dist[4] = dist[4] + (pow((cord[0].coordinate[f] - cord[2].coordinate[f]), 2));
        dist[4] = sqrt(dist[4]);
    }

    void Specifications_Triangle()//метод находит периметр и по формуле Герона находит площадь треугольника
    {
        perimetr = dist[0] + dist[1] + dist[4];
        poluper = perimetr / 2;
        area = sqrt(poluper * (poluper - dist[0]) * (poluper - dist[1]) * (poluper - dist[4]));
    }

    void Specifications_Quadrilateral()//метод находит периметр и площадь 2-ух треугольников состовляющих вместе 4-ехугольник
    {
        perimetr = dist[0] + dist[1] + dist[4];//периметр 1-го треугольника
        poluper = perimetr / 2;
        addit = sqrt(poluper * (poluper - dist[0]) * (poluper - dist[1]) * (poluper - dist[4]));//площадь первого треугольника
        perimetr = dist[2] + dist[3] + dist[4];//периметр 2-го треугольника
        poluper = perimetr / 2;
        area = sqrt(poluper * (poluper - dist[2]) * (poluper - dist[3]) * (poluper - dist[4]));//площадь второго треугольника
        area = area + addit;//сумма площадей 1-го и 2-го треугольников = площади четырехугольника
        perimetr = dist[0] + dist[1] + dist[2] + dist[3];//периметр четырехугольника
    }

    void Specifications_Circle()//метод находит периметр и площадь окружности
    {
        perimetr = 6.28 * radius;
        area = 3.14 * pow(radius, 2);
    }

    void Print()//метод выводит все фигуры и их характеристики в консоль
    {
        if (choice == 3)// если choice  равен 3-ем, то фигура - окружность
        {
            cout << "\nНазвание окружности: " << name << endl;
            cout << "Площадь окружности: " << area << endl;
            cout << "Длинна окружности: " << perimetr << endl << endl;
        }
        else if (choice == 2)// если choice  равен 2-ум, то фигура - четырехугольник
        {
            cout << "\nНазвание четырехугольника: " << name << endl;
            for (int k = 0; k < 4; k++)
            {
                cout << "Координата точки " << k + 1 << ": (" << cord[k].coordinate[0] << ";" << cord[k].coordinate[1];
                for (int s = 2; s < space; s++)
                    cout << ";" << cord[k].coordinate[s];
                cout << ")" << endl;
            }
            cout << "Площадь четырехугольника: " << area << endl;
            cout << "Периметр четырехугольника: " << perimetr << endl << endl;
        }
        else if (choice == 1)// если choice  равен 1-му, то фигура - треугольник
        {
            cout << "\nНазвание треугольника : " << name << endl;
            for (int k = 0; k < 3; k++)
            {
                cout << "Координата точки " << k + 1 << ": (" << cord[k].coordinate[0] << ";" << cord[k].coordinate[1];
                for (int s = 2; s < space; s++)
                    cout << ";" << cord[k].coordinate[s];
                cout << ")" << endl;
            }
            cout << "Площадь треугольника: " << area << endl;
            cout << "Периметр треугольника:" << perimetr << endl << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите размерность пространства: ";
    cin >> space;// размерность пространства
    Point X[4];// массив класс Point содержит 4-е элемента, что соотвествует макс. кол-ву координат фигуры
    Shapes Z[50];// массив класса Shapes может содержать до 50 фигур
    Z[6].choice = 0;
    int variant;//переменная определяет тип фигуры
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
        cout << "Наберите 1, если хотите ввести треугольник, 2 - четырехугольник, 3 - круг, 0 - вывести фигуры на консоль." << endl;
        cin >> variant;
        if (variant == 1)//если переменная variant равна 1, то фигура - треугольник, содержит три координаты и используется метод vvod_Triangle()
        {
            cout << "\nТреугольник " << endl;
            X[0].vvod();//ввод координат первой точки треугольника
            X[1].vvod();
            X[2].vvod();
            Z[i].vvod_Triangle(X, variant);//поясняла выше
        }
        else if (variant == 2)//подобно треугольнику
        {
            cout << "\nЧетырехугольникник " << endl;
            X[0].vvod();
            X[1].vvod();
            X[2].vvod();
            X[3].vvod();
            Z[i].vvod_Quadrilateral(X, variant);
        }
        else if (variant == 3)//подобно треугольнику
        {
            cout << "\nОкружность " << endl;
            X[0].vvod();
            Z[i].vvod_Circle(X, variant);
        }
        else if (variant == 0)//выход из цикла
        {
            Z[i].Abort(variant);
            break;
        }
        else continue;//цикл начинается сначала, если введено не верное значения для переменной variant
    }
    for (int s = 0; s < 10; s++)// цикл выводит данные о фигурах
        Z[s].Print();
    return 0;
}
