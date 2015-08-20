/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        /*
        palindrome can be expanded from its center, only 2N-1 centers
        N centers are chars in string, N-1 centers are between two chars
        */
        int n = s.size();
        if (n == 0) return string();
        
        int start = 0;
        int longest = 1;    //  a single char
        int len;
        
        for (int i = 0; i < n - 1; i++) {
            //  center is char in s
            len = longestPalindrome(s, n, i, i);

            if (len > longest) {
                start = i - len / 2;
                longest = len;
            }
            
            //  center is between two chars
            len = longestPalindrome(s, n, i, i + 1);
            if (len > longest) {
                start = i - len / 2 + 1;
                longest = len;
            }
        }
        
        return s.substr(start, longest);
    }   //  O(n^2) time, O(1) space
    
    int longestPalindrome(const string &s, const int n, int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        
        //  should be (right - left + 1) - 2
        return right - left - 1;
    }   //  O(n) time, O(1) space
};

class Solution {
public:
    string longestPalindrome(string s) {
        /*
        Define P[ i, j ] ← true iff the substring Si - Sj palindrome
        P[ i, j ] ← ( P[ i+1, j-1 ] and Si == Sj )
        
        Base cases:
        P[ i, i ] ← true
        P[ i, i+1 ] ← ( Si == Si+1 )
        */
        int n = s.size();
        int start = 0;
        int maxLen = 1;
        bool table[1000][1000] = {false};
        
        //  base case 1
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }
        
        //  base case 2
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && table[i + 1][j - 1]) {
                    table[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }   //  O(n^2) time, O(n^2) space
};