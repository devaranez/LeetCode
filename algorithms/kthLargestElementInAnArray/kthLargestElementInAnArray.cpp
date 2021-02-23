/**
215. Kth Largest Element in an Array
Medium

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

**/
#include <iostream>
#include <vector>
#include <algorithm>

#include <queue>
using namespace std;

class Heap {    
    int size;
    // do not confuse this with array.size(), maybe use a different name

    // added a new element to the end of the array
    // heapify from the end
    void siftUp() {
        int id = size - 1;
        while (id > 0) {
            if (array[id] > array[(id-1) / 2]) {
                swap(array[id], array[(id-1) / 2]);
                id = (id - 1) / 2;
            }
            else break;
        }
    }

    // the whole array except for the first element is a heap
    // heapify from the top
    void siftDown() {
        int id = 0;
        while (id*2+1 < size) {
            int left = array[id * 2 + 1];
            int right = array[id];
            if (id * 2 + 2 < size)
                right = array[id * 2 + 2];

            if (left >= right && left > array[id]) {
                swap(array[id], array[id * 2 + 1]);
                id = id * 2 + 1;
            }
            else if (right > left && right > array[id]) {
                swap(array[id], array[id * 2 + 2]);
                id = id * 2 + 2;
            }
            else break;
        }
    }

public:
    vector<int> array;
    Heap(int capacity) {
        array = vector<int>(capacity);
        size = 0;
    }

    // !! no handling if out of capacity
    void push(int val) {
        array[size++] = val;        
        siftUp();
    }

    int pop() {
        if (size > 0) {
            swap(array[0], array[size - 1]);
            size--;
            siftDown();
            return array[size];
        }
        else 
            return -1;
    }

};

/**
    use heap or priority queue
*/
class Solution {
    int helperPriorityQueue(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto& x : nums)
            pq.push(x);
        for (int i = 0; i < k - 1; ++i)
            pq.pop();
        return pq.top();
    }

    int helperHeap(vector<int>& nums, int k) {
        Heap h(nums.size());

        for (auto& x : nums)
            h.push(x);       

        for (int i = 0; i < k - 1; ++i) {
            cout << h.pop()<<endl;
        }
        return h.pop();
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return helperHeap(nums, k);
    }
};

void main() {
    vector<int> input{ 3,2,3,1,2,4,5,5,6 };
    int k = 4;

    Solution sol;
    cout << sol.findKthLargest(input, k) <<endl;
}

