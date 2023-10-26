#include <iostream>
#include <cmath>
#include <iomanip>

double funcion(double x)
{
    // Define aquí la función cuya derivada quieres calcular
    return pow((3 * x - 1) / (pow(x, 2) + 1), 2); // Ejemplo: x^2
}

double derivadaNumerica(double x, double h)
{
    double f_x_plus_h = funcion(x + h);
    double f_x_minus_h = funcion(x - h);

    return (f_x_plus_h - f_x_minus_h) / (2 * h);
}

int main()
{
    double a, b, h;

    std::cout << "Introduce el intervalo [a, b]\n";
    std::cout << "Introduce el valor de a: ";
    std::cin >> a;
    std::cout << "Introduce el valor de b: ";
    std::cin >> b;
    std::cout << "Introduce el valor de h: ";
    std::cin >> h;

    // Se muestran los resultados
    std::cout << "x\t\tf(x)\t\tf'(x)" << std::endl;
    std::cout << "-\t\t----\t\t-----" << std::endl; // Línea divisoria
    for (double x = a; x <= b; x += h)
    {
        double resultado = derivadaNumerica(x, h);
        std::cout << std::fixed << std::setprecision(5); // Ajusta la precisión de salida
        std::cout << x << "\t\t" << funcion(x) << "\t\t" << resultado << std::endl;
    }

    return 0;
}
