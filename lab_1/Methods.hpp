/*
* func.h
*
* @created 27.09.2023 Vitaliy Kondratev
*
*/

#ifndef __METHODS_H__
#define __METHODS_H__

#include <iostream>
#include <functional> // ��� ������������� �������� �������
#include <Windows.h>
#include <cmath>

// ����� NumericalIntegral ��� ����������
class NumericalIntegral
{
protected:
    int numPoints; // ����� �����
    double step; // ���
    double tolerance; // ��������

public:
    // �����������
    NumericalIntegral(int nPoints, double h, double tol) : numPoints(nPoints), step(h), tolerance(tol) {}
    // ���������� �������� �� ���������

    // ����� ����������� ����� Calc ��� ���������� ���������
    virtual double Calc(std::function<double(double)> f, double lowerBound, double upperBound) = 0;
};

// ����� TrapezoidalIntegral, ��������� ������ NumericalIntegral, ��� ���������� �������������� ������� ��������
class TrapezoidalIntegral : public NumericalIntegral
{
public:
    // �����������
    TrapezoidalIntegral(int nPoints, double h, double tol) : NumericalIntegral(nPoints, h, tol) {}
    // ���������� �������� �� ���������

    // ��������������� ����� Calc ��� �������������� ������� ��������
    double Calc(std::function<double(double)> f, double lowerBound, double upperBound) override;
};

// ����� SimpsonIntegral, ��������� ������ NumericalIntegral, ��� ���������� �������������� ������� ��������
class SimpsonIntegral : public NumericalIntegral
{
public:
    // �����������
    SimpsonIntegral(int nPoints, double h, double tol) : NumericalIntegral(nPoints, h, tol) {}
    // ���������� �������� �� ���������

    // ��������������� ����� Calc ��� �������������� ������� ��������
    double Calc(std::function<double(double)> f, double lowerBound, double upperBound) override;
};


   
#endif