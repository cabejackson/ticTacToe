#include <iostream>
using namespace std;

char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char currentPlayer = 'X';
int turnsCounter;


void DrawGameboard(){
    system("clear");
    cout << "Tic Tac Toe v1.0" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void PlayerInput(){
    int input;
    cout << "It's " << currentPlayer << "'s turn. Enter a number from the field:";
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore extra characters in input buffer

    if (input >= 1 && input <= 9){
        if (input == 1){
        if (matrix[0][0] == '1')
            matrix[0][0] = currentPlayer;
        else {
            cout << "Field is already in use. Try again!" << endl;
            PlayerInput();
        }
    }
    else if (input == 2)
        if (matrix[0][1] == '2')
            matrix[0][1] = currentPlayer;
        else {
            cout << "Field is already in use. Try again!" << endl;
            PlayerInput();
        }
    else if (input == 3)
        if (matrix[0][2] == '3')
            matrix[0][2] = currentPlayer;
        else {
            cout << "Field is already in use. Try again!" << endl;
            PlayerInput();
        }
    else if (input == 4)
        if (matrix[1][0] == '4')
            matrix[1][0] = currentPlayer;
        else {
            cout << "Field is already in use. Try again!" << endl;
            PlayerInput();
        }
    else if (input == 5)
        if (matrix[1][1] == '5')
            matrix[1][1] = currentPlayer;
        else {
            cout << "Field is already in use. Try again!" << endl;
            PlayerInput();
        }
    else if (input == 6)
        if (matrix[1][2] == '6')
            matrix[1][2] = currentPlayer;
        else {
            cout << "Field is already in use. Try again!" << endl;
            PlayerInput();
        }
    else if (input == 7)
        if (matrix[2][0] == '7')
            matrix[2][0] = currentPlayer;
        else {
            cout << "Field is already in use. Try again!" << endl;
            PlayerInput();
        }
    else if (input == 8)
        if (matrix[2][1] == '8')
            matrix[2][1] = currentPlayer;
        else {
            cout << "Field is already in use. Try again!" << endl;
            PlayerInput();
        }
    else if (input == 9)
        if (matrix[2][2] == '9')
            matrix[2][2] = currentPlayer;
        else {
            cout << "Field is already in use. Try again!" << endl;
            PlayerInput();
        }
    } else {
        cout << "Invalid input. Try again!" << endl;
        return PlayerInput();
    }
}

void TogglePlayer(){
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

char Win(){

    char winner = 'N'; //why does this need to be set w/ a default value?

    for (int i = 0; i < 3; i++) {
        //check if rows and columns are equal
        if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
            winner = matrix[i][0];
        if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
            winner = matrix[0][i];
    }
        //check diagonals
    if (matrix[0][0] ==  matrix[1][1] && matrix[0][0] == matrix[2][2])
        winner = matrix[0][0];
    if (matrix[2][0] == matrix[1][1] && matrix[2][0] == matrix[0][2])
        winner = matrix[2][0];
    
    return winner;
}

int main() {
    turnsCounter = 0;
    DrawGameboard();
    while(1){
        turnsCounter++;
        PlayerInput();
        DrawGameboard();
        if(Win() == 'X') {
            cout << "Player X wins!!" << endl;
            break;
        } else if(Win() == 'O') {
            cout << "Player O wins!!" << endl;
            break;
        } else if(Win() == '/' && turnsCounter == 9){
            cout << "The game is a draw!" << endl;
            break;
        }
        else
            TogglePlayer();
    }
    return 0;
}