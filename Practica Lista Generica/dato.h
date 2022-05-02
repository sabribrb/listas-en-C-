#ifndef DATO_H_INCLUDED
#define DATO_H_INCLUDED

struct DatoEstructura;
typedef struct DatoEstructura * Dato;

//Constructor
Dato crearDato(int ident);
//Destructor
//Modificar
//mostrar
void mostrarDato(Dato d);
//getters
int getID(Dato d);
//setters

#endif // DATO_H_INCLUDED
