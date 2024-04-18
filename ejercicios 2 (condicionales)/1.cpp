#include <iostream>
using namespace std;

int main(){
    int a, b;
    
    cout<<"Ingrese dos numeros: "<<endl;
    cin>>a;
    cin>>b;

    if(a>b){
        cout<<"El numero "<<a<<" es mayor"<<endl;
    }else if(b>a){
        cout<<"El numero "<<b<<" es mayor"<<endl;
    }else{
        cout<<"Los dos numeros son iguales"<<endl;
    }
}