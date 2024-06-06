#include <iostream>
using namespace std;


int contar_vocales(string palabra){
    int vocales = 0;
    for(int i = 0; i < palabra.size(); i++){
        if(palabra[i] == 'A' || palabra[i] == 'a' || palabra[i] == 'E' || palabra[i] == 'e' || palabra[i] == 'I' || palabra[i] == 'i' || palabra[i] == 'O' || palabra[i] == 'o' || palabra[i] == 'U' || palabra[i] == 'u'){
            vocales++;
        }
    }

    return vocales;
}


int main(){
    string palabra;
    int vocales;

    cout<<"Ingrese una palabra"<<endl;
    cin>>palabra;

    vocales = contar_vocales(palabra);
    cout<<"La palabra tiene "<<vocales<<" vocales"<<endl;
}