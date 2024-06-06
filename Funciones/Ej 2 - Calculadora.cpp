#include <iostream>
using namespace std;


int pedir_operacion(){
    int operacion;
    cout<<"\n     1 - Suma \n     2 - Resta \n     3 - Multiplicacion \n     4 - Division \n     5 - Salir \n"<<endl;
    cout<<"Ingrese operacion: ";
    cin>>operacion;#include <iostream>
#include <math.h>
using namespace std;

    return operacion;
}

void calcular_resultado(float n1, float n2, int op){
    float result;

    switch (op){
        case 1: //----SUMA----
            result = n1+n2;
            break;

        case 2: //----RESTA----
            result = n1-n2;
            break;

        case 3: //----MULT----
            result = n1*n2;
            break;

        case 4: //----DIV----
            result = n1/n2;
            break;

        case 5: //----SALIR----
            cout<<"SALIENDO"<<endl;
            return;
            break;

        default:
            cout<<"OPERACION INVALIDA"<<endl;
            return;
            break;
    }

    cout<<"El resultado es: "<<result<<endl;
}

int main(){
    float num1, num2;
    int op;

    while(op != 5){
        cout<<"Ingrese 2 numeros: "<<endl;
        cin>>num1;
        cin>>num2;

        op = pedir_operacion();

        calcular_resultado(num1, num2, op);
    }
}