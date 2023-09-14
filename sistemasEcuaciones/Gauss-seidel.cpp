#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<double>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el número de ecuaciones: ";
    cin >> n;

    // Crear una matriz aumentada para el sistema de ecuaciones
    vector<vector<double>> matriz(n, vector<double>(n + 1));

    // Entrada de coeficientes y términos independientes
    cout << "Ingrese los coeficientes de las ecuaciones:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Ingrese el coeficiente A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
        cout << "Ingrese el término independiente B[" << i + 1 << "]: ";
        cin >> matriz[i][n];
    }

    // Inicialización de valores iniciales
    vector<double> x(n, 0);
    vector<double> xNuevo(n);

    // Criterio de parada y número máximo de iteraciones
    double tolerancia, error = 1;
    int iteracionesMax;
    cout << "Ingrese la tolerancia: ";
    cin >> tolerancia;
    cout << "Ingrese el número máximo de iteraciones: ";
    cin >> iteracionesMax;

    // Iteraciones del método de Gauss-Seidel
    int iteracion = 0;
    while (error > tolerancia && iteracion < iteracionesMax) {
        for (int i = 0; i < n; i++) {
            double suma = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    suma += matriz[i][j] * x[j];
                }
            }
            xNuevo[i] = (matriz[i][n] - suma) / matriz[i][i];
        }

        error = 0;
        for (int i = 0; i < n; i++) {
            error += abs(xNuevo[i] - x[i]);
            x[i] = xNuevo[i];
        }

        iteracion++;
    }

    if (error <= tolerancia) {
        cout << "La solución aproximada es:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "x[" << i + 1 << "] = " << x[i] << endl;
        }
        cout << "Número de iteraciones: " << iteracion << endl;
    } else {
        cout << "El método no convergió después de " << iteracionesMax << " iteraciones." << endl;
    }

    return 0;
}
