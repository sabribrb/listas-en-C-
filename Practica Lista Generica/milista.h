#ifndef MILISTA_H_INCLUDED
#define MILISTA_H_INCLUDED
#include "dato.h"

enum estados {NO_INICIALIZADO=-1, FALSE=0 , TRUE};
struct NodoE;  //int(dato) , prox
typedef struct NodoE * No;

struct ListaEncE;
typedef struct ListaEncE * ListaEnc;  //Lista --- inicio-primer nodo, tam

ListaEnc crearLista();
int liberarLista(ListaEnc lista);
No crearNo(Dato item,No prox);

//Insertar (pos- ini- fin)
int insertarInicio(ListaEnc lista, Dato item);
int insertar(ListaEnc lista, int pos, Dato item);
int insertarFinal(ListaEnc lista, Dato item);

//Eliminar en la lista
int removerInicio(ListaEnc lista, Dato* item);
int remover(ListaEnc lista, int pos, Dato* item);
int removerFinal(ListaEnc lista, Dato* item);

//utiles

int estaVacia(ListaEnc lista);
int ordenarLista(ListaEnc lista); //ordenar por id
int obtenerElemento(ListaEnc lista, Dato* item, int pos);
int obtenerTamanio(ListaEnc lista, int* tam);

//Mostrar - imprimir
void imprimir(ListaEnc lista);


#endif // MILISTA_H_INCLUDED
