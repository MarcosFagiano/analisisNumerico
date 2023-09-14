#include <iostream>
#include <vector>

using namespace std;

// Función para imprimir una matriz
void printMatrix(const vector<vector<double>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Realiza la descomposición LU de una matriz cuadrada A
void lu_decomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        L[i][i] = 1.0;
        for (int j = i; j < n; j++) {
            U[i][j] = A[i][j];
            for (int k = 0; k < i; k++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
        for (int j = i + 1; j < n; j++) {
            L[j][i] = A[j][i];
            for (int k = 0; k < i; k++) {
                L[j][i] -= L[j][k] * U[k][i];
            }
            L[j][i] /= U[i][i];
        }
    }
}

// Resuelve el sistema de ecuaciones lineales LUx = b
vector<double> solve_lu(const vector<vector<double>>& L, const vector<vector<double>>& U, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n);
    vector<double> x(n);

    // Resuelve Ly = b usando sustitución hacia adelante
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }

    // Resuelve Ux = y usando sustitución hacia atrás
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }

    return x;
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n, 0.0));
    vector<double> b(n);

    cout << "Ingrese la matriz A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Ingrese el vector b:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<double>> L(n, vector<double>(n, 0.0));
    vector<vector<double>> U(n, vector<double>(n, 0.0));

    lu_decomposition(A, L, U);
    vector<double> x = solve_lu(L, U, b);

    cout << "Matriz L:" << endl;
    printMatrix(L);

    cout << "Matriz U:" << endl;
    printMatrix(U);

    cout << "Solución:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}
