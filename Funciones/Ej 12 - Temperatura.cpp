#include <iostream>
using namespace std;


float a_farenheit(float celsius){
    float farenheit = (celsius * 9/5)+32;

    return farenheit;
}

int main(){
    float celsius, farenheit;

    cout<<"Ingrese temperatura en celsius "<<endl;
    cin>>celsius;

    farenheit = a_farenheit(celsius);

    cout<<"Su temperatura en farenheit es: "<<farenheit<<endl;
}