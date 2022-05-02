#include <cstdio>
#include <cstdlib>
#include "milista.h"

struct NodoE{

    Dato item;
    No prox;

};

struct ListaEncE{

    int tam;
    No inicio;

};


ListaEnc crearLista(){

    ListaEnc lista = new(struct ListaEncE);//new


    lista->tam = 0;
    lista->inicio = NULL;

    return lista;

};
int liberarLista(ListaEnc lista) {
    if (lista == NULL){
        return NO_INICIALIZADO;}

    while(!estaVacia(lista)){
        remover(lista, 0 , NULL );}

    free(lista);
    lista->inicio = NULL; //El tamañpo ya quedo en cero por los remove tam--



    return TRUE;
}


No crearNo(Dato item,No prox){

    No nodo = new(struct NodoE);

    nodo ->item = item;
    nodo ->prox = prox;



    return nodo;

};

//Insertar (pos- ini- fin)
int insertarInicio(ListaEnc lista, Dato item){

        //verifiquen algo en particular-- null?


        No nuevoNo = crearNo(item, lista->inicio);

        lista-> inicio = nuevoNo;
        lista -> tam++;

        return 1;
};

int insertar(ListaEnc lista, int pos, Dato item){
    if (lista==NULL){
        return NO_INICIALIZADO;
    }
    No nuevoNo;
    if (pos==0){
        return insertarInicio(lista, item);
    }
    else {

        No auxNo= lista->inicio;
        for (int i=0;i<pos-1 ; i++ ){
            auxNo=auxNo->prox;
        }
        nuevoNo= crearNo(item, auxNo->prox);
        if (nuevoNo == NULL)
            return NO_INICIALIZADO;
        auxNo->prox= nuevoNo;
    }
    lista->tam++;
    return TRUE;
};
int insertarFinal(ListaEnc lista, Dato item){
    if (lista==NULL){
        return NO_INICIALIZADO;
    }
    if (estaVacia(lista)){
        return insertarInicio(lista, item);
    }
    else {
        return insertar(lista,lista->tam, item);
    }

};

//Eliminar en la lista
int removerInicio(ListaEnc lista, Dato* item){

    if(lista==NULL){
        return NO_INICIALIZADO;
    }

    if ( estaVacia(lista)){

        return NO_INICIALIZADO;
    }

    No aux = lista->inicio;

    ///if <---------------
    //parematro pase por referencia
    *item =  aux->item;

    free(aux);
    aux = NULL;


    lista->tam--;

    return TRUE;

};

int remover(ListaEnc lista, int pos, Dato* item){

   if (lista==NULL){
    return NO_INICIALIZADO;
   }

   if (pos==0){
    removerInicio(lista, item);
   }
   else {

    No aux= lista->inicio;
    No antAux=NULL;
    for (int i=0; i<pos; i++){
        antAux= aux;
        aux=aux->prox;
    }
    antAux->prox= aux->prox;
    *item= aux->item;
    free(aux);

   }
    lista->tam--;
    return TRUE;
};
int removerFinal(ListaEnc lista, Dato* item){
     remover(lista, lista->tam-1, item);
     return TRUE;
};



int estaVacia(ListaEnc lista){

    if(lista==NULL){
        return NO_INICIALIZADO;
    }

    if (lista->inicio == NULL){

        return TRUE;
    }

    return FALSE;
};

int ordenarLista(ListaEnc lista){
    if (lista==NULL){
        return NO_INICIALIZADO;
    }
    No ant, post;
    Dato aux;
    ant= lista->inicio;

    while (ant->prox!=NULL){
        post= ant->prox;
            while(post!=NULL){
                if(getID(ant->item) > getID( post->item)){
                aux= ant->item;
                ant->item=post->item;
                post->item=aux;
            }
            post=post->prox;
            }

        ant= ant->prox;
    }
    return TRUE;
}; //ordenar por id

int obtenerElemento(ListaEnc lista, Dato* item, int pos) {


    if (estaVacia(lista)){
        return NO_INICIALIZADO;}

    if (item == NULL){
        return NO_INICIALIZADO;}

    No  aux;
    aux = lista->inicio;

    for(int i = 0; i < pos; i++) {
        aux = aux->prox;
    }


    *item = aux->item;

    return TRUE;
}



int obtenerTamanio(ListaEnc lista, int* tam) {

    if(lista == NULL){
        return NO_INICIALIZADO;
    }
    *tam = lista->tam;


    return TRUE;
}



void imprimir(ListaEnc lista) {


    int cantidad;

    obtenerTamanio(lista, &cantidad);


    printf("[");
    for(int i = 0;i < cantidad; i++) {

        Dato cadaElemento;
        obtenerElemento(lista, &cadaElemento, i);

        mostrarDato(cadaElemento);
    }
    printf("]\n");
}
