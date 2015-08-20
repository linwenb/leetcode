/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int curr = 0;
        int counter = 0;
        
        for (int i = 0; i < n; i++) {
            A[curr] = A[i];
            
            if (counter == 0) {
                counter++;
            }   //  appear at first time
            else if (A[i] == A[curr-1]) {
                counter = 0;    //  reset counter

                //  remove duplicates appearing more than twice
                while (i + 1 < n && A[i+1] == A[curr-1])  i++;
            }   //  counter == 1, appear twice
            
            curr++;
        }
        
        return curr;    //  length after duplicates removed
    }   //  O(n) time, O(1) space
};