/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {        
        if (*s == '\0' && *p == '\0')   return true;	//  both empty, match!
        
        if (*s == *p) {
            return isMatch(s + 1, p + 1);
        }   //  letters match
        else if (*p == '?' && *s != '\0') {
            return isMatch(s + 1, p + 1);
        }   //  '?' matches any single char
        else if (*p == '*') {
            while (*p == '*') {
                p++;
            }   //  ignore continous '*', move to the first char not '*' in p
                        
            if (*p == '\0')   return true;	//  '*' matches all remaining chars in s
            
            while (*s != '\0') {
                const char *ts = s;
                const char *tp = p;
                
                while (*ts != '\0' && (*ts == *tp || *tp == '?')) {
                    ts++;
                    tp++;
                }
                
                if (*ts == '\0' && *tp == '\0')   return true;  //  reach the end
                
                //  KEY to reduce time. no need to match more chars since the new '*' will handle it
                if (*tp == '*') return isMatch(ts, tp) ? true : false;
                
                if (*ts == '\0')   return false;    //  p has more chars than s
                
                s++;    //  *ts != *tp 
            }   //  '*' matches any sequence of chars in s before all remaining
        }   //  *p == '*'
        
        return false;   //  fail: *s != *p, s is empty, p has more chars than s
    }	//	O(n + m) time, O(n + m) space
};