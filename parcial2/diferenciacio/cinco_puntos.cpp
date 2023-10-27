#include <iostream>
#include <cmath>
#include <iomanip> 

// Función
double f(double x)
{
    return exp(0.1*x)*cos(cos(x));
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
    std::cout << "Ingrese el limite inferior (a). (ingrese 'pi' si desea usar pi): ";
    std::string input_a;
    std::cin >> input_a;

    if (input_a == "pi") {
        std::cout << "Ingrese el número por el cual desea multiplicar pi: ";
        double factor;
        std::cin >> factor;
        a = M_PI * factor;
    }
    else {
        a = std::stod(input_a);
    }

    std::cout << "Ingrese el limite superior (b). (ingrese 'pi' si desea usar pi): ";
    std::string input_b;
    std::cin >> input_b;

    if (input_b == "pi") {
        std::cout << "Ingrese el número por el cual desea multiplicar pi: ";
        double factor;
        std::cin >> factor;
        b = M_PI * factor;
    }
    else {
        b = std::stod(input_b);
    }

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