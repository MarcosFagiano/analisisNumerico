#include <iostream>
#include <cmath>
#include <vector>

// Función que se integrará
double f(double x) {
    return 8 + 5 * cos(x);
}

// Función para el método de Simpson
double metodoSimpson(double a, double b, int n, double &error, std::vector<double> &function_values) {
    if (n % 2 != 0) {
        std::cerr << "El número de subintervalos (n) debe ser un número par." << std::endl;
        return 0.0;
    }

    double h = (b - a) / n;
    double integral = f(a) + f(b);

    function_values.push_back(f(a));

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            integral += 2.0 * f(x);
        } else {
            integral += 4.0 * f(x);
        }

        function_values.push_back(f(x));
    }

    integral *= h / 3.0;

    // Estimación del error
    double integral_n_minus_1 = integral;

    // Calcula la integral con n subintervalos (original)
    double integral_n = f(a) + f(b);

    for (int i = 1; i < n - 1; i++) {
        double x = a + (i + 1) * h;
        if (i % 2 == 0) {
            integral_n += 2.0 * f(x);
        } else {
            integral_n += 4.0 * f(x);
        }
    }

    integral_n *= h / 3.0;

    // Estima el error
    error = (1.0 / 15.0) * std::abs(integral_n - integral_n_minus_1);

    return integral;
}

int main() {
    double a, b;
    int n;

    std::cout << "Ingrese el valor de a: ";
    std::cin >> a;
    std::cout << "Ingrese el valor de b: ";
    std::cin >> b;
    std::cout << "Ingrese el número de subintervalos (n, un número par): ";
    std::cin >> n;

    if (n <= 0 || n % 2 != 0) {
        std::cerr << "El número de subintervalos (n) debe ser un número par positivo." << std::endl;
        return 1;
    }

    double error;
    std::vector<double> function_values;

    double resultado = metodoSimpson(a, b, n, error, function_values);

    std::cout << "Resultado de la integración (método de Simpson): " << resultado << std::endl;
    std::cout << "Error estimado: " << error << std::endl;

    // Imprimir la tabla de valores de la función
    std::cout << "Tabla de valores de la función en los subintervalos:" << std::endl;
    for (int i = 0; i <= n; i++) {
        double x = a + i * (b - a) / n;
        std::cout << "Subintervalo " << i << ": x = " << x << ", f(x) = " << function_values[i] << std::endl;
    }

    return 0;
}
