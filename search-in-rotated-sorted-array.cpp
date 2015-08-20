/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(int A[], int n, int target) {
        if (n <= 0) return -1;
        
        int start = 0;
        int end = n - 1;
        int mid;
        
        while (start <= end) {
            mid = start + (end - start) * 0.5;
            
            if (A[mid] == target) {
                return mid;
            }   //  found !
            else if (A[start] <= A[mid]) {
                if (A[start] <= target && target < A[mid]) {
                    end = mid - 1;    
                }   //  target in left part
                else {
                    start = mid + 1;
                }   //  target in right part
            }   //  left part is sorted
            else {
                if (A[mid] < target && target <= A[end]) {
                    start = mid + 1;
                }   //  target in right part
                else {
                    end = mid - 1;
                }   //  target in left part
            }   //  right part is sorted
        }
        
        return -1;  // not found
    }	//	O(log n) time, O(1) space
};