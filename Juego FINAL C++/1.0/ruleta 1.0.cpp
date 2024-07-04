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


struct termios original_termios;

void setup_terminal() {
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &original_termios);
    new_termios = original_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

void restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
}

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



//
//
//
//  _  _________   __  ____  ____  _____ ____ ____  
// | |/ / ____\ \ / / |  _ \|  _ \| ____/ ___/ ___| 
// | ' /|  _|  \ V /  | |_) | |_) |  _| \___ \___ \ 
// | . \| |___  | |   |  __/|  _ <| |___ ___) |__) |
// |_|\_\_____| |_|   |_|   |_| \_\_____|____/____/ 
//
//
//
//
                                                


enum Key {
    UP_ARROW = 0,
    DOWN_ARROW,
    RIGHT_ARROW,
    LEFT_ARROW,
    OTHER_KEY
};

char keyPress(){
    char c;
    while (true) {
        cin.get(c);
        if (c == 27) {
            char arrow1, arrow2;
            cin.get(arrow1);
            cin.get(arrow2);
            if (arrow1 == '[') {
                switch (arrow2) {
                    case 'A':
                        return UP_ARROW;
                    case 'B':
                        return DOWN_ARROW;
                    case 'C':
                        return RIGHT_ARROW;
                    case 'D':
                        return LEFT_ARROW;
                }
            }
        } else {
            return c;
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////    ____ ___  ____ ___ ____  ___     //////////////////////////
//////////////////////////   / ___/ _ \|  _ \_ _/ ___|/ _ \    //////////////////////////
//////////////////////////  | |  | | | | | | | | |  _| | | |   //////////////////////////
//////////////////////////  | |__| |_| | |_| | | |_| | |_| |   //////////////////////////
//////////////////////////   \____\___/|____/___\____|\___/    //////////////////////////
//////////////////////////                                     //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


void animacion(const string &text) {
    for (char caracter : text) {
        cout << caracter;
        usleep(5000);
    }
    usleep(10000);
}


void ruletaAscii(int espaciado){              
    string texto = "";  
    for(int i = 0; i < espaciado; i++){
        texto+=" ";
    }
    cout << texto << "    ____  __  ____    _______________ " << endl;
    cout << texto << "   / __ \\/ / / / /   / ____/_  __/   |" << endl;
    cout << texto << "  / /_/ / / / / /   / __/   / / / /| |" << endl;
    cout << texto << " / _, _/ /_/ / /___/ /___  / / / ___ |" << endl;
    cout << texto << "/_/ |_|\\____/_____/_____/ /_/ /_/  |_|" << endl;
}


//
//
//
//  __     _______ ____       _    ____  _   _ _____ ____ _____  _    ____  
//  \ \   / / ____|  _ \     / \  |  _ \| | | | ____/ ___|_   _|/ \  / ___| 
//   \ \ / /|  _| | |_) |   / _ \ | |_) | | | |  _| \___ \ | | / _ \ \___ \ 
//    \ V / | |___|  _ <   / ___ \|  __/| |_| | |___ ___) || |/ ___ \ ___) |
//     \_/  |_____|_| \_\ /_/   \_\_|    \___/|_____|____/ |_/_/   \_\____/                                                                                                 
//
//
//
//

void apuestasVer(int apuestas[], int valores){
    // Imprimir las apuestas realizadas
    ruletaAscii(44);
    cout << endl << "Apuestas: " << endl;
    string opciones[14] = {
        "Par",
        "Impar",
        "Rojo",
        "Negro",
        "1 a 18",
        "19 a 36",
        "1ra Docena",
        "2nda Docena",
        "3era Docena",
        "1 Linea",
        "2 Linea",
        "3 Linea",
        "Multiples numeros",
        "Numero unico"
    };

    cout << endl;
    for (int i = 0; i < 14; i++) {
        if (apuestas[i] > 0) {
            cout << opciones[i] << ": " << apuestas[i] << " monedas" << endl;
        }
    }
    cout << "----------------------" << endl;
    cout << endl;
}

//
//
//
//   _____  _    ____  _     _____ ____   ___  
//  |_   _|/ \  | __ )| |   | ____|  _ \ / _ \ 
//    | | / _ \ |  _ \| |   |  _| | |_) | | | |
//    | |/ ___ \| |_) | |___| |___|  _ <| |_| |
//    |_/_/   \_\____/|_____|_____|_| \_\\___/                             
//
//
//
//

void tablero(int opciones){
    switch (opciones) {
        case 0:
            cout << " _________________________________________________________________________" << endl;
            break;
        case 1:
            cout << " |    |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 2:
            cout << " |    | " << RED << "3" << RESET << " | 6 | " << RED << "9" << RESET << " | " << RED << "12" << RESET << " | 15 | " << RED << "18" << RESET << " | " << RED << "21" << RESET << " | 24 | " << RED << "27" << RESET << " | " << RED << "30" << RESET << " | 33 | " << RED << "36" << RESET << " | 3 LINEA |" << endl;
            break;
        case 3:
            cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 4:
            cout << "|     |---+---+---+----+----+----+----+----+----+----+----+----+---------+" << endl;
            break;
        case 5:
            cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 6:
            cout << "|  " << GREEN << "0" << RESET << "  | 2 | " << RED << "5" << RESET << " | 8 | 11 | " << RED << "14" << RESET << " | 17 | 20 | " << RED << "23" << RESET << " | 26 | 29 | " << RED << "32" << RESET << " | 35 | 2 LINEA |" << endl;
            break;
        case 7:
            cout << "|     |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 8:
            cout << "|     |---+---+---+----+----+----+----+----+----+----+----+----+---------+" << endl;
            break;
        case 9:
            cout << " |    |   |   |   |    |    |    |    |    |    |    |    |    |         |" << endl;
            break;
        case 10:
            cout << " |    | " << RED << "1" << RESET << " | 4 | " << RED << "7" << RESET << " | 10 | 13 | " << RED << "16" << RESET << " | " << RED << "19" << RESET << " | 22 | " << RED << "25" << RESET << " | 28 | 31 | " << RED << "34" << RESET << " | 1 LINEA |" << endl;
            break;
        case 11:
            cout << " |____|___|___|___|____|____|____|____|____|____|____|____|____|_________|" << endl;
            break;
        case 12:
            cout << "      |                |                   |                   |" << endl;
            break;
        case 13:
            cout << "      |   1ra Docena   |    2nda Docena    |    3era Docena    |" << endl;
            break;
        case 14:
            cout << "      |                |                   |                   |" << endl;
            break;
        case 15:
            cout << "      +----------------+-------------------+-------------------+" << endl;
            break;
        case 16:
            cout << "      |       |        |         |         |         |         |" << endl;
            break;
        case 17:
            cout << "      |1 a 18 |  Par   |  Rojo   |  Negro  |  Impar  | 19 a 36 |" << endl;
            break;
        case 18:
            cout << "      |       |        |         |         |         |         |" << endl;
            break;
        case 19:
            cout << "      +-------+--------+---------+---------+---------+---------+" << endl;
            break;
        default:
            break;
    }
}



//
//
//
//   ____  _   _ _     _____ _____  _    
//  |  _ \| | | | |   | ____|_   _|/ \   
//  | |_) | | | | |   |  _|   | | / _ \  
//  |  _ <| |_| | |___| |___  | |/ ___ \ 
//  |_| \_\\___/|_____|_____| |_/_/   \_\                              
//
//
//
//

void imprimirRuleta(int i, int ii, int iii, int colorI, int colorII, int colorIII){
    string textI = "";
    string textII = "";
    string textIII = "";
    if(i < 10){
        textI+=" ";
    }
    if(ii < 10){
        textII+=" ";
    }
    if(iii < 10){
        textIII+=" ";
    }
    ruletaAscii(0); 
    cout << "             ____________" << endl;
    cout << "        ____|            |____" << endl;
    cout << "       |    |            |    |" << endl;
    // si es rojo true, si es negro false
    if(colorI == true){
        cout << "       | " << RED << i << textI << RESET ;
    } else {
        cout << "       | " << RESET << i << textI;
    }
    if(colorII == true){
        cout << " |     " << RED << ii << textII << RESET;
    } else {
        cout << " |     " << ii << textII << RESET;
    }
    if(colorIII == true){
        cout << "     | " << RED << iii << textIII << RESET << " |"<< endl;
    } else {
        cout << "     | " << iii << textIII << RESET << " |" << endl;
    }
    
    
    cout << "       |____|            |____|" << endl;
    cout << "            |____________|" << endl;
    cout << endl;
    cout << endl;
}

int girarRuleta() {

    int num = numRandom(74, 148);

    int i = -1;
    int ii = 0;
    int iii = 1;
    int contador = 0;
    bool colorI;
    bool colorII;
    bool colorIII;
    while (num > 0) {
        int rojitos[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
        int negritos[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
        colorI = false;
        colorII = false;
        colorIII = false;
        clean();
        num--;
        i++;
        ii++;
        iii++;
        contador++;
        for(int value:rojitos){
            if(i == value){
                colorI = true;
            }
            if(ii == value){
                colorII = true;
            }
            if(iii == value){
                colorIII = true;
            }
        }
        // Imprimir ruleta
        if (ii == 36) {
            i = 35;
            ii = 36;
            iii = 0;
        } else if (ii == 37){
            i = 36;
            ii = 0;
            iii = 1;
        } else if (ii == 1){
            i = 0;
            ii = 1;
            iii = 2;
        }

        // Verifica que numero se imprime, si es de un o dos digitos
        if (i < 10) {
            imprimirRuleta(i, ii, iii, colorI, colorII, colorIII);
        } else {
            imprimirRuleta(i, ii, iii, colorI, colorII, colorIII);
        }

        // Darle efecto a la ruleta que se va reelentizando
        if (num > 150) {
            usleep(30000);
        } else if (num > 70) {
            usleep(70000);
        } else if (num > 30) {
            usleep(100000);
        } else if (num > 15) {
            usleep(200000);
        } else if (num > 10) {
            usleep(250000);
        } else if (num > 4) {
            usleep(500000);
        } else if (num > 2) {
            usleep(600000);
        } else if (num > 1) {
            usleep(700000);
        }
        // int dormir = map(contador, 0, num, 0, 400000);
        // usleep(dormir);
    }
    clean();
    // ruletaAscii(16);
    // for(int rI = 0; rI < 20; rI++){
    //     tablero(rI);
    // }
    if (i < 10) {
        imprimirRuleta(i, ii, iii, colorI, colorII, colorIII);
    } else {
        imprimirRuleta(i, ii, iii, colorI, colorII, colorIII);
    }
    return ii;
}

//
//
//
//   __  __ _____ _   _ _   _ 
//  |  \/  | ____| \ | | | | |
//  | |\/| |  _| |  \| | | | |
//  | |  | | |___| |\  | |_| |
//  |_|  |_|_____|_| \_|\___/ 
//
//
//
//

void menu(int op) {
    // Menu de apuestas
    cout << "OPCIONES (W,S(up down) y E(intro)): ------------------------------------------------------------------------------------------" << endl;
    string opciones[17] = {
        "(x2) Par                                         ",
        "(x2) Impar                                       ",
        "(x2) Rojo                                        ",
        "(x2) Negro                                       ",
        "(x2) 1 a 18                                      ",
        "(x2) 19 a 36                                     ",
        "(x3) 1ra Docena                                  ",
        "(x3) 2nda Docena                                 ",
        "(x3) 3era Docena                                 ",
        "(x3) 1 Linea                                     ",
        "(x3) 2 Linea                                     ",
        "(x3) 3 Linea                                     ",
        "(x6, x9, x18) Multiples numero (A la vez)        ",
        "(x36) Numero unico                               ",
        "GIRAR LA RULETA                                  ",
        "REINICIAR APUESTAS                               ",
        "VOLVER                                           "
    };

    // Marcador de opciones
    for(int i = 0; i < 2; i++) {
        for(int ii = 0; ii < 54; ii++){
            cout << " ";
        }
        tablero(i);
    }
    for (int i = 0; i < 17; i++) {
        if (i == op) {
            cout << RED << " --> " << opciones[i] << RESET;
            tablero(i+2);
        } else {
            cout << "     " << opciones[i];
            tablero(i+2);
        }
    }
    for(int i = 17; i < 18; i++) {
        for(int ii = 0; ii < 54; ii++){
            cout << " ";
        }
        tablero(i+2);
    }
}

//
//
//
//       _ _   _ _____ ____  ___  
//      | | | | | ____/ ___|/ _ \ 
//   _  | | | | |  _|| |  _| | | |
//  | |_| | |_| | |__| |_| | |_| |
//   \___/ \___/|_____\____|\___/ 
//
//
//
//
                             
void juegoRuleta(int &coin) {
    string texto = R"(
                                                ____  __  ____    _______________
                                               / __ \/ / / / /   / ____/_  __/   |
                                              / /_/ / / / / /   / __/   / / / /| |
                                             / _, _/ /_/ / /___/ /___  / / / ___ |
                                            /_/ |_|\____/_____/_____/ /_/ /_/  |_| 
    )";
    animacion(texto);
    cout << endl;
    int monto;
    int numGanador;
    int apuestaIndividualNumero;
    int apuestaMultiplesNumeros[37] = {0}; // Almacena las apuestas a números específicos
    // Vector que almacena apuestas sin modificar
    int apuestas[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // Array que almacena las ganancias ganadoras
    int ganancias[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // Multiplicacion en el caso de que gane
    int multiplicacion[14] = {2,2,2,2,2,2,3,3,3,3,3,3,6,36};
    // Tecla apretada
    int tecla;
    // Opcion a seleccionar
    int op = 0;
    // Tecla sin importancia
    int atecla;
    // Monto a devolver en caso de reiniciar las apuestas
    int montoDevolver = 0;

    bool bucle = true;
    while (bucle) {
        setup_terminal();
        // ruletaVer();
        clean();
        apuestasVer(apuestas, 14);
        cout << "Saldo: " << coin << endl;
        cout << endl;
//         string texto = R"(
//     ____  __  ____    _______________
//    / __ \/ / / / /   / ____/_  __/   |
//   / /_/ / / / / /   / __/   / / / /| |
//  / _, _/ /_/ / /___/ /___  / / / ___ |
// /_/ |_|\____/_____/_____/ /_/ /_/  |_|
//         )";
        menu(op);

        // Si hay alguna tecla presionada, que diga cual es
        tecla = keyPress();
        switch (tecla) {
            case 'w': // Flecha arriba
                op = (op - 1 + 17) % 17; // Evitar valores negativos
                break;
            case 's': // Flecha abajo
                op = (op + 1) % 17;
                break;
            case 'e': // Enter
                if (op == 16) {
                    //
                    //
                    //
                    //   ____    _    _     ___ ____    ____  _____ _           _ _   _ _____ ____  ___  
                    //  / ___|  / \  | |   |_ _|  _ \  |  _ \| ____| |         | | | | | ____/ ___|/ _ \ 
                    //  \___ \ / _ \ | |    | || |_) | | | | |  _| | |      _  | | | | |  _|| |  _| | | |
                    //   ___) / ___ \| |___ | ||  _ <  | |_| | |___| |___  | |_| | |_| | |__| |_| | |_| |
                    //  |____/_/   \_\_____|___|_| \_\ |____/|_____|_____|  \___/ \___/|_____\____|\___/                                                               
                    //
                    //
                    //
                    //
                    bucle = false;
                } else if (op == 15) {
                    //
                    //
                    //
                    //   ____  _____ ___ _   _ ___ ____ ___    _    ____       _    ____  _   _ _____ ____ _____  _    ____  
                    //  |  _ \| ____|_ _| \ | |_ _/ ___|_ _|  / \  |  _ \     / \  |  _ \| | | | ____/ ___|_   _|/ \  / ___| 
                    //  | |_) |  _|  | ||  \| || | |    | |  / _ \ | |_) |   / _ \ | |_) | | | |  _| \___ \ | | / _ \ \___ \ 
                    //  |  _ <| |___ | || |\  || | |___ | | / ___ \|  _ <   / ___ \|  __/| |_| | |___ ___) || |/ ___ \ ___) |
                    //  |_| \_\_____|___|_| \_|___\____|___/_/   \_\_| \_\ /_/   \_\_|    \___/|_____|____/ |_/_/   \_\____/                                                                                                                                                            
                    //
                    //
                    //
                    //
                    for(int i = 0; i < 14; i++){
                        apuestas[i] = 0;
                        ganancias[i] = 0;
                    }
                    for(int i = 0; i < 37; i++){
                        apuestaMultiplesNumeros[i] = 0;
                    }
                    coin += montoDevolver;
                    montoDevolver = 0;
                } else if (op == 14) {
                    //
                    //
                    //
                    //    ____ ___ ____      _    ____    _        _      ____  _   _ _     _____ _____  _    
                    //   / ___|_ _|  _ \    / \  |  _ \  | |      / \    |  _ \| | | | |   | ____|_   _|/ \   
                    //  | |  _ | || |_) |  / _ \ | |_) | | |     / _ \   | |_) | | | | |   |  _|   | | / _ \  
                    //  | |_| || ||  _ <  / ___ \|  _ <  | |___ / ___ \  |  _ <| |_| | |___| |___  | |/ ___ \ 
                    //   \____|___|_| \_\/_/   \_\_| \_\ |_____/_/   \_\ |_| \_\\___/|_____|_____| |_/_/   \_\                                                                                                                                            
                    //
                    //
                    //
                    //
                    montoDevolver = 0;
                    // Girar la ruleta
                    numGanador = girarRuleta();
                    // Plata a ganar
                    cout << "Numero ganador: " << numGanador << endl;
                    int gananciasTotales = 0;

                    int rojitos[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
                    int negritos[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

                    // Evaluar las apuestas
                    for (int i = 0; i < 14; i++) {
                        // Revisar todas las apuestas
                        if (ganancias[i] > 0) {
                            bool gano = false;
                            switch (i) {
                                case 0: // Par
                                    gano = (numGanador % 2 == 0);
                                    break;
                                case 1: // Impar
                                    gano = (numGanador % 2 != 0);
                                    break;
                                case 2: // Rojo
                                    for(int valores:rojitos){
                                        if(numGanador == valores){
                                            gano = (numGanador == valores);
                                            break;
                                        }
                                    }
                                    break;
                                case 3: // Negro
                                    for(int valores:negritos){
                                        if(numGanador == valores){
                                            gano = (numGanador == valores);
                                            break;
                                        }
                                    }
                                    break;
                                case 4: // 1 a 18
                                    gano = (numGanador >= 1 && numGanador <= 18);
                                    break;
                                case 5: // 19 a 36
                                    gano = (numGanador >= 19 && numGanador <= 36);
                                    break;
                                case 6: // 1ra Docena
                                    gano = (numGanador >= 1 && numGanador <= 12);
                                    break;
                                case 7: // 2nda Docena
                                    gano = (numGanador >= 13 && numGanador <= 24);
                                    break;
                                case 8: // 3era Docena
                                    gano = (numGanador >= 25 && numGanador <= 36);
                                    break;
                                case 9: // 1 Linea
                                    gano = (numGanador % 3 == 1);
                                    break;
                                case 10: // 2 Linea
                                    gano = (numGanador % 3 == 2);
                                    break;
                                case 11: // 3 Linea
                                    gano = (numGanador % 3 == 0);
                                    break;
                            }
                            if (gano) {
                                gananciasTotales += ganancias[i];
                            }
                        }
                    }

                    // Revisar apuesta a número único
                    if (apuestaMultiplesNumeros[numGanador] > 0) {
                        gananciasTotales += apuestaMultiplesNumeros[numGanador];
                    }
                    cout << "Saldo anterior: " << coin << endl;
                    coin += gananciasTotales;
                    cout << "Ganancias totales: " << gananciasTotales << endl;
                    cout << "Saldo actualizado: " << coin << endl;
                    cout << "Presiona cualquier tecla para continuar...";
                    tecla = keyPress();

                    for(int i = 0; i < 14; i++){
                        apuestas[i] = 0;
                        ganancias[i] = 0;
                    }
                    for(int i = 0; i < 37; i++){
                        apuestaMultiplesNumeros[i] = 0;
                    }


                } else {
                    //
                    //
                    //
                    //    ____    _    ____   ____    _    ____       _    ____  _   _ _____ ____ _____  _    ____  
                    //   / ___|  / \  |  _ \ / ___|  / \  |  _ \     / \  |  _ \| | | | ____/ ___|_   _|/ \  / ___| 
                    //  | |     / _ \ | |_) | |  _  / _ \ | |_) |   / _ \ | |_) | | | |  _| \___ \ | | / _ \ \___ \ 
                    //  | |___ / ___ \|  _ <| |_| |/ ___ \|  _ <   / ___ \|  __/| |_| | |___ ___) || |/ ___ \ ___) |
                    //   \____/_/   \_\_| \_\\____/_/   \_\_| \_\ /_/   \_\_|    \___/|_____|____/ |_/_/   \_\____/                                                                                                                                                                                                                      
                    //
                    //
                    //
                    //

                    
                    string input;
                    while (true) {
                        cout << "Monto: ";
                        getline(cin, input);

                        istringstream iss(input);
                        if (iss >> monto and monto > 0) {
                            break;
                        } else {
                            cout << "Entrada inválida. Por favor, ingresa solo numeros positivos..." << endl;
                        }
                    }

                    if (monto > coin) {
                        cout << "Fondos insuficientes!" << endl;
                        tecla = keyPress();
                    } else {
                        coin -= monto;
                        // Opción de múltiples números deshabilitada
                        if (op == 12) {
                            cout << "Opcion deshabilitada, presiona cualquier tecla para continuar...";
                            tecla = keyPress();
                        } else if (op == 13) {
                            // Apostar a un número específico
                            cout << "Numero a apostar (0-36): ";
                            bool buu = true;
                            while (buu) {
                                cin >> apuestaIndividualNumero;
                                if (apuestaIndividualNumero <= 36 && apuestaIndividualNumero >= 0) {
                                    buu = false;
                                } else {
                                    cout << "Numero invalido! Escriba otra vez: ";
                                }
                            }
                            apuestaMultiplesNumeros[apuestaIndividualNumero] += monto * 36;
                            montoDevolver += monto;
                        } else {
                            // Otras apuestas
                            ganancias[op] += (monto * multiplicacion[op]);
                            apuestas[op] += monto;
                            montoDevolver += monto;
                        }
                    }
                }
                break;
            default:
                break;
        }

    }
}


int main(){
    int monedas = 1000;
    juegoRuleta(monedas);
}