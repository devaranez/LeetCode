/**
122. Best Time to Buy and Sell Stock II
Easy

You are given an array prices for which the ith element is the price of a given stock on day i.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e., max profit = 0.


Constraints:

1 <= prices.length <= 3 * 10^4
0 <= prices[i] <= 10^4

**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
    out[i] = best profit from day 0 to day i
    we can assume the last transaction to achieve out[i] is always "sell on day i" 
    because do nothing on day i can be see as "buy on day i & sell on day i"

    so if price on day i+1 is higher then the one on day i, we update out[i+1] = out[i] + price[i+1] - price[i]

    update: we dont need to maintain an array of best profit
*/
class Solution {
public:
    int maxProfit(vector<int>& A) {
        int out = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i - 1])
                out += (A[i] - A[i - 1]);
        }
        return out;
    }
};

void main() {
    vector<int> prices{ 7, 1, 5, 3, 6, 4 };

    Solution sol;
    cout << sol.maxProfit(prices)<<endl;    
}

