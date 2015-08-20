/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        int ans = 0;

        if (n < 3) {
            for (int i = 0; i < n; i++) ans += num[i];

            return ans;
        }
        
        sort(num.begin(), num.end());
        
        int ansDiff = INT_MAX;
        int sum, diff;  //  temp ans, temp ansDiff
        int st, end;    //  index
        
        for (int i = 0; i < n - 2; i++) {
            st = i + 1;
            end = n - 1;

            while (st < end) {
                sum = num[i] + num[st] + num[end];
                diff = abs(sum - target);

                if (diff < ansDiff) {
                    ansDiff = diff;
                    ans = sum;
                }
                
                if (sum < target) st++;
                else end--;
            }   //  two sum method
        }
        
        return ans;
    }   //  O(n^2) time, O(1) space

};