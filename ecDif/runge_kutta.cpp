#include <iostream>
#include <cmath>

// Función que define la EDO (debes modificar esta función según tu problema)
double f(double x, double y) {
    return exp(0.8*x)-0.50*y; // Ejemplo de EDO: dy/dx = x + y
}

// Método de Runge-Kutta de segundo orden (Punto Medio)
double rungeKutta2ndOrder(double x0, double y0, double h, double x_target) {
    while (x0 < x_target) {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + 0.5 * h, y0 + 0.5 * k1);

        y0 = y0 + k2;
        x0 = x0 + h;
    }
    return y0;
}

double rungeKutta3rdOrder(double x0, double y0, double h, double x_target) {
    while (x0 < x_target) {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + 0.5 * h, y0 + 0.5 * k1);
        double k3 = h * f(x0 + h, y0 - k1 + 2 * k2);

        y0 = y0 + (1.0 / 6.0) * (k1 + 4 * k2 + k3);
        x0 = x0 + h;
    }
    return y0;
}

double rungeKutta4thOrder(double x0, double y0, double h, double x_target) {
    while (x0 < x_target) {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + 0.5 * h, y0 + 0.5 * k1);
        double k3 = h * f(x0 + 0.5 * h, y0 + 0.5 * k2);
        double k4 = h * f(x0 + h, y0 + k3);

        y0 = y0 + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
    }
    return y0;
}


int main() {
    double xa = 0.0; // Valor inicial de x
    double y0 = 2.0; // Valor inicial de y
    double h = 0.1; // Tamaño del paso (ajusta según tus necesidades)
    double xb = 4; //valor final de x

    for(auto x=xa; x<xb; x+=h){
      std::cout << "Solución en x = " << x
      << "| y = " << rungeKutta2ndOrder(xa, y0, h, x)
      << "| k1 = " << h * f(xa, y0)
      << "| k2 = " << h * f(xa + 0.5 * h, y0 + 0.5 * (h * f(xa, y0)))
      << std::endl;
    }

    return 0;
}
