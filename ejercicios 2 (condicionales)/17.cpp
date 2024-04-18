#include <iostream>
using namespace std;

int main(){
    string pal1, pal2;

    cout<<"Ingrese dos palabras: "<<endl;
    cin>>pal1;
    cin>>pal2;
    int size1 = size(pal1);
    int size2 = size(pal2);

    bool inword = false;
    int i = 0;
    while(i < size2){
        int letters = 0;
        int x = 0;
        while(x < size1){
            if(pal2[i+x] == pal1[x]){
                letters++;
            }else{
                x = size1;
            }
            x++;
        }
        
        
        if(letters == size1){
            inword = true;
            i = size2;
        }
        i++;
    }

    if(inword){
        cout<<pal1<<" esta en "<<pal2<<endl;
    }else{
        cout<<pal1<<" NO esta en "<<pal2<<endl;
    }
}