#include <iostream>
using namespace std;

int main(){
    int h, m;

    cout<<"Ingresar cantida de hombres: ";
    cin>>h;
    cout<<"Ingresar cantida de mujeres: ";
    cin>>m;

    int suma = h + m;
    int rh = (h*100)/suma;
    int rm = (m*100)/suma;
    
    cout<<"% Hombres: " << rh<<endl;
    cout<<"% Mujeres: " << rm<<endl;
}