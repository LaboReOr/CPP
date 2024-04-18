#include <iostream>
using namespace std;

int main(){
    string pal;
    int n = 0;
    cout<<"Ingrese su palabra: "<<endl;
    cin>>pal;
    int n1 = size(pal);
    int index = 0;
    while(index < n1){
        if(pal[index] == 'a' || pal[index] == 'e' || pal[index] == 'i' || pal[index] == 'o' || pal[index] == 'u'){
            n++;
        }
        index++;
    }
    cout<<"Su palabra tiene "<<n<<" vocales"<<endl;
}