#include <iostream>
using namespace std;

int main(){
    string pal1, pal2;
    cout<<"Ingrese 2 palabras: "<<endl;
    cin>>pal1;
    cin>>pal2;

    if(pal1[size(pal1)-1] == pal2[size(pal2)-1]){
        cout<<"La ultima letra es igual"<<endl;
    }else{
        cout<<"La ultima letra es distinta"<<endl;
    }
}
