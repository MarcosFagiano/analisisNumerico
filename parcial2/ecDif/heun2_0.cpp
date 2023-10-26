#include <iostream>
#include <cmath>

// Función que define la ecuación diferencial: dy/dx = x^2 + y
double f(double x, double y) {
    return exp(0.8*x)-0.5*y;
}

// Método de Heun para resolver la ecuación diferencial en un intervalo [a, b]
void solveODE(double y0, double h, double a, double b) {
    double x = a;
    double y = y0;

    while (x < b) {
        // Predicción de y utilizando el método de Euler
        double y_pred = y + h * f(x, y);

        // Corrección de y utilizando el método de Euler modificado
        y = y + 0.5 * h * (f(x, y) + f(x + h, y_pred));

        x += h;

        std::cout << "x = " << x << ", y = " << y << std::endl;
    }
}

int main() {
    double y0, h, a, b;

    std::cout << "Ingrese el valor inicial de y: ";
    std::cin >> y0;
    
    std::cout << "Ingrese el valor de h (tamaño del paso): ";
    std::cin >> h;

    std::cout << "Ingrese el valor inicial del intervalo [a, b] (a): ";
    std::cin >> a;

    std::cout << "Ingrese el valor final del intervalo [a, b] (b): ";
    std::cin >> b;

    if (a >= b) {
        std::cerr << "El valor de a debe ser menor que b." << std::endl;
        return 1;
    }

    solveODE(y0, h, a, b);

    return 0;
}
