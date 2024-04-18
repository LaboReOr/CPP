#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Ingrese numero: "<<endl;
    cin>>num;

    if(num > 0 && num < 10){
        cout<<"Su numero esta entre 0 y 10"<<endl;
    }else{
        cout<<"Su numero NO esta entre 0 y 10";
    }
}