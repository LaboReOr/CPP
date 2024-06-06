#include <iostream>
using namespace std;


void invertir(string &palabra){
    string nueva_palabra;

    for(int i = palabra.size(); i >= 0; i--){
        nueva_palabra += palabra[i];
    }

    palabra = nueva_palabra;
}

int main(){
    string palabra;

    cout<<"Ingrese una palabra "<<endl;
    cin>>palabra;

    invertir(palabra);

    cout<<"Su palabra invertida es "<<palabra<<endl;
}