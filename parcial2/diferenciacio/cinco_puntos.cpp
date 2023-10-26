#include <iostream>
#include <cmath>
#include <iomanip> 

// Función
double f(double x)
{
    return pow((3*x - 1)/(pow(x,2) + 1),2);
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

    // Se muestran los resultados
    std::cout << "x\t\tf(x)\t\tf'(x)" << std::endl;
    std::cout << "-\t\t----\t\t-----" << std::endl; // Línea divisoria
    for (double x = a; x <= b; x += h)
    {
        std::cout << std::fixed << std::setprecision(5); // Ajusta la precisión de salida
        std::cout << x << "\t\t" << f(x) << "\t\t" << DerivadaCincoPuntos(x, h) << std::endl;
    }

    return 0;
}