/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans(2);
        
        ans[0] = startPos(A, n, target);
        
        if (ans[0] == -1) {
            ans[1] = -1;
        }
        else {
            ans[1] = endPos(A, n, target);
        }
        
        return ans;
    }	//	O(log n) time, O(1) space
    
    int startPos(int A[], int n, int target) {
        if (n <= 0) return -1;
        //	find the smallest index i, s.t. A[i] == target
        
        int s = -1;  //  important !!
        int e = n - 1;
        int mid;
        
        //  stop when < 2 elements left to avoid infinite loop
        while (s + 1 < e) {
            mid = s + (e - s) / 2;
            
            if (A[mid] >= target) {
                e = mid;
            }
            else {
                s = mid;
            }   //  A[mid] < target
        }
        
        return A[e] == target ? e : -1;
    }
    
    int endPos(int A[], int n, int target) {
    	//	find the greatest index i, s.t. A[i] == target

        int s = 0;
        int e = n;  //  important !!
        int mid;
        
        while (s < e - 1) {
            mid = s + (e - s) / 2;
            
            if (A[mid] <= target) {
                s = mid;
            }
            else {
                e = mid;
            }   //  A[mid] > target
        }
        
        return A[s] == target ? s : -1;   
    }
};