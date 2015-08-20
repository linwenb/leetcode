/*
Given an input string, reverse the string word by word.

For example,
    Given s = "the sky is blue",
    return "blue is sky the".

Clarification:
	What constitutes a word?
	   A sequence of non-space characters constitutes a word.
	Could the input string contain leading or trailing spaces?
	   Yes. However, your reversed string should not contain leading or trailing spaces.
	How about multiple spaces between two words?
	   Reduce them to a single space in the reversed string.
*/

class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        if (n == 0)  return;    //  empty string
        
        //	discard leading spaces
        //  trailing spaces are treated as spaces between words below
        int st = 0;
        while (st < n && s[st] == ' ')	st++;
        
        int i = st;
        int j = n - 1;
        char temp;
        
        while (i < j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }   //  reverse the whole string
        
        string ans;
        
        j = st;
        while (j < n) {
            //  discard multiple spaces between two words
            i = j;
            while (i < n && s[i] == ' ')	i++;
            
            //  find the next word
            j = i;
            while (j < n && s[j] != ' ')	j++;
            
            //  append reversed word
            for (int p = j - 1; p >= i; p--)    ans += s[p];
            
            //  append a space if necessary
            if (j < n)  ans += ' ';
        }
        
        s = ans;
    }   //  O(n) time, O(n) space
};