/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
    	int n = s.size();
    	if (n == 0)	return true;

        stack<char> _stack;        
        unordered_map<char, char> _map;	//	for fast match
        
        _map[')'] = '(';
        _map['}'] = '{';
        _map[']'] = '[';
        
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case '(':
                case '{':
                case '[':
                    _stack.push(s[i]);	//	push left one into stack
                    break;
                    
                default:	//	right one
                    if (_stack.empty() || _stack.top() != _map[s[i]])	return false;	//	incorrect order
                    _stack.pop();	//	matches the left one, at the top of stack
            }
        }

        return _stack.empty();	//	true if empty
    }	//	O(n) time, O(n) space
};