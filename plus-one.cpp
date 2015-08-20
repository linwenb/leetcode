/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();

        vector<int> ans(n); //  most significant digit is at the tail of the list
        
        int carry = 1;  //  plus one

        for (int i = 0, s = n - 1; i < n; i++) {            
            if (digits[s - i] + carry > 9) {
                ans[i] = 0;
                carry = 1;
            }   //  carry exists
            else {
                ans[i] = digits[s - i] + carry;
                carry = 0;
            }   //  no carry
        }
        
        if (carry == 1) ans.push_back(1);
        
        reverse(ans.begin(), ans.end());    //  most significant digit is at the head of the list
        
        return ans;
    }   //  O(n) time, O(1) space
};