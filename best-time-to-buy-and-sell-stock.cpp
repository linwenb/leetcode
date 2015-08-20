/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int lowest = INT_MAX;
        
        int ans = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lowest) lowest = prices[i];		//	potential buy time
            if (prices[i] - lowest > ans)   ans = prices[i] - lowest;	//	buy at lowest, sell at i
        }

        return ans;
    }	//	O(n) time, O(1) space
};