#include <iostream>
using namespace std;

// Tic Tac Toe 
char arr[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int rows, col;
char token = 'X';
bool tie = false;

string n1, n2;

// DISPLAY BOARD
void displayBoard()
{
    cout << "\n";

    cout << "     |     |     \n";
    cout << "  " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << "\n";

    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";

    cout << "  " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << "\n";

    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";

    cout << "  " << arr[2][0] << "  |  " << arr[2][1] << "  |  " << arr[2][2] << "\n";

    cout << "     |     |     \n";
}

// PLAYER INPUT
void playerTurn()
{
    int digit;

    if (token == 'X')
    {
        cout << n1 << " (X) enter a number: ";
        cin >> digit;
    }
    else
    {
        cout << n2 << " (O) enter a number: ";
        cin >> digit;
    }

    // CHECK VALID INPUT
    if (digit < 1 || digit > 9)
    {
        cout << "Invalid input!\n";
        playerTurn();
        return;
    }

    // CONVERT NUMBER TO ROW/COLUMN
    rows = (digit - 1) / 3;
    col = (digit - 1) % 3;

    // CHECK IF ALREADY FILLED
    if (arr[rows][col] != 'X' && arr[rows][col] != 'O')
    {
        arr[rows][col] = token;

        // SWITCH PLAYER
        if (token == 'X')
        {
            token = 'O';
        }
        else
        {
            token = 'X';
        }
    }
    else
    {
        cout << "Box already filled!\n";
        playerTurn();
    }
}

// CHECK WIN OR DRAW
bool checkWin()
{
    // ROWS & COLUMNS
    for (int i = 0; i < 3; i++)
    {
        if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) ||
            (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]))
        {
            return true;
        }
    }

    // DIAGONALS
    if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) ||
        (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]))
    {
        return true;
    }

    // CHECK DRAW
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 'X' && arr[i][j] != 'O')
            {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main()
{
    cout << "Enter name of Player 1: ";
    getline(cin, n1);

    cout << "Enter name of Player 2: ";
    getline(cin, n2);

    cout << "\n" << n1 << " is Player 1 (X)\n";
    cout << n2 << " is Player 2 (O)\n";

    while (!checkWin())
    {
        displayBoard();
        playerTurn();
    }

    displayBoard();

    if (tie == false)
    {
        if (token == 'X')
        {
            cout << n2 << " Wins!\n";
        }
        else
        {
            cout << n1 << " Wins!\n";
        }
    }
    else
    {
        cout << "It's a Draw!\n";
    }

    return 0;
}