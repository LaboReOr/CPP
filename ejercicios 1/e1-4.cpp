#include <iostream>
using namespace std;

int main(){
    int anio_nac, anio_act;

    cout<<"Ingrese año de nacimiento: "<<endl;
    cin>>anio_nac;
    cout<<"Ingrese año actual: "<<endl;
    cin>>anio_act;

    int edad = anio_act - anio_nac;
    cout<<"edad: ";
    cout<<edad<<endl;
}