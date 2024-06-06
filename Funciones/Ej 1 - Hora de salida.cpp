#include <iostream>
#include <math.h>
using namespace std;

int hora_a_minutos(int hora){
    int hora_min = hora*60;
    return hora_min;
}

void tiempo_restante(float hora, float minuto){
    float tiempo_restante = 765 - (hora+minuto);
    
    int hora_restante = floor(tiempo_restante/60);
    int min_restante = ((tiempo_restante/60) - hora_restante)*60;

    cout<<"Faltan "<<hora_restante<<" horas y "<<min_restante<<" minutos"<<endl;
    
}

int main(){
    while(true){
        float hora_actual, minuto_actual;

        cout<<"Inserte hora actual: "<<endl;
        cin>>hora_actual;
        cout<<"Inserte minuto actual: "<<endl;
        cin>>minuto_actual;

        hora_actual = hora_a_minutos(hora_actual);

        if(hora_actual+minuto_actual < 724){
        tiempo_restante(hora_actual, minuto_actual);
        }else{
            cout<<"Ya te fuiste!"<<endl;
        }
    }
}