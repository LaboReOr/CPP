#include <iostream>
using namespace std;



int main(){
    int numero;

    cout<<"Escriba su numero decimal: ",
    cin>>numero;

    int temp = numero;
    int longitud = 0;
    bool div = true;

    while(div){
        longitud += 1;
        temp = temp/2;
        if(temp<1){
            div = false;
        }
    }

    int binario[longitud];
    for(int i = 0; i < longitud; i++){
        binario[i] = numero%2;
        numero /= 2;

    }

    cout<<"Su numero en binario es: "<<endl;
    for(int i = longitud-1; i > 0; i--){
        cout<<binario[i];
    }
    cout<<endl;
}