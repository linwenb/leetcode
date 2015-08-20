/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;   // negative number is not palindrome
        
        int n = 1;  //  x = 2112, n = 1000
        
        while (x / n > 9) n *= 10;
        
        //  n == 1, only one digit, true
        //  n == 0, no digit left, true
        //  x == 0, all zero, true
        while (x > 0 && n > 1) {
            //  first and last digit not equal
            if (x / n != x % 10)    return false;
            
            x -= x / n * n;     //  remove the highest digit, x = 112
            
            x /= 10;    //  remove the lowest digit, x = 11
            n /= 100;   //  we remove two digits, n = 10
        }
        
        return true;
    }   //  O(k) time, O(1) space
};