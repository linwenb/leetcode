/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i];	//	occur twice
            ones ^= A[i];			//	occur once, clear if twice
            threes = ones & twos;	//	occur three times
            ones &= ~threes;		//	clear if three times
            twos &= ~threes;		//	clear if three times
        }
        
        return ones;	//	the number occurs only once
    }   //  O(n) time, O(1) space
};