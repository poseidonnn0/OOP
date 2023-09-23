#include "Vector.h"

//using namespace vector_func;

int main() 
{
    SetConsoleOutputCP(1251); // Для русского языка в консоли

    // Пример использования классов и операций
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x7, y7, z7;
    std::cout << "Введите значения для точки p1 через пробел: ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "Введите значения для точки p2 через пробел: ";
    std::cin >> x2 >> y2 >> z2;
    vector_func::Point p1(x1, y1, z1);
    vector_func::Point p2(x2, y2, z2);
    vector_func::Vector v1(p1, p2);
    std::cout << "Вектор, который строится по этим точкам(p1, p2) имеет координаты: x = " 
        << v1.getX() << " y = " << v1.getY() << " z = " << v1.getZ() << '\n';

    std::cout << "Введите значения для вектора v2 через пробел: ";
    std::cin >> x3 >> y3 >> z3;
    vector_func::Vector v2(x3, y3, z3);
    vector_func::Vector v3 = v2 + v1;

    std::cout << "Сложение векторов v1 + v2, где координаты x = " << 
        v3.getX() << " y = " << v3.getY() << " z = " << v3.getZ() << '\n';
    vector_func::Vector v4 = v2 - v1;

    std::cout << "Вычитание векторов v2 - v1, где координаты x = " <<
        v4.getX() << " y = " << v4.getY() << " z = " << v4.getZ() << '\n';
    vector_func::Vector v5 = vector_func::normalize(v1);
    vector_func::Vector v6 = -v1;
    std::cout << "Обратный вектор для v1: x = " << 
        v6.getX() << " y = " << v6.getY() << " z = " << v6.getZ() << '\n';

    std::cout << "Введите значения для вектора v7 через пробел: ";
    std::cin >> x7 >> y7 >> z7;
    vector_func::Vector v7(x7, y7, z7);

    if (vector_func::areCollinear(v2, v7))
    {
        std::cout << "Вектора v2 и v7 коллениарны!\n";
    }
    else 
    {
        std::cout << " Вектора v2 и v7 НЕ коллениарны!\n";
    }

    if (vector_func::areCoplanar(v1, v2, v7))
    {
        std::cout << "Вектора v1, v2 и v7 компланарны!\n";
    }
    else
    {
        std::cout << " Вектора v1, v2 и v7 НЕ компланарны!\n";
    }

    std::cout << "Расстояние между вектором v2 и v7 = " << vector_func::distance(v2, v7) << '\n';

    std::cout << "Угол между векторами v2 и v7 = " << vector_func::angle(v2, v7);

    return 0;
}