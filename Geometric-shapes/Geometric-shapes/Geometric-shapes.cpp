#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int space;

class point//класс одной точки
{
public:
    int coordinate[99];//точка может содержать до 99 координат #x,y,z...

    void Enter()//метод ввода координат одной точки
    {
        cout << "  Координаты точки" << endl;
        for (int i = 0; i < space; i++)
        {
            if (i != 2)
            {
                cout << "   Введите " << i + 1 << "-ую кординату точки: ";
                cin >> coordinate[i];
            }
            else
            {
                cout << "   Введите " << i + 1 << "-ю кординату точки: ";
                cin >> coordinate[i];
            }
        }
    }
};

class figure//класс различных фигур
{
public:
    string name;
    point kord[4];//координата фигуры
    float side[5] = { 0,0,0,0,0 };//расстояние между координатами
    float radius, perimetr, poluper, area, addit;// радиус окружности, периметр,полупериметр,площадь и вспомогательная переменная
    int choice;

    void Abort(int variant)
    {
        choice = 0;
    }

    void Enter_Triangle(point X[], int variant)//метод принимающий значения координат
    {
        cout << " Введите название треугольника : ";
        cin >> name;
        choice = variant;//переменная choice принимает значения от 0 до 3, каждое из них соотвествует форме фигуры
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < space; i++)
                kord[k].coordinate[i] = X[k].coordinate[i];
        }
        Distance();//метод находит расстояние между координтами
        Specifications_Triangle();//метод рассчитывает площадь и периметр треугольника
    }

    void Enter_Circle(point X[], int variant)//метод принимает координаты центра окружности и радиус
    {
        cout << " Введите название окружности: ";
        cin >> name;
        choice = variant;
        for (int i = 0; i < space; i++)
            kord[1].coordinate[i] = X[1].coordinate[i];
        cout << "Введите длинну радиуса: ";
        cin >> radius;
        Specifications_Circle();// метод находит длинну и площадь окружности
    }

    void Enter_Quadrilateral(point X[], int variant)//метод принимает координаты четырехугольника
    {
        cout << " Введите название четырехугольника: ";
        cin >> name;
        choice = variant;
        for (int k = 0; k < 4; k++)
        {
            for (int i = 0; i < space; i++)
                kord[k].coordinate[i] = X[k].coordinate[i];
        }
        Distance();
        Specifications_Quadrilateral();// метод находит площадь и периметр четырехугольника
    }

    void Distance()//находит расстояние между точками
    {
        for (int i = 0; i < space; i++)//между 1 и 0 координатой
            side[0] = side[0] + (pow((kord[1].coordinate[i] - kord[0].coordinate[i]), 2));
        side[0] = sqrt(side[0]);
        for (int k = 0; k < space; k++)//между 2 и 1 координатой
            side[1] = side[1] + (pow((kord[2].coordinate[k] - kord[1].coordinate[k]), 2));
        side[1] = sqrt(side[1]);
        for (int c = 0; c < space; c++)//между 3 и 2 координатой
            side[2] = side[2] + (pow((kord[3].coordinate[c] - kord[2].coordinate[c]), 2));
        side[2] = sqrt(side[2]);
        for (int s = 0; s < space; s++)//между 3 и 0 координатой
            side[3] = side[3] + (pow((kord[0].coordinate[s] - kord[3].coordinate[s]), 2));
        side[3] = sqrt(side[3]);
        for (int f = 0; f < space; f++)//между 2 и 0 координатой
            side[4] = side[4] + (pow((kord[0].coordinate[f] - kord[2].coordinate[f]), 2));
        side[4] = sqrt(side[4]);
    }

    void Specifications_Triangle()//метод находит периметр и по формуле Герона находит площадь треугольника
    {
        perimetr = side[0] + side[1] + side[4];
        poluper = perimetr / 2;
        area = sqrt(poluper * (poluper - side[0]) * (poluper - side[1]) * (poluper - side[4]));
    }

    void Specifications_Quadrilateral()//метод находит периметр и площадь 2-ух треугольников состовляющих вместе 4-ехугольник
    {
        perimetr = side[0] + side[1] + side[4];//периметр 1-го треугольника
        poluper = perimetr / 2;
        addit = sqrt(poluper * (poluper - side[0]) * (poluper - side[1]) * (poluper - side[4]));//площадь первого треугольника
        perimetr = side[2] + side[3] + side[4];//периметр 2-го треугольника
        poluper = perimetr / 2;
        area = sqrt(poluper * (poluper - side[2]) * (poluper - side[3]) * (poluper - side[4]));//площадь второго треугольника
        area = area + addit;//сумма площадей 1-го и 2-го треугольников = площади четырехугольника
        perimetr = side[0] + side[1] + side[2] + side[3];//периметр четырехугольника
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
            cout << "\n    Название окружности : " << name << endl;
            cout << "    Координата центра окружности: (" << kord[0].coordinate[0] << ";" << kord[0].coordinate[1];
            for (int i = 2; i < space; i++)
                cout << ";" << kord[0].coordinate[i];
            cout << ")" << endl;
            cout << "    Длинна радиуса окружности : " << radius << endl;
            cout << "    Площадь окружности: " << area << endl;
            cout << "    Длинна окружности:" << perimetr << endl << endl;
        }
        else if (choice == 2)// если choice  равен 2-ум, то фигура - четырехугольник
        {
            cout << "\n    Название четырехугольника : " << name << endl;
            for (int k = 0; k < 4; k++)
            {
                cout << "    Координата точки " << k + 1 << ": (" << kord[k].coordinate[0] << ";" << kord[k].coordinate[1];
                for (int s = 2; s < space; s++)
                    cout << ";" << kord[k].coordinate[s];
                cout << ")" << endl;
            }
            cout << "    Площадь четырехугольника: " << area << endl;
            cout << "    Периметр четырехугольника:" << perimetr << endl << endl;
        }
        else if (choice == 1)// если choice  равен 1-му, то фигура - треугольник
        {
            cout << "\n    Название треугольника : " << name << endl;
            for (int k = 0; k < 3; k++)
            {
                cout << "    Координата точки " << k + 1 << ": (" << kord[k].coordinate[0] << ";" << kord[k].coordinate[1];
                for (int s = 2; s < space; s++)
                    cout << ";" << kord[k].coordinate[s];
                cout << ")" << endl;
            }
            cout << "    Площадь треугольника: " << area << endl;
            cout << "    Периметр треугольника:" << perimetr << endl << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите размерность пространства: ";
    cin >> space;// размерность пространства
    point X[4];// массив класс point содержит 4-е элемента, что соотвествует макс. кол-ву координат фигуры
    figure Z[99];// массив класса figure может содержать до 99 фигур
    Z[6].choice = 0;
    int variant;//переменная определяет тип фигуры
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
        cout << "   Наберите 1, если хотите ввести треугольник, 2 - четырехугольник, 3 - круг, 0 - если больше не хотите вводить фигуры." << endl;;
        cout << "   Вы хотите ввести: ";
        cin >> variant;
        if (variant == 1)//если переменная variant равна 1, то фигура - треугольник, содержит три координаты и используется метод Enter_Triangle()
        {
            cout << "\n Треугольник " << endl;
            X[0].Enter();//ввод координат первой точки треугольника
            X[1].Enter();
            X[2].Enter();
            Z[i].Enter_Triangle(X, variant);//поясняла выше
        }
        else if (variant == 2)//подобно треугольнику
        {
            cout << "\n Четырехугольникник " << endl;
            X[0].Enter();
            X[1].Enter();
            X[2].Enter();
            X[3].Enter();
            Z[i].Enter_Quadrilateral(X, variant);
        }
        else if (variant == 3)//подобно треугольнику
        {
            cout << "\n Окружность " << endl;
            X[0].Enter();
            Z[i].Enter_Circle(X, variant);
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
