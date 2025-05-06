/*
121. Best Time to Buy and Sell Stock
Solved
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxx = 0;
        int minPrice = INT_MAX;
        int maxProfit = 0 ;
        

        /*
               ✅ Brute Approach O(n^2)
               for (int i = 0; i < prices.size() - 1; i++)
               {
                   for (int j = i; j < prices.size(); j++)
                   {
                       if (prices[j] - prices[i] > maxx)
                       {
                           maxx = prices[j] - prices[i];
                       }
                   }
               }

            ✅ Two Variable Approach O(n)
       */
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else
            {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }
};

int main()
{
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit (Test Case 1): " << sol.maxProfit(prices1) << endl;

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max Profit (Test Case 2): " << sol.maxProfit(prices2) << endl;

    return 0;

}
