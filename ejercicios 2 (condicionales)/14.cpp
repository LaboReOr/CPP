#include <iostream>
using namespace std;

int main(){
    string pal1, pal2;
    cout<<"Ingrese dos palabras"<<endl;
    cin>>pal1;
    cin>>pal2;

    if(pal1 == pal2){
        cout<<"Sus palabras son iguales"<<endl;
    }else{
        cout<<"Sus palabras son distintas"<<endl;
    }
}