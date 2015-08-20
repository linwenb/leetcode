/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;

        if (total & 1) {
            return findKthElem(A, m, B, n, total / 2 + 1);
        }   // total is odd
        else {
            return 0.5 * (findKthElem(A, m, B, n, total / 2) + findKthElem(A, m, B, n, total / 2 + 1));
        }   // even
    }   //  O(log (m+n)) time, O(log (m+n)) space
    
    int findKthElem(int A[], int m, int B[], int n, int k) {
        // invariant: i + j = k - 1
        int i = (int)((double)m / (m + n) * (k - 1));
        int j = k - 1 - i;
        
        int Ai_1 = (i == 0) ? INT_MIN : A[i - 1];
        int Bj_1 = (j == 0) ? INT_MIN : B[j - 1];
        int Ai = (i == m) ? INT_MAX : A[i];
        int Bj = (j == n) ? INT_MAX : B[j];
        
        // found !!
        if (Bj_1 <= Ai && Ai <= Bj)   return Ai;
        if (Ai_1 <= Bj && Bj <= Ai)   return Bj;
        
        
        if (Ai < Bj) {
            return findKthElem(A + i + 1, m - i - 1, B, j, k - i - 1);
        }   //  exclude Ai and left, Bj and right
        else {
            return findKthElem(A, i, B + j + 1, n - j - 1, k - j - 1);
        }   //  exclude Ai and right, Bj and left
    }   //  O(log (m+n)) time, O(log (m+n)) space
};