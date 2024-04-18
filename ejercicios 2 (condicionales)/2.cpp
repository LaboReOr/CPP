#include <iostream>
using namespace std;

int main(){
    float n1, n2, r1, r2, r3, r4;
    cout<<"Ingresa dos numeros: "<<endl;
    cin>>n1;
    cin>>n2;

    r1 = n1*n2;
    r2 = n1+n2;
    r3 = n1-n2;
    if (n1 != 0 && n2 != 0)
    {
        r4 = n1/n2;
    }else{
        cout<<"Error division"<<endl;
    }

    cout<<"Respuestas:"<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<endl;
}