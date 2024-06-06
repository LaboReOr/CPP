#include <iostream>
using namespace std;

int elevar(int b, int e){
    if(e == 0){
        b = 1;
    }else{
        b = b * elevar(b, e-1);
    }

    return b;
}


int main(){
    int base, exponente, resultado;

    cout<<"Ingrese una base y un exponente: ";
    cin>>base;
    cin>>exponente;

    if(exponente < 0){
        cout<<"Exponentes positivos se hacen positivos porque sino violacion de core detectado"<<endl;
        exponente *= -1;
    }

    resultado = elevar(base, exponente);

    cout<<resultado<<endl;
}