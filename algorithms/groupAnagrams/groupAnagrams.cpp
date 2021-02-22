/**
49. Group Anagrams
Medium

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.

**/
#include <iostream>
#include <vector>

#include <algorithm>
#include <map>

using namespace std;

class Solution {
    string sorted(string str) {
        string out = str;
        sort(out.begin(), out.end());
        return out;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;

        for (auto x : strs)
            m[sorted(x)].push_back(x);

        vector<vector<string>> out;
        for (auto it = m.begin(); it != m.end(); ++it)
            out.push_back(it->second);
    
        return out;
    }
    
};

void main() {
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    Solution s;
    vector<vector<string>> out = s.groupAnagrams(strs);

    for (auto& row : out) {
        for (auto& x : row)
            cout << x << ", ";            
        cout << endl;
    }

}

