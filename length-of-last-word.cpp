/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {        
        int i = strlen(s) - 1;	//  start from the end, not sizeof, but strlen
        
        while (i >= 0 && s[i] == ' ')   i--;	//  skip empty space
        
        int ans = 0;        
        
        while (i >= 0 && s[i] != ' ') {
            i--;
            ans++;
        }	//  count the length of last word
        
        return ans;
    }	//	O(n) time, O(1) space
};