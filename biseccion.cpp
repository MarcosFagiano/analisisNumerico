#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return log(x)*sin(x);
}

int main()
{
    double a, b, c, errorEstimado = pow(10, -3), ancho, error, aux;
    int intervalos = 10, puntos;
    bool flag = false;
    puntos = intervalos + 1;

    cout << "Ingrese los valores de a y b del intervalo [a,b]\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    c = (a + b) / 2;

    ancho = (b - a) / intervalos;
    // mostrar valores
    cout << "\tx\t\tf(x)\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\t" << a << "\t" << f(a) << endl;
        a += ancho;
    }

    cout << "Ingrese el intervalo correcto: "
         << "\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    c = (a + b) / 2;
    if ((f(a) * f(b)) > 0)
    {
        cout << "ERROR! Los extremos del intervalo tienen el mismo signo, por lo tanto no hay ningun cero/raiz";
    }
    else
    {
        cout << "\n\ta\tb\tc\t\tf(a)\t\tf(c)\t\tf(a) * f(c)\t\t|E|\t\t\n\n";
        do
        {
            if ((f(a) * f(c)) < 0)
            {
                b = c;
                aux = c;
            }
            else
            {
                a = c;
                aux = c;
            }
            c = (a + b) / 2;
            error = aux - c;
            if (abs(error) <= errorEstimado)
                flag = true;
            cout << "\t" << a << "\t" << b << "\t" << c << "\t\t" << f(a) << "\t" << f(c) << "\t" << f(a) * f(c) << "\t" << error << "\n";
        } while (flag != true);

        cout << "\nHay una raiz en x = " << c;
    }

    return 0;
}