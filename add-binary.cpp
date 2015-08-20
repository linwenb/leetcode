/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"

Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        
        int maxSize = max(m, n);
        
        string ans(maxSize, '0');

        int carry = 0;
        int j, k, t;    //  temp
        
        for (int i = 0; i < maxSize; i++) {
            j = (i < m) ? a[m - 1 - i] - '0': 0;
            k = (i < n) ? b[n - 1 - i] - '0': 0;
            
            t = j + k + carry;  //  total summation
            
            carry = t >> 1;     //  carry
            if (t & 1)    ans[maxSize - 1 - i] = '1';   //  sum at i
        }
        
        return (carry == 0) ? ans : "1" + ans;  
    }   //  O(n + m) time, O(1) space
};