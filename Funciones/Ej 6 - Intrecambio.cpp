#include <iostream>
using namespace std;


void intercambio(int &num1, int&num2){
    int temp = num1;
    
    num1 = num2;
    num2 = temp;
}


int main(){
    int num1, num2;
    cout<<"Ingrese dos numeros: "<<endl;
    cin>>num1;
    cin>>num2;

    cout<<"Pre intercambio: "<<num1<<" "<< num2<<endl;
    intercambio(num1, num2);
    cout<<"Post intercambio: "<<num1<<" "<< num2<<endl;

}