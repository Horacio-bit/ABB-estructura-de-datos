//
// Created by Rodrigo Calles on 2020-11-18.
//

#ifndef UNTITLED_EXCEPCION_H
#define UNTITLED_EXCEPCION_H

#include <cstring>


class Excepcion {
public:
    Excepcion(const char *msn){ strcpy(mensaje,msn); }
    const char * quePaso(){ return mensaje; }
private:
    char mensaje[100];
};



#endif //UNTITLED_EXCEPCION_H
