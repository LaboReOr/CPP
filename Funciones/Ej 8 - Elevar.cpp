#include <iostream>
#include <math.h>
using namespace std;

void elevar(int &num1, int num2){
    int temp = num1;
    for(int i = 1; i < num2; i++){
        num1 *= temp; 
    }
}


int main(){
    int num1, num2;
    cout<<"Ingrese 2 numeros: "<<endl;
    cin>>num1;
    cin>>num2;

    elevar(num1, num2);
    cout<<"Num 1 elevado a Num2 es "<<num1<<endl;
}