#include <iostream>
using namespace std;

int main(){
    int numero;
    cout<<"Ingrese un numero: "<<endl;
    cin>>numero;
    if (numero < 0) {
        numero = numero*-1;
    }
    if (numero % 2 == 0){
        cout<<"Numero "<<numero<<" es par"<<endl;
    } else {
        cout<<"Numero "<<numero<<" impar"<<endl;
    }
}
