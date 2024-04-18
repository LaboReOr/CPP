#include <iostream>
using namespace std;

int main(){
    int a;
    cout<<"Ingrese un numero: ";
    cin >> a;

    if(a%2 == 0){
        cout<<"el num es par"<<endl;
    }else{
        cout<<"el num es impar"<<endl;
    }
    cout<<&a<<endl;
}