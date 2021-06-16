#include "TVector.h"

template <typename T>
TVector<T>::TVector()
{
    this->elementos = nullptr;
    this->tamanio = 0;
    this->maximo = 0;
}

template <typename T>
TVector<T>::TVector(entero _tamanio, T _valor)
{
    if(_tamanio > 0) {
        this->tamanio = this->maximo = _tamanio;
        this->elementos = new T[this->maximo];
        for (int i = 0; i < this->tamanio; ++i) {
            this->elementos[i] = _valor;
        }
    }
}

template <typename T>
TVector<T>::TVector(const TVector &otro_vector)
{
    this->tamanio = otro_vector.tamanio;
    this->maximo = this->tamanio;
    this->elementos = new T[this->maximo];
    for (int i = 0; i < this->tamanio; ++i) {
        this->elementos[i] = otro_vector.elementos[i];
    }
}

template <typename T>
TVector<T>::~TVector()
{
    delete[] this->elementos;
};

template <typename T>
void TVector<T>::setElemento(T elemento, entero posicion)
{
    if(posicion >= 0 && posicion <this->tamanio)
        this->elementos[posicion] = elemento;
}

template <typename T>
void TVector<T>::insertar(T elemento, entero posicion)
{
    if(posicion >= 0 && posicion <this->tamanio){
        if(this->tamanio == this->maximo)
            this->redimensionar();
        for (int i = this->tamanio; i > posicion; i--)
            this->elementos[i] = this->elementos[i-1];
        this->elementos[posicion] = elemento;
        this->tamanio++;
    }
}

template <typename T>
void TVector<T>::agregar(T elemento)
{
    if(this->tamanio == this->maximo)
        this->redimensionar();
    this->elementos[this->tamanio++] = elemento;
}

template <typename T>
entero TVector<T>::getTamanio()
{
    return this->tamanio;
}

template <typename T>
T TVector<T>::getElemento(entero posicion)
{
    if(posicion >= 0 && posicion <this->tamanio)
        return this->elementos[posicion];
    else return 0;
}

template <typename T>
void TVector<T>::redimensionar()
{
    this->maximo = this->maximo * 1.25; //crece 25%
    T* newarray = new T[this->maximo];
    for (int i = 0; i <this->tamanio ; ++i)
        newarray[i] = this->elementos[i];
    delete[] this->elementos;
    this->elementos = newarray;
}