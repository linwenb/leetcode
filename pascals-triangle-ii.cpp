/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        
        int pre, temp;

        for (int i = 0; i < rowIndex - 1; i++) {
            pre = 1;	//	the leftmost is always 1

            for (int j = 1; j <= (i + 1) / 2; j++) {
                temp = ans[j];
                ans[j] += pre;
                pre = temp;
            }	//	construct the left half
            
            if ((i & 1) == 0) {
                ans[i / 2 + 1] = 2 * pre;
            }	//	if i is even, construct the number on middle of the new row
        }
        
        for (int i = 0, j = rowIndex; i < j; i++, j--) {
            ans[j] = ans[i];
        }	//	copy the right half
        
        return ans;
    }   //  O(k^2) time, O(k) space
};