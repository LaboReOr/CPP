#include <iostream>
using namespace std;

int main(){
    int a = 7;
    int * adir = &a; //"&" Referencia la direccion de la variable a su derecha

    cout<<&a<<endl;
    cout<<adir<<endl;
    cout<<a<<endl;
    cout<<*adir<<endl;
    cout<<&*adir<<endl;
    cout<<*adir<<endl;
}