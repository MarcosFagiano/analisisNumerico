#include <iostream>
#include <cmath>

// Función f(x) = e^x * cos(x)
double f(double x) {
    return std::exp(x) * std::cos(x);
}

// Función para calcular la derivada numérica usando la fórmula de cinco puntos
double DerivadaCincoPuntos(double x, double h) {
    return (f(x - 2 * h) - 8 * f(x - h) + 8 * f(x + h) - f(x + 2 * h)) / (12 * h);
}

int main() {
    double h = 0.10000; // El paso es 0.1

    // Calcular la derivada en los extremos del intervalo
    double x1 = 0.0;
    double x2 = 0.7;

    for(double x=x1; x<=x2; x+=h){
      std::cout << "x; " << x << " fx: " << f(x)<< " x': " << DerivadaCincoPuntos(x, h) << std::endl;
    }

    return 0;
}
