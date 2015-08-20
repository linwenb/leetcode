/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
    	int n = tokens.size();

        stack<int> s;
        int a, b;
        
        for (int i = 0; i < n; i++) {
            if (isdigit( tokens[i].back() ) == true) {
                s.push( atoi(tokens[i].c_str()) );
                continue;
            }	//	curr token is a number, use back() because of -1
            
            //	curr token is an operator
            //	get the top two numbers
            b = s.top();	s.pop();
            a = s.top();	s.pop();
            
            switch(tokens[i].front())
            {
                case '+': a += b; break;
                case '-': a -= b; break;
                case '*': a *= b; break;
                case '/': a /= b; break;
            }
            
            s.push(a);	//	insert the result back into stack
        }
        
        return s.top();
    }   //  O(n) time, O(n) space
};