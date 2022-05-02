#include <iostream>
#include "milista.h"
using namespace std;

int main()
{
   ///cambiar el int item por un item de cualquier estructura
   /// buscar y ordenar
   ListaEnc lis1=crearLista();
   insertarInicio(lis1,crearDato(45));
   insertarInicio(lis1,crearDato(70));
   insertarInicio(lis1,crearDato(100));
   insertarInicio(lis1,crearDato(8));
    insertar(lis1, 1,crearDato(78));
ordenarLista(lis1);
   imprimir(lis1);
    return 0;
}
