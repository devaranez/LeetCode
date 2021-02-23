/**
283. Move Zeroes
Easy

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& A) {
        const int N = A.size();
        int last0 = -1;
        int last1 = -1;
        int id0 = -1;
        int id1 = -1;
        while (true) {
            for (int i = last0 + 1; i < N && id0 < 0; ++i) 
                if (id0 < 0 && !A[i])
                    id0 = i;                
            
            for (int i = max(id0, last1) + 1; i < N && id1 < 0; ++i)
                if (id1 < 0 && A[i])
                    id1 = i;

            if (id0 >= 0 && id1 > id0) {
                swap(A[id0], A[id1]);
                last0 = id0;
                last1 = id1;
                id0 = id1 = -1;
            }
            else
                break;
        }
    }
};

void main() {
    vector<int> in{ 0,1,0,3,12 };

    Solution sol;
    sol.moveZeroes(in);

    for (auto& x : in)
        cout << x << ", ";
    cout << endl;
}

