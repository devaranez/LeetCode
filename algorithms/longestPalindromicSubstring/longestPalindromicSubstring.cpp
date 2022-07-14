/**
5. Longest Palindromic Substring
Medium

10017

663

Add to List

Share
Given a string s, return the longest palindromic substring in s.

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    bool isPalin(string& s, int st, int ed, vector<vector<short>>& res) {
        if (st >= ed) return true;
        if (res[st][ed] >= 0) return res[st][ed];

        bool valid = (s[st] == s[ed]) && isPalin(s, st + 1, ed - 1, res);
        res[st][ed] = valid;
        return valid;
    }
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        
        const int N = s.size();
        vector<vector<short>> res(N, vector<short>(N, -1)); // res[i][j]: substring of s from index i to j (inclusive)
        // -1: unknown, 0: not palindrome, 1: is palindrome
        int st = 0, ed = 0;

        for (int i = 0; i + (ed - st + 1) < s.size(); ++i) {
            for (int j = i + (ed - st + 1); j < s.size(); ++j) {
                if (isPalin(s, i, j, res)) {
                    if (j - i > ed - st) {
                        st = i;
                        ed = j;
                    }
                }
            }
        }
        return s.substr(st, ed - st + 1);
    }
};

void main() {
    string str("aacabdkacaa");
    Solution s;
    auto out = s.longestPalindrome(str);
    cout << out << endl;
}

