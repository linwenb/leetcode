/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /*
        two methods in one transaction case
        1. move forward with the lowest price and profit in record.
        2. move backward with the highest price and profit in record.
        
        two transaction case
        record history and future for each time point
        */
        
        int n = prices.size();
        if (n == 0) return 0;
                
        vector<int> history(n, 0);  //  O(n) space

        int lowest = prices.front();
        for (int i = 1; i < n; i++) {
            if (prices[i] < lowest) lowest = prices[i];
            
            history[i] = max(prices[i] - lowest, history[i - 1]);
        }   //  forward, store max profit on each day into history[]
        
        int ans = 0;
        int temp;

        int highest = prices.back();        
        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] > highest) highest = prices[i];
            
            temp = highest - prices[i] + history[i];    
            if (temp > ans) ans = temp;
        }   //  backward, calculate profit on each day, and sum up with hitstory
        
        return ans;
    }   //  O(n) time, O(n) space
};