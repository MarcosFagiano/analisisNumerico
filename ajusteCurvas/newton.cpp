#include <iostream>
#include <vector>

using namespace std;

// Función para calcular las diferencias divididas
vector<double> diferencias_divididas(vector<double>& x, vector<double>& y) {
    int n = x.size();
    vector<double> coeficientes(n, 0.0);

    // Inicializar la primera columna de la tabla de diferencias divididas con los valores de y
    for (int i = 0; i < n; i++) {
        coeficientes[i] = y[i];
    }

    // Calcular las diferencias divididas
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            coeficientes[i] = (coeficientes[i] - coeficientes[i - 1]) / (x[i] - x[i - j]);
        }
    }

    return coeficientes;
}

// Función para evaluar el polinomio interpolante en un punto x
double evaluar_polinomio(vector<double>& coeficientes, vector<double>& x, double punto) {
    int n = x.size();
    double resultado = 0.0;
    double termino = 1.0;

    for (int i = 0; i < n; i++) {
        resultado += coeficientes[i] * termino;
        termino *= (punto - x[i]);
    }

    return resultado;
}

int main() {
    vector<double> x = {0.0, 1.0, 2.0, 3.0};
    vector<double> y = {1,2.7182,7.3892,20.0860};

    vector<double> coeficientes = diferencias_divididas(x, y);

    // Evaluar el polinomio interpolante en un punto, por ejemplo, x = 2.5
    double punto_evaluado = 0.99;
    double resultado = evaluar_polinomio(coeficientes, x, punto_evaluado);

    cout << "El valor interpolado en x = " << punto_evaluado << " es " << resultado << endl;

    return 0;
}
