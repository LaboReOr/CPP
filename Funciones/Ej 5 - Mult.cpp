#include <iostream>
using namespace std;

void multiplicar(int &num){
    num *= 2;
}


int main(){
    int num;

    cout<<"Ingrese un numero: ";
    cin>>num;

    multiplicar(num);

    cout<<"Su numero por dos es "<<num<<endl;
}