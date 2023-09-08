#include <iostream>
#include <limits>
#include "display.h"
//template<class T>
//T get_input(std::string msg, std::string err) {
//    while (true){
//        std::cout << msg;
//        T x{};
//        std::cin >> x;
//        if(!std::cin){
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            std::cerr << err;
//        }else{
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            return x;
//        }
//    }
//}
int main() {
    display m;
    std::cout << "---Analisis numerico---" << std::endl;
    unsigned short op=m.mainMenu();
    do{
        if(op==1){
            m.raices();
        } else if(op==2){
            m.ecuacionesLIneales();
        }else if(op==3){
            m.ajusteCurvas();
        }else if(op==4){
            m.diferenciacionNumerica();
        }else if(op==5){
            m.integracionNumerica();
        }else if(op==6){
            m.ecuacionesDiferenciales();
        }else if(op==0){
            break;
        }
    } while (true);
    return 0;
}
