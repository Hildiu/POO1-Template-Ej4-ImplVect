#include "TVector.h"

int main()
{
    //vector sin inicializar
    TVector<float> vector1;

    //vector inicializado con tamaño 10 y elementos inicializados con 1
    TVector<float>  vector2(5, 1.0);

    //vector inicializado a partir de otro vector
    TVector<float>  vector3(vector2);//[1.0,1.0,1.0,1.0,1.0]

    //reemplazar el valor de un elemento
    vector3.setElemento(20.0, 0);//[20.0,1.0,1.0,1.0,1.0]
    //insertar elemento en una posicion especifica
    vector3.insertar(25.0, 4);//[20.0,1.0,1.0,1.0,25.0,1.0]
    //agregar elemento al final del vector
    vector3.agregar(10.0);//[20.0,1.0,1.0,1.0,25.0,1.0,10.0]

    //obtener el tamaño actual del vector
    entero n = vector3.getTamanio();//n = 7
    for(int i=0; i<n; i++)
        cout<<vector3.getElemento(i)<<endl;

    return 0;
}

