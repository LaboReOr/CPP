#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Ingrese numero: "<<endl;
    cin>>num;

    if(num > 0 && num < 10){
        if(num != 5){
            cout<<"Su numero esta entre 0 y 10 y NO es 5"<<endl;
        }else{
            cout<<"Su numero es el 5";
        }
    }else{
        cout<<"Su numero NO esta entre 0 y 10";
    }
}