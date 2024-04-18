#include <iostream>
using namespace std;

int main(){
    int n, r;

    cout<<"Ingrese libros a llevarse: "<<endl;
    cin>>n;

    if(n<0){
        n = n*-1;
    }

    if(n>5){
        r = n*250;
    }else{
        r = n*300;
    }
    
    cout<<"Precio final: "<<r<<endl;
}
