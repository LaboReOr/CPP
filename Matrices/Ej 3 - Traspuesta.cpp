#include <iostream>
using namespace std;


const int filas = 3;
const int columnas = 3;

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

void invertir_matriz(int matriz1[filas][columnas], int matriz2[filas][columnas]){
    cout<<"Ingrese los valores de su matriz"<<endl;
    for(int i = 0; i < filas; i++){
        for(int ii = 0; ii < columnas; ii++){
            matriz2[ii][i] = matriz1[i][ii];
        }
    }
}

int main(){

    int matriz[filas][columnas];
    int nueva_matriz[filas][columnas];

    rellenar_matriz(matriz);

    invertir_matriz(matriz, nueva_matriz);

    cout<<"Su matriz invertida es: "<<endl;
    imprimir_matriz(nueva_matriz);
}