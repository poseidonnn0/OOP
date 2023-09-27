/*
* func.h
*
* @created 23.09.2023 Vitaliy Kondratev
*
*/

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <cmath>
#include <windows.h>
namespace vector_func
{
    class Point // используем структуру, чтобы передавать именно данные точки, изначально как public поле
    {
        double x, y, z;
    public:
        Point(double xValue = 0, double yValue = 0, double zValue = 0) : x(xValue), y(yValue), z(zValue) {} // конструктор точки и определение координат
        // гет. для получения координат вектора
        double getX() const
        {
            return x;
        }
        double getY() const
        {
            return y;
        }
        double getZ() const
        {
            return z;
        }
        // сетеры для изменения координат, если нам это необходимо
        void setX(double x)
        {
            this->x = x;
        }
        void setY(double y)
        {
            this->y = y;
        }
        void setZ(double z)
        {
            this->z = z;
        }
    };

    class Vector /*: public Point*/ // класс векторов
    {
        double x, y, z;
    public: // т.к. переопределяю операции с векторами, то x, y, z необходимо сделать публичными
        Vector(double xValue = 0, double yValue = 0, double zValue = 0) : x(xValue), y(yValue), z(zValue) {} // конструктор вектора и определение координат

        Vector(const Point& start, const Point& end); // делегируем конструктор для заданных координат точек, если вектор создаётся по точкам

        ~Vector() {}; // деструктор
        // гет. для получения координат вектора
        double getX() const
        {
            return x;
        }

        double getY() const
        {
            return y;
        }

        double getZ() const
        {
            return z;
        }
        // сетеры для изменения координат, если нам это необходимо
        void setX(double x)
        {
            this->x = x;
        }
        void setY(double y)
        {
            this->y = y;
        }
        void setZ(double z)
        {
            this->z = z;
        }
    };

    // Операции сложения и вычитания (Переопределяем)
    Vector operator+(const Vector& v1, const Vector& v2);
    Vector operator-(const Vector& v1, const Vector& v2);

    // Получение обратного вектора
    Vector operator-(const Vector& v);

    // Построение единичного вектора
    Vector normalize(const Vector& v);

    // Скалярное произведение
    double dotProduct(const Vector& v1, const Vector& v2);

    // Векторное произведение
    Vector crossProduct(const Vector& v1, const Vector& v2);

    // Смешанное произведение (для 3 векторов)
    double mixedProduct(const Vector& v1, const Vector& v2, const Vector& v3);

    // Длина вектора
    double length(const Vector& v);

    // Проверка коллинеарности векторов
    bool areCollinear(const Vector& v1, const Vector& v2);

    // Проверка компланарности векторов
    bool areCoplanar(const Vector& v1, const Vector& v2, const Vector& v3);

    // Расстояние между векторами
    double distance(const Vector& v1, const Vector& v2);

    // Нахождение угла между векторами (в радианах)
    double angle(const Vector& v1, const Vector& v2);

}
#endif