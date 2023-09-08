#include <iostream>
#include "menu.h"

int main(int argc, char **argv){
    std::cout << "---Analisis numerico---" << std::endl;
    if(argc==1||argc==2){
        menu::defaultMenu();
    }else if(argc == 3){
        //programa principal
    }else{
        std::cout << "--Demasiados argumentos.--" << std::endl;
        menu::defaultMenu();
    }

}