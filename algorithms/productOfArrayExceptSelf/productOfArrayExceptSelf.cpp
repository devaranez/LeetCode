/**
238. Product of Array Except Self
Medium

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

**/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:    
    // the algorithm operates on the output array -> constant space complexity
    vector<int> productExceptSelf(vector<int>& A) {
        int N = A.size();
        vector<int> out(A.size());
        out[0] = 1;

        for (int i = 1; i < N; ++i) 
            out[i] = A[i-1] * out[i - 1];
        
        int R = A[N-1];
        for (int i = N - 2; i >= 0; --i) {
            out[i] *= R;
            R *= A[i];
        }

        return out;
    }
};

void main() {
    vector<int> nums{ 1,2,3,4 };

    Solution s;
    vector<int> out = s.productExceptSelf(nums);
    for (auto& x : out)
        cout << x << ", ";
    cout << endl;
}