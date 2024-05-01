#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y, int row, int col, int arr[3][3], vector<vector<bool>> &visited)
{
   if (((x >= 0 && x < row) && (y >= 0 && y < col)) && (arr[x][y] == 1) && (visited[x][y] == false))
   {
      return true;
   }
   else
   {
      return false;
   }
}

void solveMaze(int arr[3][3], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string output)
{
   // base case
   if (i == row - 1 && j == col - 1)
   {
      // answer found
      path.push_back(output);
      return;
   }
   // Down ka 1->case solved karna hai (i+1 , j)

   if (isSafe(i + 1, j, row, col, arr, visited))
   {
      visited[i + 1][j] = true;
      solveMaze(arr, row, col, i + 1, j, visited, path, output + 'D');
      // backtrack
      visited[i + 1][j] = false;
   }

   // Left ka 1->case solved karna hai (i,j-1)

   if (isSafe(i, j - 1, row, col, arr, visited))
   {
      visited[i][j - 1] = true;
      solveMaze(arr, row, col, i, j - 1, visited, path, output + 'L');
      // backtrack
      visited[i][j - 1] = false;
   }

   // Right ka  1->case solved karna hai (i,j+1)

   if (isSafe(i, j + 1, row, col, arr, visited))
   {
      visited[i][j + 1] = true;
      solveMaze(arr, row, col, i, j + 1, visited, path, output + 'R');
      // backtrack
      visited[i][j + 1] = false;
   }

   // Up ka  1->case solved karna hai (i-1,j)

   if (isSafe(i - 1, j, row, col, arr, visited))
   {
      visited[i - 1][j] = true;
      solveMaze(arr, row, col, i - 1, j, visited, path, output + 'U');
      // backtrack
      visited[i - 1][j] = false;
   }
}

int main()
{
   int arr[3][3] = {{1, 0, 0},
                    {1, 1, 0},
                    {1, 1, 1}};
   int row = 3;
   int col = 3;

   vector<vector<bool>> visited(row, vector<bool>(col, false));

   // source ki value ko true markes karne k liye

   visited[0][0] = true;

   vector<string> path;
   string output = "";

   solveMaze(arr, row, col, 0, 0, visited, path, output);

   cout << "printing the result " << endl;
   for (auto i : path)
   {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}