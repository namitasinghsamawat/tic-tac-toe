#include <iostream>
using namespace std;
int main()
{
    int arr[3][3] = {{1, 1, 3}, {4, 5, 6},{7,8,9}};

    string n1, n2;
    cout << "enter the name of the 1st player:\n";
    getline(cin, n1);
    cout << "enter the name of the 2st player:\n";
    getline(cin, n2);

    cout << n1 << "is player 1 he/she plays first\n";
    cout << n2 << "is player 2 he/she plays second\n";

    // structure of the game.
    cout << "    |    |    \n";
    cout<<" "<<arr[0][0]<<"  |  "<<arr[0][1]<<" | "<<arr[0][2]<<"  \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout<<" "<<arr[1][0]<<"  |  "<<arr[1][1]<<" | "<<arr[1][2]<<"  \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout<<" "<<arr[2][0]<<"  |  "<<arr[2][1]<<" | "<<arr[2][2]<<"  \n";
    cout << "    |    |    \n";
}