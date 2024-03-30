#include<iostream>
#include <iostream>
#include <string>
#include <windows.h>
#include<direct.h>
#include<iomanip>
#include"Sudoko.h"
using namespace std;
Sudoko s;
int getLevel();
void Interface();
void printWord()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14); // Set text color to yellow (14)

        cout << "        $$$$$$\\                  $$\\           $$\\                       $$$$$$$\\                                $$\\           \n";
        cout << "       $$  __$$\\                 $$ |           $$ |                      $$  __$$\\                               $$ |          \n";
        cout << "       $$ /  \\___|$$\\   $$\\  $$$$$$$ | $$$$$$\\  $$ |  $$\\ $$\\   $$\\       $$ |  $$ |$$\\   $$\\ $$$$$$$$\\ $$$$$$$$\\ $$ | $$$$$$$\\  \n";
        cout << "       \\$$$$$$\\  $$ |  $$ |$$  __$$ |$$  __$$\\ $$ | $$  |$$ |  $$ |      $$$$$$$  |$$ |  $$ |\\____$$  |\\____$$  |$$ |$$  __$$\\ \n";
        cout << "       \\____$$\\ $$ |  $$ |$$ /  $$ |$$ /  $$ |$$$$$$  / $$ |  $$ |      $$  ____/ $$ |  $$ |  $$$$ _/   $$$$ _/ $$ |$$$$$$$$ |\n";
        cout << "       $$\\   $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$  _$$<  $$ |  $$ |      $$ |      $$ |  $$ | $$  _/    $$  _/   $$ |$$   ____|\n";
        cout << "        \\$$$$$$  |\\$$$$$$  |\\$$$$$$$ |\\$$$$$$  |$$ | \\$$\\ \\$$$$$$  |      $$ |      \\$$$$$$  |$$$$$$$$\\ $$$$$$$$\\ $$ |\\$$$$$$$\\ \n";
        cout << "        \\______/  \\______/  \\_______| \\______/ \\__|  \\__| \\______/       \\__|       \\______/ \\________|\\________|\\__| \\_______|\n";
        cout << "                                                                                                                         \n";
        cout << "                                                                                                                         \n";
        cout << "                                                                                                                         \n";

  
    SetConsoleTextAttribute(hConsole, 7); // Reset text color to default (7)

}
void loading(int n)
{
    for (int i = 0; i <= n; i++)
    {
        printWord();

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << setw(65) << "PLEASE WAIT FEW SECOND ";
        for (int j = 0; j < i; j++)
        {
            cout << ".";
        }
        cout << endl;
        Sleep(100); // delay for 100 milliseconds
        system("cls"); // clear the console
    }
}
int main()
{
    loading(20);
Interface();


}
int getLevel()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14); // Set text color to yellow (14)
    int level;
    cout << "\n\n\n\n\n\n";
    cout << "           (1)EASY 4X4\n\n           (2)MEDIUM 6X6\n\n           (3)HARD 9X9\n\n\n";
    cout << "Choose Level:";cin >> level;
    switch (level)
    {
    case 1:
        s.setArray(4);
        break;
    case 2:
        s.setArray(6);
        break;
    case 3:
        s.setArray(9);
        break;
    default:
        cout << "Invalid Option\n";
        break;
    }
    if (level > 3 || level < 1)
        level = 0;
    SetConsoleTextAttribute(hConsole, 7); // Set text color to yellow (14)

    return level;
}
void Interface()
{
    Sleep(100);
    system("cls");
    while (true) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hConsole, 12); // Set text color to yellow (14)

        cout << " __      __       .__                                  __             _________         .___      __             _________      .__                     \n";
        cout << "/  \\    /  \\ ____ |  |   ____  ____   _____   ____   _/  |_  ____    /   _____/__ __  __| _/____ |  | ____ __   /   _____/ ____ |  |___  __ ___________ \n";
        cout << "\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\  \\   __\\/  _ \\   \\_____  \\|  |  \\/ __ |/  _ \\|  |/ /  |  \\  \\_____  \\ /  _ \\|  |\\  \\/ // __ \\_  __ \\\n";
        cout << " \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/   |  | (  <_> )  /        \\  |  / /_/ (  <_> )    <|  |  /  /        (  <_> )  |_>  <\\  ___/|  | \\/\n";
        cout << "  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >  |__|  \\____/  /_______  /____/\\____ |\\____/|__|_ \\____/  /_______  /\\____/|   __/ \\___  >__|   \n";
        cout << "       \\/       \\/          \\/            \\/     \\/                         \\/           \\/           \\/               \\/         \\/|__|        \\/       \n";

        SetConsoleTextAttribute(hConsole, 10); // Set text color to yellow (14)
        cout << "\n\n\n\n\n\n\n\n\n";
       // cout << "               Welcome to Sudoku Solver!\n\n";
        cout << "                 1. PLAY SUDOKU PUZZLE\n";
        cout << "                 2. SOLVE SUDOKU PUZZLE \n";
        cout << "                 3. EXITE THE GAME\n";
        SetConsoleTextAttribute(hConsole, 7); // Set text color to yellow (14)

        cout << "                  CHOOSE AN OPTION:";

        int option;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            system("cls");

            int level = getLevel();
            if (level)
            {
                s.userSolvePuzzle();
            }
            else return;

        }
        break;
        case 2:
        {
            system("cls");

            int level = getLevel();
            if (level)
            {
                s.userProvidedPuzzle();
                cout << "Provided Sudoku Puzzle Solver:\n";
                if (s.solveSudoku() == true)
                {
                    s.printGrid();
                }
                else
                {
                    cout << "No number leads to a valid solution\n";
                }
                system("pause");
                system("cls");
            }

        }
        break;
        case 3:
            cout << "THANKS FOR PLAYING THE GAME\n";
            Sleep(100);
            return;
        default:
            cout << "Invalid Option\n";
        }
    }
}






