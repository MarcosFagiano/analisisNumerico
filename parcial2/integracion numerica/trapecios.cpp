#include <iostream>
#include <cmath>
#include <vector>

// Función que se integrará
double f(double x) {
    return (8 + 5 * cos(x)); // Puedes cambiar esta función a la que necesites integrar
}

// Función para el método de los trapecios
double metodoTrapecios(double a, double b, int n, double &error, std::vector<double> &second_derivatives) {
    double h = (b - a) / n;
    double integral = 0.5 * (f(a) + f(b));

    // Calcular la segunda derivada en los puntos del extremo
    double second_derivative_a = -5 * cos(a); // Cambia esto para calcular la segunda derivada en 'a'
    double second_derivative_b = -5 * cos(b); // Cambia esto para calcular la segunda derivada en 'b'

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += f(x);

        // Calcular la segunda derivada en el punto x
        double second_derivative_x = -5 * cos(x); // Cambia esto para calcular la segunda derivada en 'x'
        second_derivatives.push_back(second_derivative_x);
    }

    integral *= h;

    // Cálculo del error
    double max_second_derivative = std::max(second_derivative_a, second_derivative_b);
    for (double derivative : second_derivatives) {
        if (derivative > max_second_derivative) {
            max_second_derivative = derivative;
        }
    }

    error = (-((b - a) * (b - a) * (b - a)) / (12.0 *( n * n))) * max_second_derivative;

    return integral;
}

int main() {
    double a, b;
    int n;

    std::cout << "Ingrese el valor de a: ";
    std::cin >> a;
    std::cout << "Ingrese el valor de b: ";
    std::cin >> b;
    std::cout << "Ingrese el número de subintervalos (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "El número de subintervalos (n) debe ser positivo." << std::endl;
        return 1;
    }

    double error;
    std::vector<double> second_derivatives;

    double resultado = metodoTrapecios(a, b, n, error, second_derivatives);

    std::cout << "Resultado de la integración: " << resultado << std::endl;
    std::cout << "Error estimado: " << error << std::endl;

    // Imprimir la tabla de valores de la segunda derivada
    std::cout << "Tabla de la segunda derivada en los subintervalos:" << std::endl;
    for (int i = 0; i < n; i++) {
        double x = a + i * (b - a) / n;
        std::cout << "Subintervalo " << i + 1 << ": x = " << x << ", f''(x) = " << second_derivatives[i] << std::endl;
    }

    return 0;
}
