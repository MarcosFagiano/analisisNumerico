//
// Created by User on 13/9/2023.
//

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<double>>& matrix, const vector<double>& b) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "| " << b[i] << endl;
    }
}


void gaussianElimination(vector<vector<double>>& matrix, vector<double>& b) {
    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
        // Buscar el elemento máximo en la columna actual
        int maxRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(matrix[j][i]) > abs(matrix[maxRow][i])) {
                maxRow = j;
            }
        }

        // Intercambiar filas si es necesario
        if (maxRow != i) {
            swap(matrix[i], matrix[maxRow]);
            swap(b[i], b[maxRow]);
        }

        // Hacer que el elemento diagonal sea igual a 1
        double pivot = matrix[i][i];
        for (int j = i; j < n; ++j) {
            matrix[i][j] /= pivot;
        }
        b[i] /= pivot;

        // Eliminar elementos por debajo del elemento diagonal
        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i];
            for (int k = i; k < n; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    // Sustitución hacia atrás para encontrar las soluciones
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= matrix[i][j] * x[j];
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

    vector<vector<double>> matrix(n, vector<double>(n));
    vector<double> b(n);

    cout << "Ingrese los coeficientes de la matriz (fila por fila):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Ingrese los términos independientes (vector b):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    cout << "Matriz original:" << endl;
    printMatrix(matrix, b);

    gaussianElimination(matrix, b);

    return 0;
}
