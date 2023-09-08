//
// Created by maverick on 9/8/23.
//

#include "display.h"
#include <iostream>
#include <limits>

display::display(){};



unsigned short display::mainMenu() {
    unsigned short op;
    int count=0;
    do {
        clear_display();
        std::cout << "---MENU---\n"
                  << "[1] Raices de ecuaciones.\n"
                  << "[2] Sistema de ecuaciones lineales.\n"
                  << "[3] Ajuste de curvas. \n"
                  << "[4] Diferenciacion numerica.\n"
                  << "[5] Integracion numerica.\n"
                  << "[6] Ecuaciones diferenciales ordinarias.\n"
                  << "[0] Salir.\n"
                  << "Opcion: ";
        std::cin >> op;
        if(op>=0&&op<=6){
            return op;
        }else{
            count++;
            std::cout << "Ingrese un valor valido." << std::endl;
            press_enter_to_continue();
            if(count>2){
                std::cout << "Supero el limite de intentos." << std::endl;
                press_enter_to_continue();
                return 0;
            }
        }
    } while (true);


}

void display::clear_display() {
#ifdef _WIN32
    std::system("cls");
#elif __APPLE__
    std::system("clear");
#elif __linux__
    std::system("clear");
#else
    std::cout << "Sistema operativo desconocido" << std::endl;
#endif
}

void display::press_enter_to_continue() {
    std::cout << "Presione Enter para continuar...";
    getchar();  // Esperar a que se presione Enter
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el búfer de entrada
}





