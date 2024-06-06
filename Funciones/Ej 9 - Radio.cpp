#include <iostream>
#include <math.h>
using namespace std;


float calcular_area(float radio){
    float area = M_PI * pow(radio, 2);
    return area;
}

int main(){
    float radio, area;

    cout<<"Ingrese radio del circulo"<<endl;
    cin>>radio;

    area = calcular_area(radio);
    cout<<"El area del circulo es: "<<area<<endl;
}