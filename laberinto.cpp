#include <iostream>
#define X 5
using namespace std;

int mapa[X][X] = {  {1, 1, -1, 0, 0},
                    {0, 1, 1, 0, 1},
                    {0, -1, 1, -1, 1},
                    {0, 0, 1, 1, 1},
                    {1, 1, -1, 0, 2}};

int cX = 0, cY = 0;
bool win = false, lose = false, showMap = false;

void printMap(){
    for(int i = 0; i < X*X; i++){
        if(cX == i % X && cY == int(i/X)){
            cout << "X ";
        }
        else if(abs(mapa[int(i/X)][i % X]) == 1){
            cout << "# ";
        }
        else if(mapa[int(i/X)][i % X] == 2){
            cout << "$ ";
        }
        else{
            cout << ". ";
        }

        if(i % X == X - 1){
            cout << '\n';
        }
    }
}

void game(){
    if(mapa[cY][cX] == -1){
        lose = true;
        return;
    }
    else if(mapa[cY][cX] == 2){
        win = true;
        return;
    }
    
    if(showMap) printMap();
    else cout << "Tu posicion actual es " << cX << " " << cY << '\n';
    cout << "Hacia que direccion quieres ir? (1. Norte, 2. Sur, 3. Este, 4. Oeste) ";
    int dir; cin >> dir;
    int tempX = cX, tempY = cY;
    switch(dir){
        case 1:
            tempY--;
            break;
        case 2:
            tempY++;
            break;
        case 3:
            tempX++;
            break;
        case 4:
            tempX--;
            break;
        default:
            system("cls");
            cout << "Esa direccion no existe, intentalo de nuevo.\n";
            game();
    }
    system("cls");
    if(tempX >= X || tempY >= X || tempX < 0 || tempY < 0 || mapa[tempY][tempX] == 0){
        cout << "La puerta hacia esa direccion esta bloqueada. Intentalo de nuevo.\n";
        game();
        return;
    }
    cX = tempX; cY = tempY;
}

int main(){
    win = false; lose = false; showMap = false; cX = 0; cY = 0;
    system("cls");
    cout << "Bienvenido al juego del laberinto. Si decides usar el mapa, se mostrara tu ubicacion actual (X), las habitaciones (#) y la salida ($), de lo contrario se mostraran tus coordenadas en X y Y.\n" <<
    "Cada vez que entres a una habitacion podras moverte al Norte, Sur, Este u Oeste.\n" <<
    "Comenzaras en la esquina superior izquierda, y la salida se encuentra en la esquina inferior derecha.\n" <<
    "Ten cuidado, algunas habitaciones tienen trampa y perderas si entras a ellas. Buena suerte!\n";
    
    cout << "Quieres usar el mapa? (Si, No) ";
    string str; cin >> str;
    if(str == "Si") showMap = true;
    system("cls");

    while(!win && !lose) game();
    if(lose) cout << "La habitacion tiene trampa. Perdiste!\n";
    else cout << "Ganaste!\n";

    cout << "Quieres jugar de nuevo? (Si, No) ";
    cin >> str;
    if(str == "Si"){
        system("cls");
        main();
        return 0;
    }

    return 0;
}