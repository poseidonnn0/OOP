#include "Vector.h"

namespace vector_func
{
    Vector::Vector(const Point& start, const Point& end) // делегируем конструктор для заданных координат точек, если вектор создаётся по точкам
    {
        x = end.x - start.x;
        y = end.y - start.y;
        z = end.z - start.z;
    }

    // Операции сложения и вычитания (Переопределяем)
    Vector operator+(const Vector& v1, const Vector& v2)
    {
        return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    Vector operator-(const Vector& v1, const Vector& v2)
    {
        return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    }

    // Получение обратного вектора
    Vector operator-(const Vector& v)
    {
        return Vector(-v.x, -v.y, -v.z);
    }

    // Построение единичного вектора
    Vector normalize(const Vector& v)
    {
        double length = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        return Vector(v.x / length, v.y / length, v.z / length);
    }

    // Скалярное произведение
    double dotProduct(const Vector& v1, const Vector& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    // Векторное произведение 
    Vector crossProduct(const Vector& v1, const Vector& v2)
    {
        return Vector
        (v1.y * v2.z - v1.z * v2.y, // на выходе получаем вектор
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x);
    }
    // Смешанное произведение (для 3 векторов)
    double mixedProduct(const Vector& v1, const Vector& v2, const Vector& v3)
    {
        return v1.x * (v2.y * v3.z - v3.y * v2.z) // расписываем определитель и получаем число 
            - v1.y * (v2.x * v3.z - v3.x * v2.z)
            + v1.z * (v2.x * v3.y - v3.x * v2.y);
    }

    // Длина вектора
    double length(const Vector& v)
    {
        return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    // Проверка коллинеарности векторов
    bool areCollinear(const Vector& v1, const Vector& v2)
    {
        // Векторы коллинеарны, если их векторное произведение равно нулевому вектору
        return crossProduct(v1, v2).x == 0 && crossProduct(v1, v2).y == 0 && crossProduct(v1, v2).z == 0;
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