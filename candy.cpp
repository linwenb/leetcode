/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:
	Each child must have at least one candy.
	Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?
*/

class Solution {
public:
    int candy(vector<int> &ratings) {    	
        int n = ratings.size();
        if (n == 0) return 0;
        
        int ans = n;    //  initialization, each child gets one
        int incrRange, decrRange;
        int start;      //  start index of increasing or decreasing range
        
        for (int i = 0; i < n - 1;) {
            //  same rating
            while (ratings[i] == ratings[i+1] && i < n - 1) i++;
            
            if (i == n - 1) break;
            
            //  increasing rating if exists
            start = i;
            while (ratings[i] < ratings[i+1] && i < n - 1) i++;
            incrRange = i - start;
            //  from the second child, add 1, 2, 3... candies
            if (incrRange > 0)   ans += (incrRange * (incrRange + 1)) / 2;
            
            if (i == n - 1) break;
            
            //  decreasing rating if exists
            start = i;
            while (ratings[i] > ratings[i+1] && i < n - 1) i++;
            decrRange = i - start;
            //  not consider the candies of child with peak rating here
            if (decrRange > 1)  ans += (decrRange * (decrRange - 1)) / 2;
            //  the child with peak rating should have more candies than his right neighbor
            if (decrRange > incrRange)  ans += decrRange - incrRange;
        }
        
        return ans;
    }	//	O(n) time, O(1) space
};