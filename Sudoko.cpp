#include "Sudoko.h"
Sudoko::Sudoko()
{
     N = 0;
     grid = nullptr;
     solvedGrid = nullptr;
}


void Sudoko::setArray(int N)
{
    this->N = N;
    grid = new int*[N];
    for (int i = 0;i < N;i++)
        grid[i] = new int[N];

    solvedGrid = new int* [N];
    for (int i = 0;i < N;i++)
        solvedGrid[i] = new int[N];

    for(int i=0;i<N;i++)
        for (int j = 0;j < N;j++)
        {
            grid[i][j] = 0;
            solvedGrid[i][j] = 0;
        }

}

// Function to check if a number can be placed in a cell
bool Sudoko::isSafe(int row, int col, int num)
{
    // Check if num is not already present in the current row
    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num) return false;
    }
    // Check if num is not already present in the current column
    for (int i = 0; i < N; ++i) {
        if (grid[i][col] == num) return false;
    }
    // Check if num is not already present in the current subgrid
    int startRow = row - row % (N == 9 ? 3 : 2); // Adjust based on the difficulty level
    int startCol = col - col % (N == 4 ? 2 : 3); // Adjust based on the difficulty level
    for (int i = 0; i < (N == 9 ? 3: 2); ++i) { // Adjust based on the difficulty level
        for (int j = 0; j < (N == 4 ? 2 : 3); ++j) { // Adjust based on the difficulty level
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}
// Function to solve Sudoku using backtracking
bool Sudoko::solveSudoku()
{
    int row, col;
    // Find the first empty cell
    bool foundEmpty = false;
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (grid[row][col] == 0) {
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty) break;
    }
    // If no empty cell is found, puzzle is solved
    if (!foundEmpty) return true;
    // Try each number in the current cell
    for (int num = 1; num <= N; ++num) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;
            // Recursively solve the remaining puzzle
            if (solveSudoku()) return true;
            // If no solution found, backtrack
            grid[row][col] = 0;
        }
    }
    // No number leads to a valid solution
    return false;
 }

// Function to print the Sudoku grid
void Sudoko::printGrid() const
{
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < N; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    
}
void Sudoko::printSolvedGrid() const
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j) {
            cout << solvedGrid[i][j] << " ";
        }
        cout << endl;
    }

}
// Function to generate a Sudoku puzzle
void Sudoko::generatePuzzle()
{
    srand(time(0)); // Seed for random number generation
    // Initialize the grid with zeros
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = 0;
        }
    }
    // Fill the diagonal subgrids with random numbers
    for (int i = 0; i < N; i += (N == 9 ? 3 : 2)) {
        for (int j = 0; j < N; j += (N == 4 ? 2 : 3)) {
            int num = (rand() % N) + 1;
            while (!isSafe(i, j, num)) {
                num = (rand() % N) + 1;
            }
            grid[i][j] = num;
        }
    }
    
    // Solve the puzzle to generate a valid solution
    solveSudoku();
    // Copy the solved puzzle to keep the solution
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            solvedGrid[i][j] = grid[i][j];
        }
    }
    // Remove some numbers to create the puzzle
    int numToRemove = 0; // Adjust the number of clues based on difficulty
    if (N == 4) numToRemove = 8;
    else if (N == 6) numToRemove = 20;
    else if (N == 9) numToRemove = 40;
    while (numToRemove > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            --numToRemove;
        }
    }
}

// Function to check if the user's solution matches the solved puzzle
bool Sudoko::validateSolution()
{
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != solvedGrid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    
}
void Sudoko::userSolvePuzzle()
{
    generatePuzzle();
    cout << "Sudoku Puzzle:\n";
    printGrid();
    cout << "Solve the puzzle (enter numbers row-wise):\n";
    for (int i = 0; i < N; ++i) 
    {
        cout << "Row " << (i + 1) << ": ";
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    if (validateSolution()) {
        cout << "Congratulations! You solved the Sudoku puzzle correctly.\n";
    }
    else {
        cout << "Sorry, your solution is incorrect.\n";
        cout << "The correct solution is:\n";
        printSolvedGrid();
        
    }
    system("pause");
    system("cls");
}
void Sudoko::userProvidedPuzzle() const
{
    cout << "Enter the Sudoku puzzle (use 0 for empty cells):\n";
    for (int i = 0; i < N; ++i) {
        cout << "Row " << (i + 1) << ": ";
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
}

Sudoko::~Sudoko()
{
    for (int i = 0;i < N;i++)
    {
        delete grid[i];
        delete solvedGrid[i];
    }
    delete [] grid;
    delete [] solvedGrid;
}
