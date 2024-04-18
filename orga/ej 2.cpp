#include <iostream>
using namespace std;


void josefinofinofinoli(){
    int val = 0;
    int * aptr = &val; 
    *aptr += 10;
    cout<<"El valor de la variable es: "<< *aptr << endl;

}

int main(){
   josefinofinofinoli();
}