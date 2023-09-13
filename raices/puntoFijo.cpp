#include <iostream>
#include <cmath>

using namespace std;

// Define la función f(x) que deseas encontrar su raíz.
double f(double x) {
    return exp(-x)-x;
}

// Define la función g(x) que tiene un punto fijo en la raíz de f(x).
double g(double x) {
    return exp(-x);  // Puedes elegir diferentes funciones g(x).
}

int main() {
    double x0;  // Estimación inicial.
    cout << "Ingrese el valor inicial x0: ";
    cin >> x0;

    int iteracionesMaximas;
    cout << "Ingrese el número máximo de iteraciones: ";
    cin >> iteracionesMaximas;

    double tolerancia;
    cout << "Ingrese la tolerancia deseada: ";
    cin >> tolerancia;

    double x = x0;
    int iteracion = 0;

    while (iteracion < iteracionesMaximas) {
        double xNuevo = g(x);
        double error = abs(xNuevo - x);

        cout << "Iteración " << iteracion << ": x = " << x << ", f(x) = " << f(x) << ", error = " << error << endl;

        if (error < tolerancia) {
            cout << "La raíz aproximada es: " << xNuevo << endl;
            break;
        }

        x = xNuevo;
        iteracion++;
    }

    if (iteracion == iteracionesMaximas) {
        cout << "El método no convergió después de " << iteracionesMaximas << " iteraciones." << endl;
    }

    return 0;
}
