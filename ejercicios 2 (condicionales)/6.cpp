#include <iostream>
using namespace std;

int main(){
    int min, may;
    cout<<"Ingrese numeros";
    cin>>min;
    cin>>may;

    if(may <= min){
        cout<<"TONTO"<<endl;
        return false;
    }

    while(may >= min){
        cout<<may<<endl;
        may--;
    }
}