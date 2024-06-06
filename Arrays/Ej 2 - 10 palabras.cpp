#include <iostream>
using namespace std;

int main(){
    string palabras[10];

    cout<<"Ingrese 10 palabras: "<<endl;
    for(int i = 0; i < 10; i++){
        cin>>palabras[9 - i];
    }

    cout<<"Sus palabras en orden opuesto son: "<<endl;
    for(string pal : palabras){
        cout<<pal<<endl;
    }
}