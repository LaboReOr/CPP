#include <iostream>
using namespace std;

int main(){
    string usu, contra, usuario = "Admin", contraseña = "123";

    cout<<"Ingrese usuario: "<<endl;
    cin>>usu;
    
    cout<<"Ingrese contraseña: "<<endl;
    cin>>contra;

    if(usuario == usu && contraseña == contra){
        cout<<"Inicio de sesion exitoso"<<endl;
    }else{
        cout<<"Usuario o contraseña incorrectos"<<endl;
    }
}