#include <iostream>
#include <cmath>

// Función
double f(double x)
{
    return exp(x) * cos(x);
}

// Función para calcular la derivada usando la fórmula de cinco puntos
double DerivadaCincoPuntos(double x, double h)
{
    return (f(x - 2 * h) - 8 * f(x - h) + 8 * f(x + h) - f(x + 2 * h)) / (12 * h);
}

int main()
{
    double a, b, h;

    // Se introducen los valores de los intervalos y el h, respectivamente
    std::cout << "Ingrese el valor de a (inicio del intervalo): ";
    std::cin >> a;

    std::cout << "Ingrese el valor de b (final del intervalo): ";
    std::cin >> b;

    std::cout << "Ingrese el valor de h (el espaciado entre puntos cercanos): ";
    std::cin >> h;

    // Se hace un bucle en el cual la derivada se va a analizar en todo el intervalo [a, b]
    for (double x = a; x <= b; x += h)
    {
        std::cout << "y'(" << x << ") = " << DerivadaCincoPuntos(x, h) << std::endl;
    }

    return 0;
}
