#include <iostream>
using namespace std;

void suma(int &num){
    num++;
    cout<<"Void "<<num<<endl;
}



int main(){
    int num = 3;
    suma(num);
    cout<<"Main "<<num<<endl;
}