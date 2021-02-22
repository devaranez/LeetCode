/**
347. Top K Frequent Elements
Medium

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

**/
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

/**
    1. count every number
    2. group by frequency (map from freq. to set )
    3. iterate the map    
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        map<int, int> num2count;
        for (auto& x : A) {            
            num2count[x]++;
        }

        map<int, set<int>> count2set;
        for (auto it = num2count.begin(); it != num2count.end(); ++it) {            
            //auto &num = it->first;            
            //auto &count = it->second;
            count2set[it->second].insert(it->first);
        }

        vector<int> out;
        for (auto it = count2set.rbegin(); it != count2set.rend() && k > 0; ++it) {
            auto nums = it->second;
            out.insert(out.end(), nums.begin(), nums.end());
            k -= nums.size();
        }

        return out;
    }
};

void main() {
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;

    Solution s;
    auto out = s.topKFrequent(nums, k);

    for (auto& x : out)
        cout << x << ", ";
    cout << endl;
}