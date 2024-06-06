#include <iostream>
using namespace std;

int main(){
    int tamanio, mayor, mayorPos;

    cout<<"Ingrese el tamaño de su lista: ";   
    cin>>tamanio;

    int lista[tamanio];
    int listaOrdenada[tamanio];
    
    cout<<"Ingrese los elementos de su lista:"<<endl;
    for(int i = 0; i < tamanio; i++){
        cin>>lista[i];
    }


    for(int i = 0; i < tamanio; i++){
        mayor = 0;
        for(int ii = 0; ii < tamanio; ii++){
            if(lista[ii] > mayor){
                mayorPos = ii;
                mayor = lista[ii];
            }
        }
        
        lista[mayorPos] =  -2147483646;
        listaOrdenada[i] = mayor;
    }

    cout<<"Su lista ordenada de mayor a menor es:"<<endl;
    for(int num : listaOrdenada){
        cout<<num<<endl;
    }
}
