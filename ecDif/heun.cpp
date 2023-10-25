#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

// Función que implementa el método de Heun para resolver EDOs
std::vector<double> solveODE(std::function<double(double, double)> f, double y0, double a, double b, double h)
{
    std::vector<double> result;
    double t = a;
    double y = y0;

    while (t < 5)
    {
        result.push_back(y);

        double k1 = h * f(t, y);
        double k2 = h * f(t + h, y + k1);
        y += 0.5 * (k1 + k2);

        t += h;
    }

    return result;
}

// Funcion
double funcion(double t, double y)
{
    return exp(0.8 * t) - 0.5 * y;
}

int main()
{
    double a, b, y0, h;

    std::cout << "Ingrese el valor de a: ";
    std::cin >> a;

    std::cout << "Ingrese el valor de b: ";
    std::cin >> b;

    std::cout << "Ingrese el valor inicial y(a): ";
    std::cin >> y0;

    std::cout << "Ingrese el tamaño del paso h: ";
    std::cin >> h;

    std::vector<double> solution = solveODE(funcion, y0, a, b, h);

    std::cout << "Solución de la EDO usando el método de Heun:\n";
    for (double t = a; t <= b; t += h)
    {
        std::cout << "y(" << t << ") = " << solution[static_cast<int>((t - a) / h)] << std::endl;
    }

    return 0;
}
