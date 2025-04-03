#include "Polinom.h"
#include <iostream>
#include <sstream>
#include <cmath>

// ����������� �� �������������
Polinom::Polinom() : degree(0) {
    for (int i = 0; i < MAX_DEGREE; i++) {
        coefficients[i] = 0;
    }
}

// ����������� � �����������
Polinom::Polinom(const double coeffs[], int deg) : degree(deg) {
    for (int i = 0; i < MAX_DEGREE; i++) {
        coefficients[i] = (i <= deg) ? coeffs[i] : 0;
    }
}

// ����������� ���������
Polinom::Polinom(const Polinom& other) : degree(other.degree) {
    for (int i = 0; i < MAX_DEGREE; i++) {
        coefficients[i] = other.coefficients[i];
    }
}

// ����������
Polinom::~Polinom() {}

// ������
double Polinom::getCoefficient(int index) const {
    if (index >= 0 && index <= degree) {
        return coefficients[index];
    }
    return 0; // ��������� 0, ���� ������ �������� �� ���
}

int Polinom::getDegree() const {
    return degree;
}

// ������
void Polinom::setCoefficient(int index, double value) {
    if (index >= 0 && index <= degree) {
        coefficients[index] = value;
    }
}

void Polinom::setDegree(int deg) {
    if (deg >= 0 && deg < MAX_DEGREE) {
        degree = deg;
    }
}

// �������� ���������
Polinom Polinom::operator+(const Polinom& other) const {
    Polinom result;
    result.degree = max(degree, other.degree);
    for (int i = 0; i <= result.degree; i++) {
        result.coefficients[i] = coefficients[i] + other.coefficients[i];
    }
    return result;
}

// �������� ��������
Polinom Polinom::operator-(const Polinom& other) const {
    Polinom result;
    result.degree = max(degree, other.degree);
    for (int i = 0; i <= result.degree; i++) {
        result.coefficients[i] = coefficients[i] - other.coefficients[i];
    }
    return result;
}

// �������� ��������
Polinom Polinom::operator*(const Polinom& other) const {
    Polinom result;
    result.degree = degree + other.degree;
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= other.degree; j++) {
            result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    return result;
}

// �������� ���������
bool Polinom::operator==(const Polinom& other) const {
    if (degree != other.degree) return false;
    for (int i = 0; i <= degree; i++) {
        if (coefficients[i] != other.coefficients[i]) return false;
    }
    return true;
}

// �������� ���������
Polinom& Polinom::operator=(const Polinom& other) {
    if (this == &other) return *this;
    degree = other.degree;
    for (int i = 0; i < MAX_DEGREE; i++) {
        coefficients[i] = other.coefficients[i];
    }
    return *this;
}

// ���������� �������� �������
double Polinom::evaluate(double x) const {
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

// ���������������
Polinom Polinom::derivative() const {
    Polinom result;
    if (degree == 0) return result;
    result.degree = degree - 1;
    for (int i = 1; i <= degree; i++) {
        result.coefficients[i - 1] = coefficients[i] * i;
    }
    return result;
}

// ������������
Polinom Polinom::integral() const {
    Polinom result;
    result.degree = degree + 1;
    for (int i = degree; i >= 0; i--) {
        result.coefficients[i + 1] = coefficients[i] / (i + 1);
    }
    return result;
}

// �������� ���������� �� �����
Polinom::operator string() const {
    ostringstream os;
    for (int i = degree; i >= 0; i--) {
        os << coefficients[i] << "x^" << i;
        if (i > 0) os << " + ";
    }
    return os.str();
}

// ���������
void Polinom::display() const {
    cout << string(*this) << endl;
}

// �������� ������
ostream& operator<<(ostream& os, const Polinom& p) {
    os << string(p);
    return os;
}

// �������� �����
istream& operator>>(istream& is, Polinom& p) {
    cout << "������ ������ �������: ";
    is >> p.degree;
    for (int i = 0; i <= p.degree; i++) {
        cout << "���������� ��� x^" << i << ": ";
        is >> p.coefficients[i];
    }
    return is;
}

