/**
289. Game of Life
Medium

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

Example 1:

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]


Example 2:

Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]


Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.


Follow up:

Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

**/
#include <iostream>
#include <vector>
#include <algorithm>

#include <queue>
using namespace std;

/**
    to solve it in-place: use -1 to denote "was 0 and will be 1", 2 as "was 1 and will be 0", then update the numbers again
    if the board is infinite, reallocate larger array if needed

    From Discussion: use bit manupulation to speedup
*/
class Solution {
    void futureState(vector<vector<int>> &A, int i, int j) {
        const int M = A.size();
        const int N = A[0].size();
        int count = 0;
        if (i > 0) {
            if (j > 0 && A[i - 1][j - 1] > 0) count++;
            if (A[i - 1][j] > 0) count++;
            if (j + 1 < N && A[i - 1][j + 1] > 0) count++;
        }

        if (j > 0 && A[i][j - 1] > 0) count++;
        if (j + 1 < N && A[i][j + 1] > 0) count++;

        if (i + 1 < M) {
            if (j > 0 && A[i + 1][j - 1] > 0) count++;
            if (A[i + 1][j] > 0)count++;
            if (j + 1 < N && A[i + 1][j + 1] > 0) count++;
        }
        
        if (A[i][j] == 0 && count == 3) A[i][j] = -1;
        else if (A[i][j] && (count<2||count > 3)) 
            A[i][j] = 2;        
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                futureState(board, i, j);

        for (auto &row: board)
            for (auto& x : row) {
                if (x > 1) x = 0;
                else if (x < 0) x = 1;
            }
    }
};

void main() {
    vector<vector<int>> board{ {0,1,0},{0,0,1},{1,1,1},{0,0,0} };

    int k = 4;

    Solution sol;
    sol.gameOfLife(board);
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j)
            cout << board[i][j] << ", ";
        cout << endl;
    }
}

