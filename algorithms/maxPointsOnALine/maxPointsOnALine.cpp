/**
149. Max Points on a Line
Hard

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

**/
#include <iostream>
#include <vector>

#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    long gcd(long a, long b) {
        while (a * b != 0) {
            if (b >= a)
                b = b % a;
            else
                a = a % b;
        }
        return max(a, b);
    }
    /**
        compute the simplest form of fraction b/a 
        a will always be positive
    */
    void reduceFraction(long&a, long&b) {
        if (a == 0) 
            b = 1;        
        if (b == 0)
            a = 1;

        else {
            int x = gcd(abs(a), abs(b));
            if (a * b < 0)
                b = -abs(b) / x;
            else
                b = abs(b) / x;
            a = abs(a) / x;
        }
    }

    void yIntercept(long &x, long &y, long a, long b) {
        if (a == 0) {   // no y intercept
            y = x;
            x = 0;            
        }
        else {
            b = a * y - b * x;
            reduceFraction(a, b);

            x = a;
            y = b;
        }
    }

public:
    /**
        this can be solved by hough transform
        every pair of points can be described as: (0, y) + (a, b)*t

        the idea is to group every pair of point by (y, a, b)
        y, a, b should be simplest 

    */
    int maxPoints(vector<vector<int>>& A) {
        if (A.size() <= 2) return A.size();

        map<vector<long>, set<int>> mapVote;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                auto &p0 = A[i];
                auto &p1 = A[j];

                long a = p1[0] - p0[0];
                long b = p1[1] - p0[1];
                reduceFraction(a, b);

                long x = p0[0];
                long y = p0[1];

                yIntercept(x, y, a, b);

                vector<long> key{ x,y, a, b };
                mapVote[key].insert(i);
                mapVote[key].insert(j);               
            }
        }

        int out = 0;
        for (auto it = mapVote.begin(); it != mapVote.end(); ++it) {
            out = it->second.size() > out ? it->second.size() : out;
        }

        return out;
    }
};

void main() {
    vector<vector<int>> input = { {1, 1},{3, 2},{5, 3},{4, 1},{2, 3},{1, 4} };
    Solution s;
    int out = s.maxPoints(input);

    cout << out << endl;
}

