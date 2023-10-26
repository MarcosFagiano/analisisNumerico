#include <iostream>
#include <cmath>

// Función para calcular la derivada utilizando el método de tres puntos
double DiferenciacionTresPuntos(double f(double), double x, double h)
{
    return (f(x + h) - f(x - h)) / (2 * h);
}

// Funcion
double f(double x)
{
    return exp(x)*cos(x);
}

int main()
{

    double a, b, h;

    std::cout << "Ingrese el valor de a (inicio del intervalo): ";
    std::cin >> a;

    std::cout << "Ingrese el valor de b (final del intervalo): ";
    std::cin >> b;

    std::cout << "Ingrese el valor de h (el espaciado entre puntos cercanos): ";
    std::cin >> h;

    // Se hace un bucle en el cual la derivada se va a analizar en todo el intervalo [a, b]
    for (double x = a; x <= b; x += h)
    {
        double derivada = DiferenciacionTresPuntos(f, x, h);
        std::cout << "La derivada en x = " << x << " es: " << derivada << std::endl;
    }

    return 0;
}
