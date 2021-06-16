
#ifndef VECTOR_TVECTOR_H
#define VECTOR_TVECTOR_H

#include <iostream>
using namespace std;
typedef int entero;

template <typename T>
class TVector {
private:
    entero tamanio; //--- numero de elementos en el vector
    T* elementos;
    entero maximo; //--- el vector tiene maximo numero de casillas, que no necesariamente estan ocupadas todas
    void redimensionar();
public:
    //constructor vacio
    TVector();
    //constructor inicilizador
    TVector(entero _tamanio, T _valor);
    //constructor copia
    TVector(const TVector &otro_vector);
    //destructor
    virtual ~TVector();
    //reemplazar elemento
    void setElemento(T elemento, entero posicion);
    //insertar elemento
    void insertar(T elemento, entero posicion);
    //agregar elemento
    void agregar(T elemento);
    //getters
    entero getTamanio();
    T getElemento(entero posicion);
};

#include "TVector.cpp"

#endif //VECTOR_TVECTOR_H
