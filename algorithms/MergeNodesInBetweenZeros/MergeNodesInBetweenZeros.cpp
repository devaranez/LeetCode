/**
2181. Merge Nodes in Between Zeros
Medium

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

Example:

Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]

Constraints:

The number of nodes in the list is in the range [3, 2 * 105].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
The beginning and end of the linked list have Node.val == 0.

**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* A) {
        A = A->next;
        ListNode* head = nullptr, * tail = nullptr;

        int sum = 0;
        while (A) {
            if (A->val == 0) {
                if (!head) {
                    head = tail = new ListNode(sum);
                }
                else {
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                }
                sum = 0;
            }
            else
                sum += A->val;
            A = A->next;
        }
        return head;
    }
};

ListNode* makeList(vector<int> A) {
    if (A.empty()) return nullptr;
    ListNode* head, * tail;
    head = tail = new ListNode(A[0]);
    for (int i = 1; i < A.size(); ++i) {
        tail->next = new ListNode(A[i]);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode* list) {
    while (list) {
        cout << list->val << ", ";
        list = list->next;
    }
    cout << endl;
}

int main() {
    std::vector<int>A{ 0,3,1,0,4,5,2,0 };
    ListNode* q = makeList(A);
    Solution s;
    ListNode* a = s.mergeNodes(q);
    printList(a);

    return 0;
}