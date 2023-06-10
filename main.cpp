#include <iostream>
using namespace std;

char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player = 'X';
//draws the gameboard
void Draw(){
    cout << "Tic Tac Toe v1.0" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//takes in user input
void Input(){
    int a;
    cout << "Enter a number from the field:";
    cin >> a;

    if (a == 1)
        matrix[0][0] = player;
    else if (a == 2)
        matrix[0][1] = player;
    else if (a == 3)
        matrix[0][2] = player;
    else if (a == 4)
        matrix[1][0] = player;
    else if (a == 5)
        matrix[1][1] = player;
    else if (a == 6)
        matrix[1][2] = player;
    else if (a == 7)
        matrix[2][0] = player;
    else if (a == 8)
        matrix[2][1] = player;
    else if (a == 9)
        matrix[2][2] = player;
}

void TogglePlayer(){
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

int main() {
    Draw();
    while(1){
        Input();
        Draw();
        TogglePlayer();
    }
    return 0;
}