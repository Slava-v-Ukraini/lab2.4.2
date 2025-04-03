#ifndef POLINOM_H
#define POLINOM_H
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define MAX_DEGREE 100 // ������������ ������ �������

using namespace std;

class Polinom {
private:
    double coefficients[MAX_DEGREE]; // ����� �����������
    int degree; // ������ �������

public:
    // ����������� �� �������������
    Polinom();

    // ����������� � �����������
    Polinom(const double coeffs[], int deg);

    // ����������� ���������
    Polinom(const Polinom& other);

    // ����������
    ~Polinom();

    // ������
    double getCoefficient(int index) const;
    int getDegree() const;

    // ������
    void setCoefficient(int index, double value);
    void setDegree(int deg);

    // ���������
    Polinom operator+(const Polinom& other) const;
    Polinom operator-(const Polinom& other) const;
    Polinom operator*(const Polinom& other) const;
    bool operator==(const Polinom& other) const;
    Polinom& operator=(const Polinom& other);

    // ������
    double evaluate(double x) const;
    Polinom derivative() const;
    Polinom integral() const;
    operator string() const;
    void display() const;

    // �������� ��������/���������
    friend ostream& operator<<(ostream& os, const Polinom& p);
    friend istream& operator>>(istream& is, Polinom& p);
};

#endif // POLINOM_H