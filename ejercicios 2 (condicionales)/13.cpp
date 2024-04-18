#include <iostream>
using namespace std;

int main(){
    string pal, newpal;
    cout<<"Ingrese su palabra:"<<endl;
    cin>>pal;
    
    cout<<size(pal)<<endl;
    int index = 0;
    while(index < size(pal)+1){
        newpal = newpal + pal[size(pal)-index];
        index++;
    }
    cout<<"Su palabra dada vuelta: "<<newpal<<endl;
}