#include <iostream>
#include <cmath>
#include <iomanip>
// Función que representa la función a integrar. Debes editar esta función según tu necesidad.
double funcion(double x)
{
    return 8 + 5 * cos(x);
}

// Función para calcular la integral definida utilizando el método de los trapecios.
double integralPorTrapecios(double a, double b, int n)
{
    double h = (b - a) / n;
    double integral = 0.5 * (funcion(a) + funcion(b));

    std::cout << "i\t  xi\t    f(xi)\n-------------------------\n";
    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        integral += funcion(x);
        std::cout << i << "\t" << std::fixed << std::setprecision(4) << x << "\t" << std::fixed << std::setprecision(4) << funcion(x) << "\n";
    }

    integral *= h;

    return integral;
}

int main()
{
    double a, b;
    int n;

    std::cout << "Ingrese el limite inferior (a). Si quieres introducir el numero pi, escribe pi: ";
    std::string input;
    std::cin >> input;

    if (input == "pi")
    {
        a = M_PI;
    }
    else
    {
        a = std::stod(input); // Convierte la entrada a double
    }

    std::cout << "Ingrese el limite superior (b). Si quieres introducir el numero pi, escribe pi: ";
    std::cin >> input;

    if (input == "pi")
    {
        b = M_PI;
    }
    else
    {
        b = std::stod(input); // Convierte la entrada a double
    }

    std::cout << "Ingrese el numero de trapecios (n): ";
    std::cin >> n;

    if (n <= 0)
    {
        std::cout << "El numero de trapecios debe ser mayor que 0." << std::endl;
        return 1;
    }

    double resultado = integralPorTrapecios(a, b, n);

    std::cout << "Aproximacion de la integral definida: " << resultado << std::endl;

    return 0;
}
