/**
654. Maximum Binary Tree
Medium

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

Example

Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]
Explanation: The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
- The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
- Empty array, so no child.
- The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
- Empty array, so no child.
- Only one element, so child is a node with value 1.
- The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
- Only one element, so child is a node with value 0.
- Empty array, so no child.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* helper(vector<int>& A, int st, int ed) {
        if (st > ed) return nullptr;
        else if (st == ed) return new TreeNode(A[st]);

        auto result = std::max_element(A.begin() + st, A.begin() + ed + 1);
        int idMax = std::distance(A.begin(), result);

        TreeNode* node = new TreeNode(A[idMax]);
        node->left = helper(A, st, idMax - 1);
        node->right = helper(A, idMax + 1, ed);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main() {

}