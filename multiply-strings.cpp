/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        /*
                43
               127
            ------
               301
               86
              43
            ------  
        */
        list<char> lst;
        
        int n1 = num1.size();
        int n2 = num2.size();
        
        int carry = 0;
        int t2, t1;
        
        for (int k = 0; k < n1 + n2 - 1; k++) {
            t2 = (k < n1) ? 0 : k - n1 + 1;  //  not calculate lower digits of num2 after k >= n1
            t1 = (k < n1) ? k : n1 - 1;      //  correspondingly, always start with first digit of num1
            
            for (int i = n2 - 1 - t2, j = n1 - 1 - t1; i >= 0 && j < n1; i--, j++) {
                carry += (num1[j] - '0') * (num2[i] - '0');
            }
            
            lst.push_front(carry % 10 + '0');	//	value at k pos
            carry /= 10;
        }
        
        while (carry > 0) {
            lst.push_front(carry % 10 + '0');
            carry /= 10;
        }	//	until carry is zero
        
        while (lst.size() > 1 && lst.front() == '0') {
            lst.pop_front();
        }   //  remove until last digit if '00000' 
        
        string ans(lst.begin(), lst.end());        
        return ans;
    }	//	O(n * m) time, O(n + m) space
};