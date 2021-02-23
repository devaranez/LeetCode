/**
287. Find the Duplicate Number
Medium

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2


Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


Example 3:

Input: nums = [1,1]
Output: 1


Example 4:

Input: nums = [1,1,2]
Output: 1


Constraints:

2 <= n <= 3 * 104
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
    let N = array.size(), every array value is between 1 to N-1
    so we can see the array as a linked list, the value indicates the index of the next node
    there is a duplicated integer means there must be a cycle
    the cycle can be visited from A[0] because A[0]!=0, because node 0 does not go to itself and no other node goes to node 0

*/
class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int one = A[0];
        int two = A[one];

        while (one != two) {
            one = A[one];
            two = A[A[two]];
        }

        two = 0;

        while (one != two) {
            one = A[one];
            two = A[two];
        }

        return one;
    }
};

void main() {
    vector<int> nums = { 3, 1, 3, 4, 2 };
    
    Solution sol;
    cout << sol.findDuplicate(nums)<<endl;
    
    
}

