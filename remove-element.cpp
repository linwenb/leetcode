/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int ans = 0;	//	new length

        for (int i = 0; i < n; i++) {
            while (A[i] == elem && i < n)	i++;	//	ignore that value
            
            if (i < n) {
                A[ans] = A[i];
                ans++;
            }
        }

        return ans;
    }
};