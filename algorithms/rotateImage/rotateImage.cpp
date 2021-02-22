/**
48. Rotate Image
Medium

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
Example 3:

Input: matrix = [[1]]
Output: [[1]]
Example 4:

Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]


Constraints:

matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

**/
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class Solution {
    // rotate A[i][j] and its corresponding elements
    // (i, j) -> (j, N-1-i) -> (N-1-i, N-1-j) -> (N-1-j, i)
    
    void helper(vector<vector<int>>& A, int i, int j) {
        int N = A.size();
        int tmp = A[i][j];
        A[i][j] = A[N - 1 - j][i];
        A[N - 1 - j][i] = A[N - 1 - i][N - 1 - j];
        A[N - 1 - i][N - 1 - j] = A[j][N - 1 - i];
        A[j][N - 1 - i] = tmp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();

        int R = N / 2;
        int C = N / 2;
        if (N % 2 == 1) C++;

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                helper(matrix, i, j);
    }
};

void main() {
    vector<vector<int>> matrix = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    Solution s;
    s.rotate(matrix);

    for (auto& row : matrix) {
        for (auto& x : row)
            cout << x << ", ";            
        cout << endl;
    }

}

