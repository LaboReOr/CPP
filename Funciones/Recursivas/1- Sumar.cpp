#include <iostream>
using namespace std;

int sumar_a_0(int n){
    if(n > 0){
        n = n + sumar_a_0(n-1);
    }

    return n;
}


int main(){
    int num;

    cout<<"Ingrese un numero: ";
    cin>>num;

    if(num < 0){
        num *= -1;
    }

    num = sumar_a_0(num);

    cout<<"Resultado: "<<num<<endl;
}