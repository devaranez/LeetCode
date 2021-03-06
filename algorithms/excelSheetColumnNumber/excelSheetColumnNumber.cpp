﻿/**
171. Excel Sheet Column Number
Easy

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...

Example 1:

Input: "A"
Output: 1


Example 2:

Input: "AB"
Output: 28


Example 3:

Input: "ZY"
Output: 701


Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".

**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        unsigned int out = 0;
        for (auto& x : s)
            out = out * 26 + x - 'A' + 1;
        return out;
    }
};

void main() {
    string input = "FXSHRXW";
    Solution sol;
    cout << sol.titleToNumber(input);        
}

