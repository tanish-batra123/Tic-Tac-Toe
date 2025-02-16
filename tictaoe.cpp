#include <iostream>
using namespace std;

int currentplayer;
char currentmarker;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void printboard()
{
    cout << "-------------\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placemarker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'x' && board[row][col] != 'o')
    {
        board[row][col] = currentmarker;
        return true;
    }
    return false;
}

int winner()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return currentplayer;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return currentplayer;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return currentplayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return currentplayer;
    }
    return 0;
}

void swapplayerandmarker()
{
    currentmarker = (currentmarker == 'x') ? 'o' : 'x';
    currentplayer = (currentplayer == 1) ? 2 : 1;
}

void startgame()
{
    cout << "Player 1, choose your marker ('x' or 'o'): ";
    char markerp1;
    cin >> markerp1;

    currentplayer = 1;
    currentmarker = markerp1;
    printboard();

    int playerwon = 0;

    for (int i = 0; i < 9; i++)
    {
        cout << "It's your turn, Player " << currentplayer << ". Choose your slot (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "Invalid slot! Please choose a slot between 1 and 9.\n";
            i--;
            continue;
        }

        if (!placemarker(slot))
        {
            cout << "This slot is already occupied! Try again.\n";
            i--;
            continue;
        }

        printboard();
        playerwon = winner();

        if (playerwon == 1)
        {
            cout << "Player 1 wins the game!\n";
            break;
        }
        else if (playerwon == 2)
        {
            cout << "Player 2 wins the game!\n";
            break;
        }

        swapplayerandmarker();
    }

    if (playerwon == 0)
    {
        cout << "It's a tie game!\n";
    }
}

int main()
{
    startgame();
    return 0;
}
