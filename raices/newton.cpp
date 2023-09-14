#include <iostream>
#include <cmath>

using namespace std;

double derivada(double Xi) {
    return -exp(-Xi) - 1 ;
}

double funcion(double Xi) {
    return exp(-Xi) - Xi;
}

int main() {
    double x, Xi, E;

    cout << "Ingrese el primer valor para evaluar: ";
    cin >> x;

    E = 2;
    Xi = x;
    
     do  {
        cout << "El punto donde se valúa es: " << Xi << endl;
        cout << "Función evaluada: " << funcion(Xi) << endl; // Aquí debes evaluar la función en Xi
        cout << "Derivada evaluada: " << derivada(Xi) << endl; // Aquí debes evaluar la derivada en Xi
        cout << "Error actual: " << E << endl;
        
        Xi = x - (funcion(Xi) / derivada(Xi));
        E = abs(Xi - x);
        x = Xi;
        cout << "BLYAAAAT" << endl;
    } while (E > 0.000001);
    return 0;
    
}