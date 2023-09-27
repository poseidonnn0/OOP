#include "Vector.h"

namespace vector_func
{
    Vector::Vector(const Point& start, const Point& end) // делегируем конструктор для заданных координат точек, если вектор создаётся по точкам
    {
        x = end.getX() - start.getX();
        y = end.getY() - start.getY();
        z = end.getZ() - start.getZ();
    }

    // Операции сложения и вычитания (Переопределяем)
    Vector operator+(const Vector& v1, const Vector& v2)
    {
        return Vector(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
    }

    Vector operator-(const Vector& v1, const Vector& v2)
    {
        return Vector(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
    }

    // Получение обратного вектора
    Vector operator-(const Vector& v)
    {
        return Vector(-v.getX(), -v.getY(), -v.getZ());
    }

    // Построение единичного вектора
    Vector normalize(const Vector& v)
    {
        double length = std::sqrt(v.getX() * v.getX() + v.getY() * v.getY() + v.getZ() * v.getZ());
        return Vector(v.getX() / length, v.getY() / length, v.getZ() / length);
    }

    // Скалярное произведение
    double dotProduct(const Vector& v1, const Vector& v2)
    {
        return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
    }

    // Векторное произведение 
    Vector crossProduct(const Vector& v1, const Vector& v2)
    {
        return Vector
        (v1.getY() * v2.getZ() - v1.getZ() * v2.getY(), // на выходе получаем вектор
            v1.getZ() * v2.getX() - v1.getX() * v2.getZ(),
            v1.getX() * v2.getY() - v1.getY() * v2.getX());
    }
    // Смешанное произведение (для 3 векторов)
    double mixedProduct(const Vector& v1, const Vector& v2, const Vector& v3)
    {
        return v1.getX() * (v2.getY() * v3.getZ() - v3.getY() * v2.getZ()) // расписываем определитель и получаем число 
            - v1.getY() * (v2.getX() * v3.getZ() - v3.getX() * v2.getZ())
            + v1.getZ() * (v2.getX() * v3.getY() - v3.getX() * v2.getY());
    }

    // Длина вектора
    double length(const Vector& v)
    {
        return std::sqrt(v.getX() * v.getX() + v.getY() * v.getY() + v.getZ() * v.getZ());
    }

    // Проверка коллинеарности векторов
    bool areCollinear(const Vector& v1, const Vector& v2)
    {
        // Векторы коллинеарны, если их векторное произведение равно нулевому вектору
        return crossProduct(v1, v2).getX() == 0 && crossProduct(v1, v2).getY() == 0 && crossProduct(v1, v2).getZ() == 0;
    }

    // Проверка компланарности векторов
    bool areCoplanar(const Vector& v1, const Vector& v2, const Vector& v3)
    {
        // Векторы компланарны, если их смешанное произведение равно нулю
        return dotProduct(crossProduct(v1, v2), v3) == 0;
    }

    // Расстояние между векторами
    double distance(const Vector& v1, const Vector& v2)
    {
        return length(v2 - v1);
    }

    // Нахождение угла между векторами (в радианах)
    double angle(const Vector& v1, const Vector& v2)
    {
        double cosTheta = dotProduct(v1, v2) / (length(v1) * length(v2));
        return std::acos(cosTheta);
    }
}
