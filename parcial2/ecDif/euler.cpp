#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// Función que define la EDO dy/dx = x + y
double f(double x, double y)
{
    return exp(0.8 * x) - 0.5 * y;
}

int main()
{
    double a;      // Valor inicial del intervalo
    double b;      // Valor final del intervalo
    double x0 = a; // Valor inicial de x
    double y0;     // Valor inicial de y
    double h;      // Tamaño del paso

    std::cout << "Ingrese el valor inicial del intervalo [a,b]: " << std::endl;
    std::cin >> a;
    std::cout << "Ingrese el valor final del intervalo [a,b]: " << std::endl;
    std::cin >> b;
    std::cout << "Ingrese el valor de la condicion y(0): " << std::endl;
    std::cin >> y0;
    std::cout << "Ingrese el tamanio del paso: " << std::endl;
    std::cin >> h;

    std::vector<double> x_values;
    std::vector<double> y_values;

    x_values.push_back(x0);
    y_values.push_back(y0);

    while (x0 < b)
    {
        double x = x_values.back();
        double y = y_values.back();
        double dydx = f(x, y);

        if (x + h > b)
        {
            h = b - x; // Ajustar el tamaño del paso para que no exceda el valor final del intervalo
        }

        x0 = x + h;
        y0 = y + h * dydx;

        x_values.push_back(x0);
        y_values.push_back(y0);
    }

    // Imprimir los resultados

    std::cout << std::left << std::setw(8) << "Xi"
              << "Yi+1" << std::endl;
    std::cout << "-------------------------" << std::endl;

    for (size_t i = 0; i < x_values.size(); i++)
    {
        std::cout << std::left << std::setw(8) << x_values[i] << " " << y_values[i] << std::endl;
    }

    return 0;
}
