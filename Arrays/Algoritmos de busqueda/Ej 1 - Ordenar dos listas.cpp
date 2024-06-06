#include <iostream>
using namespace std;

void ordenar(int lista[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        for(int ii = 0; ii < tamanio - 1; ii++){
            if(lista[ii] > lista[ii +1]){
                int temp = lista [ii];
                lista[ii] = lista[ii+1];
                lista[ii+1] = temp;
            }
        }
    }
}


int main(){
    int tamanio, tamanio2;

    cout<<"Ingrese el tamaño de su primer lista: ";   
    cin>>tamanio;
    int lista[tamanio];
    
    cout<<"Ingrese el tamaño de su segunda lista: ";   
    cin>>tamanio2;
    int lista2[tamanio2];

    cout<<"Ingrese los elementos de su primer lista:"<<endl;
    for(int i = 0; i < tamanio; i++){
        cin>>lista[i];
    }
    
    cout<<"Ingrese los elementos de su segunda lista:"<<endl;
    for(int i = 0; i < tamanio2; i++){
        cin>>lista2[i];
    }

    int tamanio3 = tamanio + tamanio2;
    int lista3[tamanio3];
    for(int i = 0; i < tamanio; i++){
        lista3[i] = lista[i]; 
    }
    for(int i = 0; i < tamanio2; i++){
        lista3[tamanio + i] = lista2[i];
    }

    
    ordenar(lista3, tamanio3);


    cout<<"Los elementos de sus dos listas mezcladas y ordenadas son:"<<endl;
    for(int i = 0; i < tamanio3; i++){
        cout<<lista3[i]<<endl;
    }
}