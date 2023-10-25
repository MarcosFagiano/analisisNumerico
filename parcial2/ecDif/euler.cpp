#include <iostream>
#include <vector>
#include <cmath>

// Función que define la EDO dy/dx = x + y
double f(double x, double y) {
    return y*pow(2, x) - y;
}

int main() {
    double a = 0.0;  // Valor inicial del intervalo
    double b = 1.0;  // Valor final del intervalo
    double x0 = a;   // Valor inicial de x
    double y0 = 0.0;  // Valor inicial de y
    double h = 0.01;  // Tamaño del paso

    /*
    std::cout << "Ingrese el valor inicial del intervalo [a,b]: " << std::endl;
    std::cin >> a;
    std::cout << "Ingrese el valor final del intervalo [a,b]: " << std::endl;
    std::cin >> b;
    std::cout << "Ingrese el valor de la condicion: " << std::endl;
    std::cin >> y0;
    std::cout << "Ingrese el tamaño del paso: " << std::endl;
    std::cin >> h;
    */

    std::vector<double> x_values;
    std::vector<double> y_values;

    x_values.push_back(x0);
    y_values.push_back(y0);

    while (x0 < b) {
        double x = x_values.back();
        double y = y_values.back();
        double dydx = f(x, y);

        if (x + h > b) {
            h = b - x; // Ajustar el tamaño del paso para que no exceda el valor final del intervalo
        }

        x0 = x + h;
        y0 = y + h * dydx;

        x_values.push_back(x0);
        y_values.push_back(y0);
    }

    // Imprimir los resultados
    for (size_t i = 0; i < x_values.size(); i++) {
        std::cout << "x = " << x_values[i] << ", y = " << y_values[i] << std::endl;
    }

    return 0;
}
