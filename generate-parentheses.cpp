/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;        
        generateParenthesis(ans, string(), n, n);        
        return ans;
    }	//	O(?) time, O(?) space
    
    void generateParenthesis(vector<string> &ans, const string s, const int nLeft, const int nRight) {
        if (nLeft == 0 && nRight == 0)    ans.push_back(s);	//	reach end, one combination
        
        if (nLeft > 0)	generateParenthesis(ans, s + '(', nLeft - 1, nRight);	//	append left, if there is quota for left
        
        if (nLeft < nRight)	generateParenthesis(ans, s + ')', nLeft, nRight - 1);	//	append right, if the number of left is less
    }
};