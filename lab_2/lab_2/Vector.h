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
    class Point // ���������� ���������, ����� ���������� ������ ������ �����, ���������� ��� public ����
    {
    public:
        double x, y, z;
        Point(double xValue = 0, double yValue = 0, double zValue = 0) : x(xValue), y(yValue), z(zValue) {} // ����������� ����� � ����������� ���������
        // ���. ��� ��������� ��������� �������
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
        // ������ ��� ��������� ���������, ���� ��� ��� ����������
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

    class Vector /*: public Point*/ // ����� ��������
    {
    public: // �.�. ������������� �������� � ���������, �� x, y, z ���������� ������� ����������
        double x, y, z;
        Vector(double xValue = 0, double yValue = 0, double zValue = 0) : x(xValue), y(yValue), z(zValue) {} // ����������� ������� � ����������� ���������

        Vector(const Point& start, const Point& end); // ���������� ����������� ��� �������� ��������� �����, ���� ������ �������� �� ������

        ~Vector() {}; // ����������
        // ���. ��� ��������� ��������� �������
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
        // ������ ��� ��������� ���������, ���� ��� ��� ����������
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

    // �������� �������� � ��������� (��������������)
    Vector operator+(const Vector& v1, const Vector& v2);
    Vector operator-(const Vector& v1, const Vector& v2);

    // ��������� ��������� �������
    Vector operator-(const Vector& v);

    // ���������� ���������� �������
    Vector normalize(const Vector& v);

    // ��������� ������������
    double dotProduct(const Vector& v1, const Vector& v2);

    // ��������� ������������
    Vector crossProduct(const Vector& v1, const Vector& v2);

    // ��������� ������������ (��� 3 ��������)
    double mixedProduct(const Vector& v1, const Vector& v2, const Vector& v3);

    // ����� �������
    double length(const Vector& v);

    // �������� �������������� ��������
    bool areCollinear(const Vector& v1, const Vector& v2);

    // �������� �������������� ��������
    bool areCoplanar(const Vector& v1, const Vector& v2, const Vector& v3);

    // ���������� ����� ���������
    double distance(const Vector& v1, const Vector& v2);

    // ���������� ���� ����� ��������� (� ��������)
    double angle(const Vector& v1, const Vector& v2);
}
#endif