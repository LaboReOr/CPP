#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Ingrese numero: ";
    cin>>num;

    for(int i = 1; i <= 10; i++){
        int x = num * i;
        cout<<num<<" * "<<i<<" == "<<x<<endl;
    }
}