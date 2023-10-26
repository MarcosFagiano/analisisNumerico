#include <iostream>
#include <cmath>
#include <iomanip>

// Función a integrar (reemplaza con tu propia función)
double funcion(double x) {
    return 8 + 5 * cos(x);
}

// Método de Simpson para calcular la integral definida
double metodoSimpson(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = funcion(a) + funcion(b); // Puntos extremos

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            integral += 2 * funcion(x); // Suma de pares
        } else {
            integral += 4 * funcion(x); // Suma de impares
        }
    }

    integral *= h / 3.0;
    return integral;
}

int main() {
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

    if (n % 2 != 0) {
        std::cout << "El número de subintervalos debe ser par." << std::endl;
        return 1;
    }

    double resultado = metodoSimpson(a, b, n);

    std::cout << "El valor aproximado de la integral definida es: " << resultado << std::endl;

    return 0;
}