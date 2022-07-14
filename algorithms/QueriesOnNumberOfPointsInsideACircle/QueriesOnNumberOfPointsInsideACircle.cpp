/**
1828. Queries on Number of Points Inside a Circle
Medium

You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane.
Multiple points can have the same coordinates.
You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj)
with a radius of rj.
For each query queries[j], compute the number of points inside the jth circle.
Points on the border of the circle are considered inside.
Return an array answer, where answer[j] is the answer to the jth query.

Example:

Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
Explanation: The points and circles are shown above.
queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& circles) {
        // brute force
        vector<int> result(circles.size());
        for (int i = 0; i < circles.size(); ++i) {
            auto& A = circles[i];
            int count = 0;
            for (auto& p : points) {
                if ((p[0] - A[0]) * (p[0] - A[0]) + (p[1] - A[1]) * (p[1] - A[1]) <= A[2] * A[2]) count++;
            }
            result[i] = count;
        }
        return result;
    }
};

void printVector(const vector<int>& A) {
    for (auto& x : A)
        cout << x << ", ";
    cout << endl;
}

int main() {
    vector<vector<int>> points = { {1, 3}, {3, 3}, {5, 3}, {2, 2} };
    vector<vector<int>> queries = { {2, 3, 1}, {4, 3, 1}, {1, 1, 2} };

    Solution s;
    auto A = s.countPoints(points, queries);

    printVector(A);
}