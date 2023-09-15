#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para calcular la media de un vector
double media(const vector<double>& data) {
    double suma = 0.0;
    for (const double& valor : data) {
        suma += valor;
    }
    return suma / data.size();
}

// Función para calcular la covarianza entre dos vectores
double covarianza(const vector<double>& x, const vector<double>& y) {
    if (x.size() != y.size() || x.empty()) {
        cerr << "Los vectores deben tener la misma longitud y no pueden estar vacíos." << endl;
        return 0.0;
    }

    double media_x = media(x);
    double media_y = media(y);
    double covarianza = 0.0;

    for (size_t i = 0; i < x.size(); ++i) {
        covarianza += (x[i] - media_x) * (y[i] - media_y);
    }

    return covarianza / (x.size() - 1);
}

// Función para calcular la pendiente y la intersección de la regresión lineal
void regresion(const vector<double>& x, const vector<double>& y, double& pendiente, double& interseccion) {
    if (x.size() != y.size() || x.empty()) {
        cerr << "Los vectores deben tener la misma longitud y no pueden estar vacíos." << endl;
        return;
    }

    double covarianza_xy = covarianza(x, y);
    double varianza_x = covarianza(x, x);
    double media_x = media(x);
    double media_y = media(y);

    pendiente = covarianza_xy / varianza_x;
    interseccion = media_y - pendiente * media_x;
}

int main() {
    // Datos de ejemplo
    vector<double> x = {1,2,3,4,5,6,7};
    vector<double> y = {0.5,2.5,2,4,3.5,6,5.5} ;

    // Variables para los coeficientes de la regresión
    double pendiente, interseccion;

    // Calcular la regresión lineal
    regresion(x, y, pendiente, interseccion);

    // Imprimir los resultados
    cout << "Ecuación de la línea de regresión: y = " << pendiente << "x + " << interseccion << endl;

    return 0;
}
