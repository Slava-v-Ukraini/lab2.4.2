#include <iostream>
#include "Polinom.h"

using namespace std;

int main() {
    // Створення поліномів
    double coeffs1[] = { 1, 2, 3 }; // 1 + 2x + 3x^2
    Polinom p1(coeffs1, 2);
    double coeffs2[] = { 3, 4, 5, 6 }; // 3 + 4x + 5x^2 + 6x^3
    Polinom p2(coeffs2, 3);

    // Вивід поліномів
    cout << "First polinom : " << p1 << endl;
    cout << "Second polinom : " << p2 << endl;

    // Операції
    Polinom sum = p1 + p2;
    Polinom diff = p1 - p2;
    Polinom prod = p1 * p2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Dob: " << prod << endl;

    // Обчислення значення полінома
    double x = 2.0;
    cout << "The value of the first polynomial at x = " << x << ": " << p1.evaluate(x) << endl;

    // Диференціювання та інтегрування
    cout << "The derivative of the first polynomial : " << p1.derivative() << endl;
    cout << "The integral of the first polynomial : " << p1.integral() << endl;

    // Порівняння
    cout << "Are p1 and p2 equal? " << (p1 == p2 ? "yes" : "no") << endl;

    return 0;
}