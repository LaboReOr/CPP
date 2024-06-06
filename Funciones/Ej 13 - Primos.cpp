#include <iostream>
using namespace std;


bool primo (int numero){
    for(int i = 2; i < numero; i++){
        cout<<numero%i<<endl;
        if(numero % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int numero;

    cout<<"Ingrese un numero: "<<endl;
    cin>>numero;

    if(primo(numero)){
        cout<<"El numero es primo"<<endl;
    }else{
        cout<<"El numero no es primo"<<endl;
    }
}