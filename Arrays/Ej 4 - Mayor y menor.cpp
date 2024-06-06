#include <iostream>
using namespace std;

int main(){
    int tamanio, mayor, menor;

    cout<<"Ingrese el tamaño de su lista: ";   
    cin>>tamanio;

    int lista[tamanio];
    cout<<"Ingrese los elementos de su lista:"<<endl;
    for(int i = 0; i < tamanio; i++){
        cin>>lista[i];
    }

    mayor = lista[1];
    menor = mayor;
    for(int num : lista){
        if(num < menor){
            menor = num;
        }
        if(num > mayor){
            mayor = num;
        }
    }

    cout<<"El menor elemento de su lista es: "<<menor<<" y el mayor es: "<<mayor<<endl;
}