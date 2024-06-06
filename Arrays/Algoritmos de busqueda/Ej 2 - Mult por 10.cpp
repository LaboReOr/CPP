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
    int lista[5], lista10[5];

    cout<<"Ingrese 5 elementos de su lista: "<<endl;
    for(int i = 0; i < 5; i++){
        cin>>lista[i];
    }
    
    for(int i = 0; i < 5; i++){
        lista10[i] = lista[i] * 10;
    }

    ordenar[lista10, 5];


    cout<<"Los elementos de su lista * 10 y ordenada son:"<<endl;
    for(int num : lista10){
        cout<<num<<endl;
    }
}