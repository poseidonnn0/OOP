/*
* func.h
*
* @created 27.09.2023 Vitaliy Kondratev
*
*/

#ifndef __METHODS_H__
#define __METHODS_H__

#include <iostream>
#include <functional> // для использования шаблонов функций
#include <Windows.h>
#include <cmath>

// Класс NumericalIntegral для интеграции
class NumericalIntegral
{
protected:
    int numPoints; // Число точек
    double step; // Шаг
    double tolerance; // Точность

public:
    // Конструктор
    NumericalIntegral(int nPoints, double h, double tol) : numPoints(nPoints), step(h), tolerance(tol) {}
    // деструктор создаётся по умолчанию

    // Чисто виртуальный метод Calc для вычисления интеграла
    virtual double Calc(std::function<double(double)> f, double lowerBound, double upperBound) = 0;
};

// Класс TrapezoidalIntegral, наследник класса NumericalIntegral, для численного интегрирования методом трапеций
class TrapezoidalIntegral : public NumericalIntegral
{
public:
    // Конструктор
    TrapezoidalIntegral(int nPoints, double h, double tol) : NumericalIntegral(nPoints, h, tol) {}
    // деструктор создаётся по умолчанию

    // Переопределённый метод Calc для интегрирования методом трапеций
    double Calc(std::function<double(double)> f, double lowerBound, double upperBound) override;
};

// Класс SimpsonIntegral, наследник класса NumericalIntegral, для численного интегрирования методом Симпсона
class SimpsonIntegral : public NumericalIntegral
{
public:
    // Конструктор
    SimpsonIntegral(int nPoints, double h, double tol) : NumericalIntegral(nPoints, h, tol) {}
    // деструктор создаётся по умолчанию

    // Переопределённый метод Calc для интегрирования методом Симпсона
    double Calc(std::function<double(double)> f, double lowerBound, double upperBound) override;
};


   
#endif