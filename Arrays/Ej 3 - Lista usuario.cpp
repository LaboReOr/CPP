#include <iostream>
using namespace std;

int main(){
    int numero;
    int tamanio;

    cout<<"Ingrese un numero entero, y un tamaño de lista: "<<endl;
    cin>>numero;
    cin>>tamanio;

    int lista[tamanio];
    cout<<"Ingrese los elementos de su lista: "<<endl;
    for(int i = 0; i < tamanio; i++){
        cin>>lista[i];
    }

    bool inList = false;
    for(int num : lista){
        if(num == numero){
            inList = true;
        }
    }

    if(inList == true){
        cout<<"El numero se encuentra en la lista."<<endl;
    }else{
        cout<<"El numero no se encuentra en la lista.";
    }
}