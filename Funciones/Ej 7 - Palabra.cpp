#include <iostream>
using namespace std;

void juntar(string &pal, char let){
    pal += let;
}


int main(){
    string pal;
    char let;

    cout<<"Ingrese una palabra y una letra:"<<endl;
    cin>>pal;
    cin>>let;

    juntar(pal, let);

    cout<<pal<<endl;
}