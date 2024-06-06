#include <iostream>
using namespace std;

int fibonacci(int n, int x1, int x2){

    if(n>0){
    int x = x1;
    x1 = x1 + x2;
    x2 = x;
    x1 = fibonacci(n-1, x1, x2);
    }else{
        return x1 ;
    }

    return x1;
}

int main(){
    int num;

    cout<<"Ingrese un numero: ";
    cin>>num;

    if(num<0){
        num *= -1;
    }

    num = fibonacci(num-2, 1, 0);
    cout<<num<<endl;
}