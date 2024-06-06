#include <iostream>
using namespace std;

int main(){
    float numeros[5];
    int suma = 0;

    cout<<"Ingrese cinco numeros (con o sin coma): ";
    for(int i = 0; i < 5; i++){
        cin>>numeros[i];
    }

    for(float num : numeros){
        suma += num;
    }

    cout<<"La suma de todos sus numeros es: "<<suma<<endl;
}