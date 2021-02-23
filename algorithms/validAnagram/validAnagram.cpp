/**
242. Valid Anagram
Easy

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
    To handle unicode characters I would use map instead of array.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for (auto& c : s)
            count[c - 'a']++;

        for (auto& c : t)
            count[c - 'a']--;

        for (auto& v : count)
            if (v != 0) return false;
        return true;
    }
};

void main() {
    string s = "anagram", t = "nagaram";

    Solution sol;
    bool out = sol.isAnagram(s,t);

    cout << out << endl;
}

