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


// Terminal 
struct termios original_termios;
void setup_terminal(){
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

// Mas espaciado
void clear(){
    for(int i = 0; i < 100; i++){
        cout<<" "<<endl;
    }
}

// Numero random
int numRandom(int min, int max) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(min, max);
    int numero_aleatorio = dis(gen);
    return numero_aleatorio;
}


// Colores
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


/*------------------------------------SLOTS------------------------------------*/



void draw_strawberry(int line){
    switch(line){
        case 1:
            cout<<"        ⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⢀⠀ ⠀         ";
            break;
        case 2:
            cout<<"        ⠀⠀⠀⠀⠀⠀⣏⠓⠒⠤⣰⠋⠹⡄⠀⣠⠞⣿⠀⠀          ";
            break;
        case 3:
            cout<<"        ⠀⠀⠀⢀⠄⠂⠙⢦⡀⠐⠨⣆⠁⣷⣮⠖⠋⠉⠁⠀          ";
            break;
        case 4:
            cout<<"        ⠀⠀⡰⠁⠀⠮⠇⠀⣩⠶⠒⠾⣿⡯⡋⠩⡓⢦⣀⡀          ";
            break;
        case 5:
            cout<<"        ⠀⡰⢰⡹⠀⠀⠲⣾⣁⣀⣤⠞⢧⡈⢊⢲⠶⠶⠛⠁          ";
            break;
        case 6:
            cout<<"        ⢀⠃⠀⠀⠀⣌⡅⠀⢀⡀⠀⠀⣈⠻⠦⣤⣿⡀⠀⠀          ";
            break;
        case 7:                  
            cout<<"        ⠸⣎⠇⠀⠀⡠⡄⠀⠷⠎⠀⠐⡶⠁⠀⠀⣟⡇⠀         ⠀ ";
            break;
        case 8:
            cout<<"        ⡇⠀⡠⣄⠀⠷⠃⠀⠀⡤⠄⠀⠀⣔⡰⠀⢩⠇⠀         ⠀ ";
            break;
        case 9:
            cout<<"        ⡇⠀⠻⠋⠀⢀⠤⠀⠈⠛⠁⠀⢀⠉⠁⣠⠏⠀⠀          ⠀";
            break;
        case 10:
            cout<<"        ⣷⢰⢢⠀⠀⠘⠚⠀⢰⣂⠆⠰⢥⡡⠞⠁⠀⠀⠀          ⠀";
            break;
        case 11:
            cout<<"        ⠸⣎⠋⢠⢢⠀⢠⢀⠀⠀⣠⠴⠋⠀⠀⠀⠀⠀          ⠀⠀";
            break;
        case 12:
            cout<<"        ⠀⠘⠷⣬⣅⣀⣬⡷⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀          ⠀⠀";
            break;
        case 13:
            cout<<"⠀        ⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀         ⠀ ⠀⠀";
            break;
        case 14:
            cout<<"                                      ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}

void draw_cherry(int line){
    switch(line){
        case 1:
            cout<<"                        ████          ";      
            break;
        case 2:
            cout<<"                    ████████          ";
            break;
        case 3:
            cout<<"                  ██    ██            ";
            break;
        case 4:
            cout<<"                ██      ██            ";
            break;
        case 5:
            cout<<"              ██        ██            ";
            break;
        case 6:
            cout<<"          ██████        ██            ";
            break;
        case 7:
            cout<<"        ██▓▓▓▓▓▓██      ██            ";
            break;
        case 8:
            cout<<"      ██▓▓  ▓▓▓▓▓▓██  ██████          ";
            break;
        case 9:
            cout<<"      ██▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓██        ";
            break;
        case 10:
            cout<<"      ██▓▓▓▓▓▓▓▓▓▓██▓▓  ▓▓▓▓▓▓██      ";
            break;
        case 11:
            cout<<"        ██▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓██      ";
            break;
        case 12:
            cout<<"          ██████  ██▓▓▓▓▓▓▓▓▓▓██      ";
            break;
        case 13:
            cout<<"                    ██▓▓▓▓▓▓██        ";
            break;
        case 14:
            cout<<"                      ██████          ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}


void draw_grapes(int line){
    switch(line){
        case 1:
            cout<<"      ⢀⣀⣠⣤⣄⣀⡀     ⢠⡄                  ";
            break;
        case 2:
            cout<<"      ⠈⠙⢛⣿⣿⣿⣿⣷⣄   ⢸⡇                  ";
            break;
        case 3:
            cout<<"    ⠠⠤⣶⠿⠿⠟⠛⣻⣿⡿⠛⣷⡀⣾⠇⣀⣤⣤⣤⣄⡀             ";
            break;
        case 4:
            cout<<"           ⣰⠿⠏   ⠸⣷⣿⡾⠋⠁ ⠹⣿⣿⣷⣄.        ";
            break;
        case 5:
            cout<<"             ⣤⣤⣄ ⢿⠟       ⣿⡟⢿⡍⠃       ";
            break;
        case 6:
            cout<<"         ⣴⣿⡇⠸⠿⣿⣿⠇⣠⣤⣤⡄   ⠛⠁⠈⠃          ";

            break;
        case 7:
            cout<<"        ⠻⠿⠁⣠⣤⣄⠁ ⠛⠛⠿⡟⢀⣀⡀               ";
            break;
        case 8:
            cout<<"      ⢀⣤⣤⡄⢸⣿⣿⣿⠆⢰⣿⣷⣆ ⣾⣿⣷               ";
            break;
        case 9:
            cout<<"      ⢺⡿⠋⣁⣀⠙⠛⠋ ⢿⣿⣿⠟  ⠻⠿⠋              ";
            break;
        case 10:
            cout<<"         ⢼⣿⣿⣿ ⣿⣷⣤⡉⢡⣴⣿⣶                ";
            break;
        case 11:
            cout<<"         ⠈⠛⠛⠋ ⠿⠿⠛⢀⣦⣈⡉                 ";
            break;
        case 12:
            cout<<"         ⢺⣿ ⣿⣷⣶⡖ ⠻⢿⠿⠃                 ";
            break;
        case 13:
            cout<<"          ⠉⠂⠈⠙⠋⣀⠘⢶⣤⠄                  ";
            break;
        case 14:
            cout<<"            ⢸⣿⣿⣿⠇⠈⠁                   ";
            break;
        case 15:
            cout<<"             ⠉⠉⠁                      ";
            break;
    }
}

void draw_diamond(int line){
    switch(line){
        case 1:
            cout<<"     .:::::--.-===+=====:.    ...     ";
            break;
        case 2:
            cout<<"   .::::--===. :=++===:  :.  .::::.   ";
            break;
        case 3:
            cout<<" .::::-======-   :+=-   .::. :::::::. ";
            break;
        case 4:
            cout<<"::::::...:---------.   .---------:::::";
            break;
        case 5:
            cout<<" .::::.    :::-====    -========-:::. ";
            break;
        case 6:
            cout<<"   .::::   .:::====   .=======-:::.   ";
            break;
        case 7:
            cout<<"     .:::.  .::-===   -======-::.     ";
            break;
        case 8:
            cout<<"       .::.  .::===  .=====-::.       ";
            break;
        case 9:
            cout<<"         .::  .:-==  -====-:.         ";
            break;
        case 10:
            cout<<"           .:. .:==  ====::           ";
            break;
        case 11:
            cout<<"             .: .-= :==-:             ";
            break;
        case 12:
            cout<<"               ..:= ==:.              ";  
            break;
        case 13:
            cout<<"                ..-:-.                ";
            break;
        case 14:
            cout<<"                  ..                  ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}

void draw_seven(int line){
    switch(line){
        case 1:
            cout<<"        ++++++++++++++    +++++       ";
            break;

        case 2:
            cout<<"        +++++++++++++++++++++++       ";
            break;
        case 3:
            cout<<"        +++++++++++++++++++++         ";
            break;
        case 4:
            cout<<"        ++++++++++++++++++++          ";
            break;
        case 5:
            cout<<"        +++++       +++++++           ";
            break;
        case 6:
            cout<<"        ++++      +++++++++           ";
            break;
        case 7:
            cout<<"                ++++++++++            ";
            break;
        case 8:
            cout<<"              ++++++++++++            ";
            break;
        case 9:
            cout<<"             ++++++++++++             ";
            break;
        case 10:
            cout<<"            ++++++++++++              ";
            break;
        case 11:
            cout<<"            ++++++++++++              ";
            break;
        case 12:
            cout<<"            +++++++++++++             ";
            break;
        case 13:
            cout<<"            +++++++++++++             ";
            break;
        case 14:
            cout<<"                                      ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}

void draw_empty(int line){
    switch(line){
        case 1:
            cout<<"                                      ";
            break;

        case 2:
            cout<<"                                      ";
            break;
        case 3:
            cout<<"                                      ";
            break;
        case 4:
            cout<<"                                      ";
            break;
        case 5:
            cout<<"                                      ";
            break;
        case 6:
            cout<<"                                      ";
            break;
        case 7:
            cout<<"                                      ";
            break;
        case 8:
            cout<<"                                      ";
            break;
        case 9:
            cout<<"                                      ";
            break;
        case 10:
            cout<<"                                      ";
            break;
        case 11:
            cout<<"                                      ";
            break;
        case 12:
            cout<<"                                      ";
            break;
        case 13:
            cout<<"                                      ";
            break;
        case 14:
            cout<<"                                      ";
            break;
        case 15:
            cout<<"                                      ";
            break;
    }
}



void draw_machine_top(){
    cout<<R"(
                                       ________________________________________
                                       |                                      |
---------------------------------------|             SLOT MACHINE             |--------------------------------------|
|                                      |______________________________________|                                      |
|____________________________________________________________________________________________________________________|
|                                      |                                      |                                      |
)";
}

void draw_machine_bottom(string prize){
    cout<<R"(|                                      |                                      |                                      |
|______________________________________|______________________________________|______________________________________|
|                                              ________________________                                              |
|                                              |                      |                                              |
)";
cout<<"|                                              |        "<<prize<<"        |                                              |"<<endl;
cout<<"|                                              |______________________|                                              |"<<endl;
cout<<"|____________________________________________________________________________________________________________________|"<<endl;
}


void draw_fruit_line(int num, int line){
    switch(num){
        case 1:
            draw_strawberry(line);
            break;
        case 2:
            draw_grapes(line);
            break;
        case 3:
            draw_cherry(line);
            break;
        case 4:
            draw_diamond(line);
            break;
        case 5:
            draw_seven(line);
            break;
        case 6:
            draw_empty(line);
    }
}
    

void draw_fruits(int num1, int num2, int num3){
    for(int i = 1; i <= 15; i++){
            cout<<"|";
            draw_fruit_line(num1, i);
            cout<<"|";
            draw_fruit_line(num2, i);
            cout<<"|";
            draw_fruit_line(num3, i);
            cout<<"|";
            cout<<endl;
        }
}


int recompensa_de(int fruit){
    int prize;

    switch(fruit){
        case 1:
            prize = 10;
            break;

        case 2:
            prize = 100;
            break;
        case 3:
            prize = 1000;
            break;
        case 4:
            prize = 10000;
            break;
        case 5:
            prize = 100000;
            break;
    }

    return prize;
}


void slot_game(int &coins){
    clear();
    
    draw_machine_top();
    draw_fruits(5, 5, 5);
    draw_machine_bottom("999999");
    
    bool slot = true;
    while(slot){

        cout<<"Ingrese E para iniciar. O toca la K para salir. El juego cuesta 25 monedas. Tienes "<<coins<<" monedas."<<endl;
        if(coins < 25){
            cout<<"Saldo insuficiente."<<endl;
            return;
        }

        char input;
        while(true){
            if(read(STDIN_FILENO, &input, 1) > 0){
                if(input == 'k'){
                    return;
                }else if(input == 'e'){
                    break;
                }
            }
        }
        
        coins -= 25;
        
        
        draw_machine_top();
    
        int fruit1 = numRandom(1, 5);
        int fruit2 = numRandom(1, 5);
        int fruit3 = numRandom(1, 5);
        float fruit1d = 0;
        float fruit1i = 10;
        float fruit2d = 0;
        float fruit2i = 10;
        float fruit3d = 0;
        float fruit3i = 10;

        int time = 50; // 25 - 75
        for(int i = 0; i < time + 160; i++){ // 50 - 70

            clear();
            cout<<"Tenes: "<<coins<<" monedas"<<endl;
            draw_machine_top();

            if(i < (time + fruit1d)){
                if(fruit1 < 5){
                    fruit1++;
                }else{
                    fruit1 = 1;
                }
            }else{
                fruit1d += fruit1i;
                fruit1i = (fruit1i/1.1);
            }
            
            if(i < time + 30 + fruit2d){
                if(fruit2 < 5){
                    fruit2++;
                }else{
                    fruit2 = 1;
                }
           }else{
                fruit2d += fruit2i;
                fruit2i = (fruit2i/1.1);
            }

           if(i < time + 60 + fruit3d){
                if(fruit3 < 5){
                    fruit3++;
                }else{
                    fruit3 = 1;
                }
           }else{
                fruit3d += fruit3i;
                fruit3i = (fruit3i/1.1);
            }

            draw_fruits(fruit1, fruit2, fruit3);

            draw_machine_bottom("000000");

            usleep(50000);
        }

        if(fruit1 == fruit2 && fruit1 == fruit3){
            int prize = recompensa_de(fruit1);
            coins += prize;
            string prize_s = to_string(prize);

            while(prize_s.size() < 6){
                prize_s = "0" + prize_s;
            }

            for(int i = 0; i < 25; i++){
                clear();

                draw_machine_top();
                draw_fruits(fruit1, fruit2, fruit3);
                draw_machine_bottom(prize_s);

                usleep(100000);
                clear();

                draw_machine_top();
                draw_fruits(6, 6, 6);
                draw_machine_bottom(prize_s);

                usleep(100000);
            }
        }
    }
}

int main(){
    int monedas = 1000;
    slot_game(monedas);
}