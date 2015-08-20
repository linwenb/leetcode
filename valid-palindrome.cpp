/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n == 0)  return true;
        
        int i = 0, j = n - 1;
        
        while (i < j) {
            if (isalnum(s[i]) == false) {
                i++;
                continue;
            }   //  considering only alphanumeric chars
            
            if (isalnum(s[j]) == false) {
                j--;
                continue;
            }   //  considering only alphanumeric chars
            
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }   //  ignoring cases, not palindrome
            
            i++;
            j--;
        }
        
        return true;    //  palindrome !!
    }   //  O(n) time, O(1) space
};