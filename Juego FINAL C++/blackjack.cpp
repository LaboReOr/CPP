#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <ctime>
#include <random>

#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define GRAY    "\033[90m"      /* Gray */


/////////////////////////////////////////////////////////////////////////////////


// Espaciado
void clean() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

int numRandom(int min, int max) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(min, max);
    int numero_aleatorio = dis(gen);
    return numero_aleatorio;
}

//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK
//BLACKJACK


// Barajas
const char baraja[4][13] ={
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}, // Trebor    Negro
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}, // Pica      Negro
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}, // Corazon   Rojo
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}  // Rombo     Rojo
};

bool barajaUsada[4][13] ={
    {false, false, false, false, false, false, false, false, false, false, false, false, false}, // Trebor    Negro
    {false, false, false, false, false, false, false, false, false, false, false, false, false}, // Pica      Negro
    {false, false, false, false, false, false, false, false, false, false, false, false, false}, // Corazon   Rojo
    {false, false, false, false, false, false, false, false, false, false, false, false, false}  // Rombo     Rojo
};

void ascii(string palabra){
    if (palabra == "blackjack") {
        cout << endl;
        cout << BLUE << R"(
    ██████  ██       █████   ██████ ██   ██      ██  █████   ██████ ██   ██ 
    ██   ██ ██      ██   ██ ██      ██  ██       ██ ██   ██ ██      ██  ██  
    ██████  ██      ███████ ██      █████        ██ ███████ ██      █████   
    ██   ██ ██      ██   ██ ██      ██  ██  ██   ██ ██   ██ ██      ██  ██  
    ██████  ███████ ██   ██  ██████ ██   ██  █████  ██   ██  ██████ ██   ██ 
                                                                            )" << endl;
    } else if (palabra == "ganaste") {
        cout << endl;
        cout << GREEN << "   ____    _    _   _    _    ____ _____ _____ " << endl;
        cout << GREEN << "  / ___|  / \\  | \\ | |  / \\  / ___|_   _| ____|" << endl;
        cout << GREEN << " | |  _  / _ \\ |  \\| | / _ \\ \\___ \\ | | |  _|  " << endl;
        cout << GREEN << " | |_| |/ ___ \\| |\\  |/ ___ \\ ___) || | | |___ " << endl;
        cout << GREEN << "  \\____/_/   \\_\\_| \\_/_/   \\_\\____/ |_| |_____|" << endl;
    } else if (palabra == "perdiste") {
        cout << endl;
        cout << RED << "  ____  _____ ____  ____ ___ ____ _____ _____ " << endl;
        cout << RED << " |  _ \\| ____|  _ \\|  _ \\_ _/ ___|_   _| ____|" << endl;
        cout << RED << " | |_) |  _| | |_) | | | | |\\___ \\ | | |  _|  " << endl;
        cout << RED << " |  __/| |___|  _ <| |_| | | ___) || | | |___ " << endl;
        cout << RED << " |_|   |_____|_| \\_\\____/___|____/ |_| |_____|" << endl;
    } else if (palabra == "empate") {
        cout << endl;
        cout << YELLOW << "  _____ __  __ ____   _  _____ _____ " << endl;
        cout << YELLOW << " | ____|  \\/  |  _ \\ / \\|_   _| ____|" << endl;
        cout << YELLOW << " |  _| | |\\/| | |_) / _ \\ | | |  _|  " << endl;
        cout << YELLOW << " | |___| |  | |  __/ ___ \\| | | |___ " << endl;
        cout << YELLOW << " |_____|_|  |_|_| /_/   \\_\\_| |_____|" << endl;     
    }
}


// Cartas random
string repartirCarta(){
    int cartita, palo;
    cartita = numRandom(0, 12);
    palo = numRandom(0, 3);

    barajaUsada[palo][cartita] = true;

    string palito;
    if(palo == 0){
        palito = "♣";
    } else if(palo == 1){
        palito = "♠";
    } else if(palo == 2){
        palito = "❤";
    } else if(palo == 3){
        palito = "◆";
    }
    return palito + baraja[palo][cartita];
}

void imprimir_cartas(vector<string> mano){
    string palos[4] = {"♣", "♠", "❤", "◆"};

    for(int ii = 0; ii < 5; ii++){
        for(int i = 0; i < mano.size(); i++){

            // Colores
            int palo = 0;
            int cualPalo;
            for(int ii = 0; ii < 4; ii++){
                for(int iii = 0; iii < 3; iii++){
                    if(mano[i][iii] == palos[ii][iii]) {
                        palo++;
                    }
                }
                if(palo == 3){
                    cualPalo = ii;
                    break;
                } else {
                    palo = 0;
                }
            }
            switch (cualPalo){
            case 0:
            case 1:
                // Imprimir
                switch (ii){
                case 0:
                    cout << RESET << ".----. " << RESET;
                    break;
                case 1:
                    cout << RESET << "|    | " << RESET;
                    break;
                case 2:
                    if(mano[i][3] == '0'){
                        cout << RESET << "| "<< mano[i][0] << mano[i][1] << mano[i][2] <<"10| " << RESET;
                    } else {
                        cout << RESET << "| "<< mano[i] <<" | " << RESET;
                    }
                    break;
                case 3:
                    cout << RESET << "|    | " << RESET;
                    break;
                case 4:
                    cout << RESET << "'----' " << RESET;
                    break;
                default:
                    break;
                }
                break;

            case 2:
            case 3:
                // Imprimir
                switch (ii){
                case 0:
                    cout << RED << ".----. " << RESET;
                    break;
                case 1:
                    cout << RED << "|    | " << RESET;
                    break;
                case 2:
                    if(mano[i][3] == '0'){
                        cout << RED << "| "<< mano[i][0] << mano[i][1] << mano[i][2] <<"10| " << RESET;
                    } else {
                        cout << RED << "| "<< mano[i] <<" | " << RESET;
                    }
                    break;
                case 3:
                    cout << RED << "|    | " << RESET;
                    break;
                case 4:
                    cout << RED << "'----' " << RESET;
                    break;
                default:
                    break;
                }
                break;
            }

        }
        cout<<endl;
    }
}

// Devuelve el valor de la carta ingresada
int valorCarta(string carta){
    int valor;
    switch (carta[3])
    {
    case '2':
        valor = 2;
        break;
    case '3':
        valor = 3;
        break;
    case '4':
        valor = 4;
        break;
    case '5':
        valor = 5;
        break;
    case '6':
        valor = 6;
        break;
    case '7':
        valor = 7;
        break;
    case '8':
        valor = 8;
        break;
    case '9':
        valor = 9;
        break;
    case '0':
    case 'J':
    case 'Q':
    case 'K':
        valor = 10;
        break;
    default:
        valor = 0;
        break;
    }
    return valor;
}

// Cuenta el valor de la mano
int contarCartas(vector<string> mano){
    int valor = 0;
    for(string carta:mano){
        valor += valorCarta(carta);
    }
    for(string carta:mano){
        if(carta[3] == 'A'){
            if(valor <= 10){
                valor += 11;
            } else {
                valor += 1;
            }
        }
    }
    return valor;
}

// Imprime las manos del blackjack
void imprimirMenuBlackJack(vector<string> manoCasa, vector<string> manoJugador){
    clean();
    ascii("blackjack");

    cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
    imprimir_cartas(manoCasa);
    cout << endl;

    cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
    imprimir_cartas(manoJugador);
    cout << endl;

    cout << GREEN << "(P) PEDIR " << RED << "(Q) QUEDARSE " << YELLOW << "(D) DOBLAR" << RESET << endl;
    cout << "--> ";
}

void dealer(vector<string> manoCasa, vector<string> manoJugador, int &resultado, int &apuesta, int &coin, bool &bucleMano){
    if(contarCartas(manoCasa) >= 17){
        imprimirMenuBlackJack(manoCasa, manoJugador);
        usleep(2000000);
    }

    if(contarCartas(manoJugador) > 21){
        imprimirMenuBlackJack(manoCasa, manoJugador);
        resultado = 2;
        bucleMano = false;
        usleep(2000000);

    } else {

        usleep(2000000);
        while (contarCartas(manoCasa) < 17){
            manoCasa.push_back(repartirCarta());
            imprimirMenuBlackJack(manoCasa, manoJugador);
            usleep(2000000);
        }

        usleep(1000000);
        if(contarCartas(manoCasa) > 21){
            resultado = 1;
            coin += apuesta*2;
            bucleMano = false;
        } else if(contarCartas(manoJugador) > 21){
            resultado = 2;
            bucleMano = false;
        } else {
            if(contarCartas(manoCasa) > contarCartas(manoJugador)){
                resultado = 2;
                bucleMano = false;
            } else if (contarCartas(manoCasa) == contarCartas(manoJugador)) {
                resultado = 3;
                coin += apuesta;
                bucleMano = false;
            } else {
                resultado = 1;
                coin += apuesta*2;
                bucleMano = false;
            }
        }

    }

    
}

// Rondas o manos del black jack
void rondas(int &coin){

    int apuesta = 0;

    vector<string> manoJugador;
    vector<string> manoCasa;

    // Apuestas
    while (true){
        clean();
        cout << BLUE << "Valor a apostar --> " << RESET;
        cin >> apuesta;
        if (apuesta > coin){
            cout << RED << "FONDOS INSUFICIENTES!" << RESET << endl;
            usleep(3000000);
        } else if(apuesta > 0) {
            coin -= apuesta;
            break;
        } else {
            cout << RED << "INGRESE UN NUMERO VALIDO!" << RESET << endl;
            usleep(3000000);
        }
    }
    clean();

    // Animacion inicio
    manoCasa.push_back(repartirCarta());
    ascii("blackjack");
    cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
    imprimir_cartas(manoCasa);
    usleep(600000);
    clean();
    manoCasa.push_back(repartirCarta());
    ascii("blackjack");
    cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
    imprimir_cartas(manoCasa);
    usleep(600000);
    clean();
    manoJugador.push_back(repartirCarta());
    ascii("blackjack");
    cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
    imprimir_cartas(manoCasa);
    cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
    imprimir_cartas(manoJugador);
    usleep(600000);
    clean();
    manoJugador.push_back(repartirCarta());
    ascii("blackjack");
    cout << BLUE << "CASA" << "(" << contarCartas(manoCasa) << ")" << RESET << endl;
    imprimir_cartas(manoCasa);
    cout << BLUE << "YO" << "(" << contarCartas(manoJugador) << ")" << RESET << endl;
    imprimir_cartas(manoJugador);
    usleep(600000);
    clean();

    // Un bucle
    char opcion;
    int resultado = 0;
    bool bucleMano = true;

    if(contarCartas(manoCasa) == 21){
        if(contarCartas(manoJugador) == 21){
            bucleMano = false;
            resultado = 3;
            imprimirMenuBlackJack(manoCasa, manoJugador);
            usleep(1300000);
        } else {
            bucleMano = false;
            resultado = 1;
            imprimirMenuBlackJack(manoCasa, manoJugador);
            usleep(1300000);
        }
    }

    if(contarCartas(manoJugador) == 21){
        bucleMano = false;
        resultado = 1;
        imprimirMenuBlackJack(manoCasa, manoJugador);
        usleep(1300000);
    }

    // Partidas
    while (bucleMano){
        imprimirMenuBlackJack(manoCasa, manoJugador);
        cin >> opcion;

        switch (opcion)
        {
        case 'p':
        case 'P':
            manoJugador.push_back(repartirCarta());
            if(contarCartas(manoJugador) > 21){
                imprimirMenuBlackJack(manoCasa, manoJugador);

                bucleMano = false;
                resultado = 2;
                usleep(1300000);
            }
            break;

        case 'q':
        case 'Q':
            dealer(manoCasa, manoJugador, resultado, apuesta, coin, bucleMano);
            break;

        case 'd':
        case 'D':
            clean();
            manoJugador.push_back(repartirCarta());
            dealer(manoCasa, manoJugador, resultado, apuesta, coin, bucleMano);
            break;

        default:
            break;
        }
    }


    // RESULTADO
    if(resultado == 1){
        ascii("ganaste");
        cout << GREEN << "GANASTE --> $" << apuesta*2 << endl;
        usleep(2500000);
    } else if (resultado == 2) {
        ascii("perdiste");
        usleep(2500000);
    } else if (resultado == 3) {
        ascii("empate");
        cout << GRAY << "TE DEVOLVIERON --> $" << apuesta << endl;
        usleep(2500000);
    } else {
        clean();
        int asd;
        cout << "ERROR INESPERADO!" << endl;
        cin >> asd;
    }


}

// El juego
void juegoBlackJack(int &coin){
    // Juego
    int respuesta;
    int bucle = true;
    while (bucle){
        clean();
        ascii("blackjack");
        cout << R"(
          .-------------------------------------------------------.
          |                                                       |
          |         OPCIONES - TOCAR UN NUM Y LUEGO ENTER.        |
          |                                                       |
          |                      1 - Jugar                        |
          |                      2 - Salir                        |
          |                                                       |)" << endl;
        cout << "          |                     saldo: "<< coin <<"                       |" << endl;
        cout << "          '-------------------------------------------------------'" << endl;
        cout << "--> ";
        cin >> respuesta;
        if(respuesta == 1){
            rondas(coin);
        } else if (respuesta == 2) {
            bucle = false;
        } else {
            cout << RED << "Elija una de las siguientes opciones!" << RESET << endl;
            usleep(2000000);
        }

    }

}


int main(){
    int monedas  = 1000;
    juegoBlackJack(monedas);
}