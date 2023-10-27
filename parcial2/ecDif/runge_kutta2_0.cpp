#include <iostream>
#include <vector>
#include <cmath>
// Función que representa la ecuación diferencial dy/dx = f(x, y)
double f(double x, double y)
{
    // Cambia esta función de acuerdo a la ecuación diferencial que desees resolver
    return x + pow(y,2);
}

// Método de Runge-Kutta de segundo orden
void rungeKutta2(double a, double b, double h, double y0)
{
    double x = a;
    double y = y0;

    std::vector<double> x_values;
    std::vector<double> y_values;

    while (x <= b)
    {
        x_values.push_back(x);
        y_values.push_back(y);

        double k1 = h * f(x, y);
        double k2 = h * f(x + h, y + k1);

        x = x + h;
        y = y + (k1 + k2) / 2;
    }

    // Imprimir los resultados
    std::cout << "Runge-Kutta de segundo orden:\n";
    std::cout << "x\ty\n";
    for (int i = 0; i < x_values.size(); i++)
    {
        std::cout << x_values[i] << "\t" << y_values[i] << "\n";
    }
}

// Método de Runge-Kutta de tercer orden
void rungeKutta3(double a, double b, double h, double y0)
{
    double x = a;
    double y = y0;

    std::vector<double> x_values;
    std::vector<double> y_values;

    while (x <= b + h)
    {
        x_values.push_back(x);
        y_values.push_back(y);

        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h, y - k1 + 2 * k2);

        y = y + (k1 + 4 * k2 + k3) / 6;
        x = x + h;
    }

    // Imprimir los resultados
    std::cout << "Runge-Kutta de tercer orden:\n";
    std::cout << "x\ty\n";
    for (int i = 0; i < x_values.size(); i++)
    {
        std::cout << x_values[i] << "\t" << y_values[i] << "\n";
    }
}

// Método de Runge-Kutta de cuarto orden
void rungeKutta4(double a, double b, double h, double y0)
{
    double x = a;
    double y = y0;

    std::vector<double> x_values;
    std::vector<double> y_values;

    while (x <= b + h)
    {
        x_values.push_back(x);
        y_values.push_back(y);

        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
    }

    // Imprimir los resultados
    std::cout << "Runge-Kutta de cuarto orden:\n";
    std::cout << "x\ty\n";
    for (int i = 0; i < x_values.size(); i++)
    {
        std::cout << x_values[i] << "\t" << y_values[i] << "\n";
    }
}

int main()
{
    double a, b, h, y0;
    int metodo;

    std::cout << "Ingrese el valor inicial de x (a): ";
    std::cin >> a;

    std::cout << "Ingrese el valor final de x (b): ";
    std::cin >> b;

    std::cout << "Ingrese el paso (h): ";
    std::cin >> h;

    std::cout << "Ingrese la condicion inicial y(0): ";
    std::cin >> y0;

    std::cout << "Seleccione el metodo de Runge-Kutta (2, 3 o 4): ";
    std::cin >> metodo;

    if (metodo == 2)
    {
        rungeKutta2(a, b, h, y0);
    }
    else if (metodo == 3)
    {
        rungeKutta3(a, b, h, y0);
    }
    else if (metodo == 4)
    {
        rungeKutta4(a, b, h, y0);
    }
    
    return 0;
}
