/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0) return 0;	//	empty array
        
        if (target < A[0]) return 0;	//	insert at the front
        if (target > A[n-1]) return n;	//	insert at the end
        
        int low = 0;
        int high = n - 1;
        int mid;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (target < A[mid]) {
                if (target > A[mid-1])	return mid;

                high = mid - 1;
            }
            else if (target > A[mid]) {
                low = mid + 1;
            }
            else {
                return mid;
            }   //  target == A[mid]
        }

        return mid;
    }	//	O(log n) time, O(1) space
};