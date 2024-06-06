#include <iostream>
using namespace std;


const int filas = 2;
const int columnas = 2;

void rellenar_matriz(int matriz[filas][columnas]){
    cout<<"Ingrese los valores de su matriz"<<endl;
    for(int i = 0; i < filas; i++){
        for(int ii = 0; ii < columnas; ii++){
            cin>>matriz[i][ii];
        }
    }
}

void imprimir_matriz(int matriz[filas][columnas]){
    for(int i = 0; i < filas; i++){
        for(int ii = 0; ii < columnas; ii++){
            cout<<matriz[i][ii];
        }
        cout<<endl;
    }
}

void copiar_matriz(int matriz1[filas][columnas], int matriz2[filas][columnas]){
    cout<<"Ingrese los valores de su matriz"<<endl;
    for(int i = 0; i < filas; i++){
        for(int ii = 0; ii < columnas; ii++){
            matriz2[i][ii] = matriz1[i][ii];
        }
    }
}


int main(){
    int matriz[filas][columnas];
    int nueva_matriz[filas][columnas];

    rellenar_matriz(matriz);

    copiar_matriz(matriz, nueva_matriz);

    cout<<"La copia de su matriz es: "<<endl;
    imprimir_matriz(nueva_matriz);
}