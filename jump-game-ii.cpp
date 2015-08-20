/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    int jump(int A[], int n) {
        int ans = 0;        //  num of steps
        int reach = 0;      //  distance reached with ans steps
        int farthest = 0;   //  distance reached with ans+1 steps
        
        for (int i = 0; i < n; i++) {
            if (reach < i) {
                ans++;
                reach = farthest;
            }   //  cannot reach i, take one more step reaching farthest
            
            if (farthest < i + A[i])	farthest = i + A[i];	//	update farthest
        }
        
        return ans;
    }	//	O(n) time, O(1) space
};