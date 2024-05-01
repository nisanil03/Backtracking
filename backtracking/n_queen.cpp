/*#include <bits/stdc++.h>
using namespace std;

void printsolution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
    // check karna chate hai ,
    // ki kay mai current cell [row, col] pr.... QUEEN rak
    // sakta hu ya nahi
    int i = row;
    int j = col;
    // check row
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }
    // check upper left digonal
    i = row;
    i = col;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }

    // check down left digonal
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }
    // kahi par bhi QUEEN nahi mile
    // iska matlab ye possion safe hai
    // iska matlab return kar do true
    return true;
}
void solve(vector<vector<char>> &board, int col, int n)
{
    // base case
    if (col >= n)
    {
        printsolution(board, n);
        return;
    }

    // 1=> case solve karna hai , baki recursion dhak lega

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // queen rak k dhakna hai
            board[row][col] = 'Q';
            // recursive solution lega
            solve(board, col + 1, n);
            // backtracking
            board[row][col] = '-';
        }
    }
}

int main()
{
    int n = 6;

    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    // 0 -> empty cell
    // 1->queen at the call

    solve(board, col, n);

    return 0;
}*/
//---------------------------------------**************************************---------------------------------------------------
// another wat using map

class Solution
{
public:
    unordered_map<int, bool> rowcheck;
    unordered_map<int, bool> upperleftDigonalCheck;
    unordered_map<int, bool> lowerleftDigonalCheck;
    void storesolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans)
    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string output = "";
            for (int j = 0; j < n; j++)
            {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }
    bool isSafe(int row, int col, vector<vector<char>> &board, int n, vector<vector<string>> &ans)
    {
        if (rowcheck[row] == true)
            return false;

        if (upperleftDigonalCheck[n - 1 + col - row] == true)
            return false;

        if (lowerleftDigonalCheck[row + col] == true)
            return false;
        return true;
    }
    void solve(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans)
    {
        // base case
        if (col >= n)
        {
            storesolution(board, n, ans);
            return;
        }
        for (int row = 0; row < n; row++)
        {

            if (isSafe(row, col, board, n))
            {
                // queen rak k dhakna hai
                board[row][col] = 'Q';
                rowcheck[row] = true;
                upperleftDigonalCheck[n - 1 + col - row] = true;
                lowerleftDigonalCheck[row + col] = true;

                // recursive solution lega
                solve(board, col + 1, n);
                // backtracking
                board[row][col] = '.';
                rowcheck[row] = false;
                upperleftDigonalCheck[n - 1 + col - row] = false;
                lowerleftDigonalCheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0;
        // 0 -> empty cell
        // 1->queen at the call

        solve(board, col, n, ans);
        return ans;
    }
};