#include <iostream>
#include <cmath>
using namespace std;

// Función objetivo que queremos encontrar su raíz
double f(double x) {
    return sin(x);
}

// Implementación del método de la secante
double secante(double x0, double x1, double epsilon, int maxIter) {
    double x2;
    int iter = 0;

    do {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
        iter++;
    } while (fabs(f(x2)) > epsilon && iter < maxIter);

    return x2;
}

int main() {
    double x0 = 1; // Valor inicial
    double x1 = 4.0; // Otro valor inicial cercano
    double epsilon = 1e-6; // Tolerancia para la convergencia
    int maxIter = 100; // Número máximo de iteraciones

    double raiz = secante(x0, x1, epsilon, maxIter);

    if (fabs(f(raiz)) < epsilon) {
        cout << "La raíz encontrada es: " << raiz << endl;
    } else {
        cout << "El método de la secante no convergió." << endl;
    }

    return 0;
}
