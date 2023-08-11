#include <iostream>
#include <array>
#define N 9

int grid[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

bool inCol(int col, int num);
bool inCol(int col, int num)
{
    for(int row = 0; row < N; row++)
    {
        if(grid[row][col] == num) return true;
    }
    return false;
}

bool inRow(int row, int num);
bool inRow(int row, int num)
{
    for(int col = 0; col < N; col++)
    {
        if(grid[row][col] == num) return true;
    }
    return false;
}

bool inBox(int row, int col, int num);
bool inBox(int row, int col, int num)
{
    int rowStart = (row/3)*3;
    int colStart = (col/3)*3;

    for(int r = rowStart; r < rowStart + 3; r++)
    {
        for(int c = colStart; c < colStart + 3; c++)
        {
            if(grid[r][c] == num) return true;
        }
    }
    return false;
}

bool isValidPlace(int row, int col, int num);
bool isValidPlace(int row, int col, int num)
{
    return !inRow(row,num) && !inCol(col,num) && !inBox(row,col,num);
}

bool isFilled();
bool isFilled()
{
    for(int row = 0; row < N; row++)
    {
        for(int col = 0; col < N; col++)
        {
            if(grid[row][col] == 0) return false;
        }
    }
    return true;
}

bool sudokuSolver()
{
    if(isFilled()) return true;
    for(int row = 0; row < N; row++)
    {
        for(int col = 0; col < N; col++)
        {
            if(grid[row][col] == 0)
            {
                for(int num = 1; num <= 9; num++)
                {
                    if(isValidPlace(row,col,num))
                    {
                        grid[row][col] = num;
                        if(sudokuSolver()) return true;
                        grid[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }
}

void sudokuGrid();
void sudokuGrid()
{
    for(int row = 0; row < N; row++)
    {
        for(int col = 0; col < N; col++)
        {
            if(col == 2 || col == 5)
                std::cout << grid[row][col] << " | ";
            else
                std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
        if(row == 2 || row == 5)
            std::cout << "---------------------" << std::endl;
    }
    return;
}
int main()
{
    if(sudokuSolver())
        sudokuGrid();
    else
        std::cout << "No Solution exists";
    return 0;
}