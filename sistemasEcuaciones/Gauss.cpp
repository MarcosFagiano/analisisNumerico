//
// Created by User on 13/9/2023.
//

#include <iostream>
#include <vector>

using namespace std;

void printMatriz(const vector<vector<double>>& matriz, const vector<double>& b) {
    int n = matriz.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << "| " << b[i] << endl;
    }
}


void eliminacionGaussiana(vector<vector<double>>& matriz, vector<double>& b) {
    int n = matriz.size();

    for (int i = 0; i < n; ++i) {
        // Se busca el numero mas grande de la fila
        int maxRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(matriz[j][i]) > abs(matriz[maxRow][i])) {
                maxRow = j;
            }
        }

        // Se cambian filas si es necesario
        if (maxRow != i) {
            swap(matriz[i], matriz[maxRow]);
            swap(b[i], b[maxRow]);
        }

        // Hacer que el elemento diagonal sea igual a 1
        double pivot = matriz[i][i];
        for (int j = i; j < n; ++j) {
            matriz[i][j] /= pivot;
        }
        b[i] /= pivot;

        // Eliminar elementos por debajo del elemento diagonal
        for (int j = i + 1; j < n; ++j) {
            double factor = matriz[j][i];
            for (int k = i; k < n; ++k) {
                matriz[j][k] -= factor * matriz[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    // Sustitución hacia atrás para encontrar las soluciones
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= matriz[i][j] * x[j];
        }
    }

    cout << "Soluciones:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el número de ecuaciones: ";
    cin >> n;

    vector<vector<double>> matriz(n, vector<double>(n));
    vector<double> b(n);

    cout << "Ingrese los coeficientes de la matriz (fila por fila):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    cout << "Ingrese los términos independientes (vector b):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    cout << "Matriz original:" << endl;
    printMatriz(matriz, b);

    eliminacionGaussiana(matriz, b);

    return 0;
}
