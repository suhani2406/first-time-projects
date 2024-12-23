#include <iostream>
#include <string>
using namespace std;

// Global variables for simplicity
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
string n1, n2;

// Function to display the board
void displayBoard() {
    cout << "   |   |   " << endl;
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " " << endl;
    cout << "   |   |   " << endl;
}

// Function to get player names
void functionOne() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);
    cout << n1 << " is Player 1 (X) and will play first." << endl;
    cout << n2 << " is Player 2 (O) and will play second." << endl;
}

// Function to take a player's move
void functionTwo() {
    int digit;
    if (token == 'x') {
        cout << n1 << ", please enter your move (1-9): ";
    } else {
        cout << n2 << ", please enter your move (1-9): ";
    }
    cin >> digit;

    switch (digit) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid input! Please enter a number between 1 and 9." << endl;
            return;
    }

    if (space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    } else {
        cout << "The cell is already occupied! Try again." << endl;
    }
}

// Main function
int main() {
    functionOne();
    int turns = 0;

    while (true) {
        displayBoard();
        functionTwo();
        turns++;

        // Check for a winner or a tie
        if ((space[0][0] == space[0][1] && space[0][1] == space[0][2]) ||
            (space[1][0] == space[1][1] && space[1][1] == space[1][2]) ||
            (space[2][0] == space[2][1] && space[2][1] == space[2][2]) ||
            (space[0][0] == space[1][0] && space[1][0] == space[2][0]) ||
            (space[0][1] == space[1][1] && space[1][1] == space[2][1]) ||
            (space[0][2] == space[1][2] && space[1][2] == space[2][2]) ||
            (space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
            (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
            displayBoard();
            cout << ((token == '0') ? n1 : n2) << " wins!" << endl;
            break;
        }

        if (turns == 9) {
            displayBoard();
            cout << "It's a tie!" << endl;
            break;
        }
    }
    return 0;
}
