/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int n = triangle.size();	//	number of levels
        if (n == 0)   return 0;
        
        //	first and last elements on a row have only one adjacent number
        //	use INT_MAX to represent the other unexisted adjacent number
        vector<int> ans(n + 1, INT_MAX);
        ans[1] = 0;

        int temp, pre;
        
        for (int i = 0; i < n; i++) {
            pre = INT_MAX;

            for (int j = 0; j <= i; j++) {
                temp = ans[j + 1];
                ans[j + 1] = min(pre, temp) + triangle[i][j];

                pre = temp;
            }   //  go through elements on a row
        }   //  go through rows
        
        return *min_element(ans.begin(), ans.end());	//	min_element() return iterator
    }   //  O(n^2) time, O(n) space
};