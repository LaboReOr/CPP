#include <iostream>
using namespace std;


int main(){
    int filas, columnas;;

    cout<<"Ingrese las filas y columnas de su matriz"<<endl;
    cin>>filas;
    cin>>columnas;

    int matriz[filas][columnas];
    
    cout<<"Ingrese los elementos de su matriz"<<endl;
    for(int i = 0; i < filas; i++){
        for(int ii = 0; ii < columnas; ii++){
            cin>>matriz[i][ii];
        }
    }

    cout<<"Su matriz resultante es: "<<endl;
    for(int i = 0; i < filas; i++){
        for(int ii = 0; ii < columnas; ii++){
            cout<<matriz[i][ii];
        }
        cout<<endl;
    }

}