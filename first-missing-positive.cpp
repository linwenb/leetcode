/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
    	int curr, temp;
        //  Pass 1, move every value to the position of its value, A[0] = 1
        for (int i = 0; i < n; i++) {
            curr = A[i];

            while (curr > 0 && curr <= n && A[curr - 1] != curr) {
                temp = A[curr - 1];
                A[curr - 1] = curr;
                curr = temp;
            }
        }
        
        //  Pass 2, find first location where the index doesn't match the value
        for (int i = 0; i < n; i++)	if (A[i] != i + 1)  return i + 1;
                
        return n + 1;	//  n numbers are from 1 to n, first missing is n+1
    }	//	O(n) time, O(1) space
};