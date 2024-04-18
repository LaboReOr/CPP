#include <iostream>
using namespace std;


int main(){
    char letra;
    int letraAscii;

    cout<<"Ingrese letra: "<<endl;
    cin>>letra;

    letraAscii = letra;
    if(letraAscii<=122 && letraAscii>=97){
        cout<<"Letra minuscula"<<endl;
    } else {
        cout<<"Letra mayuscula"<<endl;
    }
}