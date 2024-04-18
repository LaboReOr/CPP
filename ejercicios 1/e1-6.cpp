#include <iostream>  //incluir la libreria iostream 
using namespace std;  //usar el 'namespace' de nombre std
    // espacio vacio
int main(){  // loop principal
    int n;      // crea la variable n
     //espacio vacio
    cout<<"Ingrese numero: "<<endl; //imprime las palabras ingrese numero y deja un espacio vacio
    cin>>n;  // toma de la consola un valor  y lo almacena en la variable n
      // espacio vacio
    if(n%2 != 0){  //una comparacion entre el resto de n/2 y 0
        cout<<"El numero es impar"<<endl; 
    }else{
        cout<<"El numero es par"<<endl;
    }
}