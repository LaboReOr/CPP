#include <iostream>
using namespace std;


int main(){
    int filas, columnas;;

    cout<<"Ingrese las filas y columnas de su matriz"<<endl;
    cin>>filas;
    cin>>columnas;

    int matriz[filas][columnas];
    int matriz_traspuesta[filas][columnas];
    
    cout<<"Ingrese los elementos de su matriz"<<endl;
    for(int i = 0; i < filas; i++){
        for(int ii = 0; ii < columnas; ii++){
            cin>>matriz[i][ii];
        }
    }


    cout<<"Ingrese los valores de su matriz"<<endl;
    for(int i = 0; i < filas; i++){
        for(int ii = 0; ii < columnas; ii++){
            matriz_traspuesta[ii][i] = matriz[i][ii];
        }
    }

    bool iguales = true;
    if(filas == columnas){
        cout<<"SI tiene la misma cantidad de filas que de columnas; ";

        for(int i = 0; i < filas; i++){
            for(int ii = 0; ii < columnas; ii++){
                if(matriz[i][ii] != matriz_traspuesta[i][ii]){
                    iguales = false;
                }
            }
        }
    }else{
        cout<<"NO tiene la misma cantidad de filas que de columnas; ";
        iguales = false;
    }

    if(iguales){
        cout<<"La matriz y su traspuesta SI son iguales."<<endl;
    }else{
        cout<<"La matriz y su traspuesta NO son iguales."<<endl;
    }
}