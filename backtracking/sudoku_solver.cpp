#include <bits/stdc++.h>
using namespace std;

bool isSafe(int value, int board[][9], int curr_row, int curr_col)
{
    // Row check -> same row changing column
    for (int col = 0; col < 9; col++)
    {
        if (board[curr_row][col] == value)
        {
            return false;
        }
    }
    // column check -> same column changing column
    for (int row = 0; row < 9; row++)
    {
        if (board[row][curr_col] == value)
        {

            return false;
        }
    }
    // 3*3 box cheacking
    for (int i = 0; i < 9; i++)
    {
        if (board[3 * (curr_row / 3) + (i / 3)][3 * (curr_col / 3) + (i % 3)] == value)
        {
            return false;
        }
    }
    return true; // safe value;
}
bool solve(int board[9][9], int n)
{
    // traversing the sudoku board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // insert only empty cell
            if (board[i][j] == 0)
            {
                for (int value = 1; value <= 9; value++)
                {
                    if (isSafe(value, board, i, j))
                    {
                        board[i][j] = value;
                        // recursive cell
                        bool aageSolution = solve(board, n);
                        // found solution or not?
                        // due to below line we don't need base case
                        if (aageSolution == true)
                        {
                            return true;
                        }
                        // Backtracking if solution not found
                        else
                            board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int board[9][9] = {{4, 5, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 2, 0, 7, 0, 6, 3, 0},
                       {0, 0, 0, 0, 0, 0, 0, 2, 8},
                       {0, 0, 0, 9, 5, 0, 0, 0, 0},
                       {0, 8, 6, 0, 0, 0, 2, 0, 0},
                       {0, 2, 0, 6, 0, 0, 7, 5, 0},
                       {0, 0, 0, 0, 0, 0, 4, 7, 6},
                       {0, 7, 0, 0, 0, 5, 0, 0, 0},
                       {0, 0, 8, 0, 0, 9, 0, 0, 0}};
    int n = 9;
    solve(board, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}