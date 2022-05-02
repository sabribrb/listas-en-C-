#include <cstdio>
#include <cstdlib>
#include "dato.h"

struct DatoEstructura{
    int ID;
    //otros datos
};
Dato crearDato(int ident){
    Dato datoNuevo= new DatoEstructura;
    datoNuevo->ID= ident;
    return datoNuevo;
};
void mostrarDato(Dato d){
    printf("    ID: %d \n", d->ID);
};

int getID(Dato d){
    return d->ID;
};
