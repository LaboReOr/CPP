#include <iostream>
using namespace std;

int main(){
    int n;
    int r;
    int r2 = 0;
    cout<<"Ingresa el numero"<<endl;
    cin>>n;
    if(n>1){
        for(int i = n-1; i>=2; i--){
            r=n%i;
            if(r>0){r2=r2+1;}
        }
        if(r2==n-2){
            cout<<"Numero es primo"<<endl;
        } else {
            cout<<"Numero no es primo"<<endl;
        }
    } else {
        cout<<"Numero no es priASDmo"<<endl;
    }
}