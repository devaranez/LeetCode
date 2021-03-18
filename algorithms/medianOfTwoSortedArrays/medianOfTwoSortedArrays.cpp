/**
4. Median of Two Sorted Arrays
Hard

9467

1458

Add to List

Share
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int>::iterator iter;
class Solution {
    // assume k is valid
    int findKthInRange(iter ast, iter aed, iter bst, iter bed, int k) {
        iter mid = ast != aed ? ast + (aed - ast) / 2: bst+(bed-bst)/2;
        
        iter aLower = lower_bound(ast, aed, *mid);
        iter bLower = lower_bound(bst, bed, *mid);

        iter aUpper = upper_bound(ast, aed, *mid);
        iter bUpper = upper_bound(bst, bed, *mid);
        
        int less = (aLower - ast) + (bLower - bst);
        int notLarger = (aUpper - ast) + (bUpper - bst);

        if (less >= k) {    // target is smaller than *mid
            return findKthInRange(ast, aLower, bst, bLower, k);
        }
        else if (k > notLarger) {
            return findKthInRange(aUpper, aed, bUpper, bed, k - notLarger);
        }
        else return *mid;
    }
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        const int N = A.size() + B.size();
        // (N+1)/2;
        int x = findKthInRange(A.begin(), A.end(), B.begin(), B.end(), (N + 1) / 2);
        if (N % 2 == 1) return x;
        int y = findKthInRange(A.begin(), A.end(), B.begin(), B.end(), (N + 1) / 2 + 1);
        
        return 0.5 * (x+y);
    }
};

void main() {

    vector<int> A = { 2,3 };
    vector<int> B{ 0, 1 };
    
    Solution s;
    auto out = s.findMedianSortedArrays(A, B);
    cout << out << endl;
}

