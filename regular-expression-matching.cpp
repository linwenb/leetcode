/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        //  pLen == 0
        if (*p == '\0')  return *s == '\0';

        //  pLen >= 1
        if (*(p + 1) != '*') {
            return (*s == *p || (*s != '\0' && *p == '.')) && isMatch(s + 1, p + 1);
        }   //  pLen == 1 (p[1] == '\0') || (pLen > 1 && p[1] != '*')
        
        //  p[1] == '*'
        //  if match, brute force exhaustive matching of any repeats of *p
        while (*s == *p || (*s != '\0' && *p == '.')) {
            if (isMatch(s, p + 2)) return true;
            s++;
        }
        
        //  not match, skip p[0] and p[1], "x*"
        return isMatch(s, p + 2);
    }   //  O(n + m) time, O(n + m) space
};