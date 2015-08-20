/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n == 0) return false;
        
        int start = 0;
        int end = n - 1;
        int mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            
            if (A[mid] == target) {
                return true;
            }   //  found !
            else if (A[start] < A[mid]) {
                if (A[start] <= target && target < A[mid]) {
                    end = mid - 1;    
                }   //  target in left part
                else {
                    start = mid + 1;
                }
            }   //  left part is sorted
            else if (A[start] > A[mid]) {
                if (A[mid] < target && target <= A[end]) {
                    start = mid + 1;
                }   //  target in right part
                else {
                    end = mid - 1;
                }
            }   //  right part is sorted
            else {  //  A[start] == A[mid]
                return search(A + start, mid - start, target)
                    || search(A + mid + 1, end - mid, target);
            }   //  need to check both sides, it could be in either part
            
        }
        
        return false;  // not found
    }   //  O(log n) time, O(1) space
};