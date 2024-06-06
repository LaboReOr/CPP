#include <iostream>
using namespace std;

int main(){
    int tamanio, mayor;

    cout<<"Ingrese el tamaño de su lista: ";   
    cin>>tamanio;

    int lista[tamanio];
    cout<<"Ingrese los elementos de su lista:"<<endl;
    for(int i = 0; i < tamanio; i++){
        cin>>lista[i];
    }

    mayor = lista[0];
    for(int num : lista){
        if(num > mayor){
            mayor = num;
        }
    }

    cout<<"El mayor elemento de su lista es: "<<mayor<<endl;
}