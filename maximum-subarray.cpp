/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
    	if (n == 1)	return A[0];

        int maxSum = A[0];	//	optimal subarray with largest sum
        int sum = A[0];		//	temp, subarray with sum
    
        for (int i = 1; i < n; i++)
        {
            if (sum < 0) sum = 0;	//	subarray restart from i
            sum += A[i];

            if (sum > maxSum) maxSum = sum;
        }
    
        return maxSum;
    }	//	O(n) time, O(1) space
};