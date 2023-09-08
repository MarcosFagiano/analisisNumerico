//
// Created by maverick on 9/8/23.
//

#include "menu.h"
#include <iostream>
void menu::defaultMenu() {
    std::cout << "Uso: analisisNumerico --[Metodo] -[Funcion]\n"
                 "Especificacion de metodo: " << std::endl;

    std::cout << "[1] RAICES: \n"
                 "\t--B  : Metodo de biseccion.\n"
                 "\t--Pf : Metodo de punto fijo.\n"
                 "\t--NR : Metodo de Newton Raphson.\n"
                 "\t--S  : Metodo de la secante.\n" << std::endl;

    std::cout << "[2] ECACIONES LINEALES: \n"
                 "\t--Eg : Eliminnacion Gaussiana.\n"
                 "\t--GS : Gauss Seidel. \n"
                 "\t--LU : LU.\n" <<std::endl;

    std::cout << "[3] AJUSTE DE CURVAS: \n"
                 "\t--Rl : Regresion lineal.\n"
                 "\t--PN : Polinomio de Newton o Diferencias divididas.\n"
                 "\t--PL : Polinomio de Lagrange.\n"
                 "\t--Is : Interpolacion segmentaria.\n" <<std::endl;
}
