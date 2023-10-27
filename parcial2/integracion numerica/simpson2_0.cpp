#include <iostream>
#include <cmath>
#include <iomanip>

// Función a integrar (reemplaza con tu propia función)
double funcion(double x) {
    return exp(0.1*x)*(cos(x));
}

// Método de Simpson para calcular la integral definida
double metodoSimpson(double a, double b, int n) {
    double h = (b - a) / n;
    std::cout << "El h es: " << h << std::endl; // Para verificar que el h sea el correcto
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
    double a, b, error;
    int n;

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

    std::cout << "Ingrese el numero de subintervalos (n): ";
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << "El número de subintervalos debe ser par." << std::endl;
        return 1;
    }

    std::cout << "Ingrese el error a usar: ";
    std::cin >> error;

    double resultado = metodoSimpson(a, b, n);

    std::cout << "El valor aproximado de la integral definida es: " << resultado << std::endl;

    return 0;
}
