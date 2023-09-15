//
// Created by User on 13/9/2023.
//
#include <iostream>
#include <vector>

using namespace std;

// Función para calcular el polinomio de Lagrange
double lagrange(const vector<double>& x, const vector<double>& y, double xi) {
    int n = x.size();
    double resultado = 0.0;

    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        resultado += term;
    }

    return resultado;
}

int main() {
    int n;
    cout << "Ingrese el número de puntos: ";
    cin >> n;

    vector<double> x(n);
    vector<double> y(n);

    cout << "Ingrese los puntos (x, y):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Punto " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    double xi;
    cout << "Ingrese el valor de xi para evaluar el polinomio de Lagrange: ";
    cin >> xi;

    double res = lagrange(x, y, xi);

    cout << "El valor del polinomio de Lagrange en xi es: " << res << endl;

    return 0;
}
