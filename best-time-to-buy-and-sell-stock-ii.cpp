/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        int ans = 0;
        
        int minimal = 0;    //  local minimal
        int maximal = 0;    //  local maximal

        while (maximal + 1 < n && minimal + 1 < n) {
            minimal = maximal;
            while (minimal + 1 < n && prices[minimal] >= prices[minimal + 1]) {
                minimal++;
            }   //  find minimal

            maximal = minimal;
            while (maximal + 1 < n && prices[maximal] <= prices[maximal + 1]) {
                maximal++;
            }   //  find maximal

            ans += prices[maximal] - prices[minimal];   //  one transaction
        }

        return ans;
    }   //  O(n) time, O(1) space
};