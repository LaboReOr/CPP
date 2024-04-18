#include <iostream>
using namespace std;

int main(){
    string pal, newpal;
    cout<<"Ingrese su palabra:"<<endl;
    cin>>pal;

    int indice = size(pal);
    while(indice != 0){
        newpal = newpal + pal[indice-1];
        indice--;
    }
    
    
    if(pal == newpal){
        cout<<"Su palabra se lee igual al reves."<<endl;
    }else{
        cout<<"Su palabra NO se lee igual al reves."<<endl;
    }
}