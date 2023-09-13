#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct CubicSplineSegment {
    double a, b, c, d, x;

    double evaluate(double xi) {
        double dx = xi - x;
        return a + b * dx + c * dx * dx + d * dx * dx * dx;
    }
};

// Función para calcular los coeficientes de los segmentos cúbicos
vector<CubicSplineSegment> calcular_segmentos_cubicos(vector<double>& x, vector<double>& y) {
    int n = x.size();
    vector<double> h(n - 1);
    vector<double> alpha(n - 1);
    vector<double> l(n);
    vector<double> mu(n - 1);
    vector<double> z(n);

    for (int i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
        alpha[i] = (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
    }

    l[0] = 1.0;
    mu[0] = 0.0;
    z[0] = 0.0;

    for (int i = 1; i < n - 1; i++) {
        l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n - 1] = 1.0;
    z[n - 1] = 0.0;
    vector<CubicSplineSegment> segmentos(n);

    for (int j = n - 2; j >= 0; j--) {
        segmentos[j].a = y[j];
        segmentos[j].b = (y[j + 1] - y[j]) / h[j] - h[j] * (z[j + 1] + 2.0 * z[j]) / 3.0;
        segmentos[j].c = z[j];
        segmentos[j].d = (z[j + 1] - z[j]) / (3.0 * h[j]);
        segmentos[j].x = x[j];
    }

    return segmentos;
}

int main() {
    vector<double> x = {0.0, 1.0, 2.0, 3.0};
    vector<double> y = {1.0,2.7182,7.3891,20.0855};

    vector<CubicSplineSegment> segmentos = calcular_segmentos_cubicos(x, y);

    // Evaluar la interpolación cúbica en un punto, por ejemplo, x = 1.5
    double punto_evaluado = 0.5;
    int segmento = 0;

    // Encontrar el segmento adecuado
    for (int i = 0; i < x.size() - 1; i++) {
        if (punto_evaluado >= x[i] && punto_evaluado <= x[i + 1]) {
            segmento = i;
            break;
        }
    }

    double resultado = segmentos[segmento].evaluate(punto_evaluado);

    cout << "El valor interpolado en x = " << punto_evaluado << " es " << resultado << endl;

    return 0;
}
