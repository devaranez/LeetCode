/**
230. Kth Smallest Element in a BST
Medium

Given the root of a binary search tree, and an integer k, return the kth(1 - indexed) smallest element in the tree.

Example 1:
Input: root = [3, 1, 4, null, 2], k = 1
Output : 1

Example 2 :
Input : root = [5, 3, 6, 2, 4, null, null, 1], k = 3
Output : 3

Constraints :

The number of nodes in the tree is n.
1 <= k <= n <= 10^4
0 <= Node.val <= 10^4

Follow up : If the BST is modified often(i.e., we can do insertand delete operations) and you need to find the kth smallest frequently, how would you optimize ?
**/
#include <vector>
#include <iostream>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // return # nodes in the tree 'root'
    int countAndFind(TreeNode* root, int k, TreeNode* &tar) {
        if (!root) return 0;
        int numLeft = countAndFind(root->left, k, tar);
        if (numLeft == k - 1) {
            tar = root;
            return k;   // no need to count #right
        }
        else if (numLeft >= k) {
            // tar must have been found
            return numLeft + 1;
        }
        else {
            int numRight = countAndFind(root->right, k - numLeft - 1, tar);
            return numLeft + numRight + 1;
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* tar;
        countAndFind(root, k, tar);
        return tar->val;
    }
};

void main() {
    vector<int> nodes{ 5,3,6,2,4,-1,-1,1 };
    int k = 3;

    vector<TreeNode*> vecNodes(nodes.size());
    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i] >= 0)
            vecNodes[i] = new TreeNode(nodes[i]);
        else
            vecNodes[i] = nullptr;
        if (i > 0 && i % 2 == 1)
            vecNodes[(i - 1) / 2]->left = vecNodes[i];
        else if (i>0 && i%2 == 0)
            vecNodes[(i - 2) / 2]->right = vecNodes[i];
    }

    Solution s;
    int out = s.kthSmallest(vecNodes[0], k);
    cout << out << endl;

}