#ifndef POLINOM_H
#define POLINOM_H
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define MAX_DEGREE 100 // Максимальний степінь полінома

using namespace std;

class Polinom {
private:
    double coefficients[MAX_DEGREE]; // Масив коефіцієнтів
    int degree; // Степінь полінома

public:
    // Конструктор за замовчуванням
    Polinom();

    // Конструктор з параметрами
    Polinom(const double coeffs[], int deg);

    // Конструктор копіювання
    Polinom(const Polinom& other);

    // Деструктор
    ~Polinom();

    // Гетери
    double getCoefficient(int index) const;
    int getDegree() const;

    // Сетери
    void setCoefficient(int index, double value);
    void setDegree(int deg);

    // Оператори
    Polinom operator+(const Polinom& other) const;
    Polinom operator-(const Polinom& other) const;
    Polinom operator*(const Polinom& other) const;
    bool operator==(const Polinom& other) const;
    Polinom& operator=(const Polinom& other);

    // Методи
    double evaluate(double x) const;
    Polinom derivative() const;
    Polinom integral() const;
    operator string() const;
    void display() const;

    // Операції введення/виведення
    friend ostream& operator<<(ostream& os, const Polinom& p);
    friend istream& operator>>(istream& is, Polinom& p);
};

#endif // POLINOM_H