//
// Created by maverick on 9/8/23.
//

#ifndef ANALISISNUMERICO_DISPLAY_H
#define ANALISISNUMERICO_DISPLAY_H
#include <string>

class display{
private:
    std::string m_argv;
    bool validArgv();
public:
    display();
    unsigned short mainMenu();

    void raices();
    void ecuacionesLIneales();
    void ajusteCurvas();
    void diferenciacionNumerica();
    void integracionNumerica();
    void ecuacionesDiferenciales();

//    template<class T>
//    T get_input(std::string msg, std::string err, unsigned short);
    void clear_display();

    void press_enter_to_continue();
};
#endif //ANALISISNUMERICO_DISPLAY_H
