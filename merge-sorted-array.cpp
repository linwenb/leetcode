/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n == 0) return;
        
        int cur = m + n - 1;
        
        while (m > 0 && n > 0) {
            if (A[m - 1] > B[n - 1]) {
                A[cur] = A[m - 1];
                m--;
            }
            else {
                A[cur] = B[n - 1];
                n--;
            }
            
            cur--;
        }	//	copy starting from the end of A, 
        
        while (n > 0) {
            A[cur] = B[n - 1];
            cur--;
            n--;
        }	//	m == 0, copy remaining elements in B

        //	n == 0, no need to copy remaining elements in A
        //	since they are already there
    }	//	O(n + m) time, O(1) space
};