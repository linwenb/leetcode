/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        /*
        1. Scan the string
        2. stack, matching pair pop, otherwise push index
        3. stack only contain the indices of not matched chars
        4. check longest valid substring
        */        
        int n = s.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (st.empty() == false && s[st.top()] == '(') {
                st.pop();
            }   //  s[i] == ')'
            else {
                st.push(i);
            }   //  st.empty() || s[st.top()] == ')'
        }
        
        if (st.empty() == true)	return n;	//	whole string is valid
        
        int ans = 0;
        int left;           //  index i - 1, if valid substr s[i : j]
        int right = n - 1;  //  index j, if valid substr s[i : j]
        
        while (st.empty() == false) {
            left = st.top();
            st.pop();
            
            if (right - left > ans) ans = right - left;
            
            right = left - 1;
        }
        
        //	after the while loop, right may be the index i, s.t. valid substr s[0 : i]
        return (ans > right + 1) ? ans : right + 1;
    }	//	O(n) time, O(n) space
};