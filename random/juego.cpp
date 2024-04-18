#include <iostream>
#include <termios.h>
#include <unistd.h>
using namespace std;

void createmap();
void map();
void entities(string stri, int i, int line);
void characterMovement();
void roomObjects();
void coins();

string line1[20];
string line2[20];
string line3[20];
string line4[20];
string line5[20];
string line6[20];

int rooms[] = {1, 3, 2, 4};

int gold = 0;
int life = 3;
int posx = 9;
int posy = 3;
int Ox = 18;
int Oy = 5;
int room = 0;

int main(){
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
    createmap();

    cout<<"A = left, D = right, S = down, W = up"<<endl;

    while (true) {
        cout<<"Gold: "<< gold <<" - Life: "<< life<<endl;
        map();
        characterMovement();
        coins();

    }  
}

void createmap(){
    //line 1
    for(int i = 0; i < 20; i++){
        line1[i] = "-";
    }
    
    //line 2
    line2[0]= "|";
    for(int i = 1; i < 19; i++){
        line2[i] = " ";
    }
    line2[19]= "|";

    //line 3
    line3[0]= "|";
    for(int i = 1; i < 19; i++){
        line3[i] = " ";
    }
    line3[19]= "|";

    //line 4
    line4[0]= "|";
    for(int i = 1; i < 19; i++){
        line4[i] = " ";
    }
    line4[19]= "|";

    //line 5
    line5[0]= "|";
    for(int i = 1; i < 19; i++){
        line5[i] = " ";
    }
    line5[19]= "|";

    //line 6
    line6[0]= "|";
    for(int i = 1; i < 19; i++){
        line6[i] = " ";
    }
    line6[19]= "|";
}

void map(){
    //TOP
    for(int i = 0; i < 20; i++){
        if(rooms[room] == 1 && (i == 10 || i == 9)){
            cout<<" ";
        }else{
            cout<<line1[i];
        }
    }
    cout<<""<<endl;

    //line 2
    for(int i = 0; i < 20; i++){
        entities(line2[i], i, 2);
    }
    cout<<""<<endl;

    //line 3
    for(int i = 0; i < 20; i++){
        entities(line3[i], i, 3);
    }
    cout<<""<<endl;

    //line 4
    for(int i = 0; i < 20; i++){
        entities(line4[i], i, 4);
    }
    cout<<""<<endl;

    //line 5
    for(int i = 0; i < 20; i++){
        entities(line5[i], i, 5);
    }
    cout<<""<<endl;

    //line 6
    for(int i = 0; i < 20; i++){
        entities(line6[i], i, 6);
    }
    cout<<""<<endl;

    //BOTTOM
    for(int i = 0; i < 20; i++){
        if(rooms[room] == 2 && (i == 10 || i == 9)){
            cout<<" ";
        }else{
            cout<<line1[i];
        }
    }
    cout<<""<<endl;
}

void entities(string stri, int i, int line){
    if(posx == i && posy == line){
        cout<<"f";
    }else if(Ox == i && Oy == line){
        cout<<"o";
    }else if(i == 0 && line == 4 && rooms[room] == 3){
        cout<<" ";
    }else if(i == 19 && line == 4 && rooms[room] == 4){
        cout<<" ";
    }else{
        cout<<stri;
    }
}

void characterMovement(){
    char input;
    if (read(STDIN_FILENO, &input, 1) > 0) {
            if(input=='a'){
                if(posx>1){
                    posx--;
                }else if(rooms[room] == 3 && posy == 4){
                    room++;
                    roomObjects();
                    posx = 9;
                    posy = 4;
                }
            }else if (input=='d'){
                if(posx <18){
                    posx++;
                }else if(rooms[room] == 4 && posy == 4){
                    room++;
                    roomObjects();
                    posx = 9;
                    posy = 4;
                }
            }else if (input == 's'){
                if(posy < 6){
                    posy++;
                }else if(rooms[room] == 2 && (posx == 9 || posx == 10)){
                    room++;
                    roomObjects();
                    posx = 9;
                    posy = 4;
                }
            }else if (input == 'w'){
                if(posy > 2){
                    posy--;
                }else if(rooms[room] == 1 && (posx == 9 || posx == 10)){
                    room++;
                    roomObjects();
                    posx = 9;
                    posy = 4;
                }
            }else if (input == 'p'){
                exit(1);
            }
            
        }
}

void roomObjects(){
    if(room == 4){
        cout<<"YOU WIN - Score: "<<gold<<endl;
        exit(1);
    }

    switch(room){
        case 0:
        Ox = 18;
        Oy = 5;
        break;

        case 1:
        Ox = 2;
        Oy = 3;
        break;

        case 2:
        Ox = 12;
        Oy = 2;
        break;

        case 3:
        Ox = 18;
        Oy = 2;
        break;
        
        case 4:
        Ox = 15;
        Oy = 3;
        break;
    }
}

void coins(){
    if(Ox == posx && Oy == posy){
        Ox = 999;
        Oy = 999;
        gold++;
    }
}