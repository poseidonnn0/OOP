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
#include <Windows.h>
namespace vector_func
{
    class Point // используем структуру, чтобы передавать именно данные точки, изначально как public поле
    {
    public:
        double x, y, z;
        Point(double xValue = 0, double yValue = 0, double zValue = 0) : x(xValue), y(yValue), z(zValue) {} // конструктор точки и определение координат
        // гет. дл€ получени€ координат вектора
        double getX()
        {
            return x;
        }
        double getY()
        {
            return y;
        }
        double getZ()
        {
            return z;
        }
        // сетеры дл€ изменени€ координат, если нам это необходимо
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
    public: // т.к. переопредел€ю операции с векторами, то x, y, z необходимо сделать публичными
        double x, y, z;
        Vector(double xValue = 0, double yValue = 0, double zValue = 0) : x(xValue), y(yValue), z(zValue) {} // конструктор вектора и определение координат

        Vector(const Point& start, const Point& end); // делегируем конструктор дл€ заданных координат точек, если вектор создаЄтс€ по точкам

        ~Vector() {}; // деструктор
        // гет. дл€ получени€ координат вектора
        double getX() 
        {
            return x;
        }

        double getY()
        {
            return y;
        }

        double getZ()
        {
            return z;
        }
        // сетеры дл€ изменени€ координат, если нам это необходимо
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

    // ќперации сложени€ и вычитани€ (ѕереопредел€ем)
    Vector operator+(const Vector& v1, const Vector& v2);
    Vector operator-(const Vector& v1, const Vector& v2);

    // ѕолучение обратного вектора
    Vector operator-(const Vector& v);

    // ѕостроение единичного вектора
    Vector normalize(const Vector& v);

    // —кал€рное произведение
    double dotProduct(const Vector& v1, const Vector& v2);

    // ¬екторное произведение
    Vector crossProduct(const Vector& v1, const Vector& v2);

    // —мешанное произведение (дл€ 3 векторов)
    double mixedProduct(const Vector& v1, const Vector& v2, const Vector& v3);

    // ƒлина вектора
    double length(const Vector& v);

    // ѕроверка коллинеарности векторов
    bool areCollinear(const Vector& v1, const Vector& v2);

    // ѕроверка компланарности векторов
    bool areCoplanar(const Vector& v1, const Vector& v2, const Vector& v3);

    // –ассто€ние между векторами
    double distance(const Vector& v1, const Vector& v2);

    // Ќахождение угла между векторами (в радианах)
    double angle(const Vector& v1, const Vector& v2);
}
#endif