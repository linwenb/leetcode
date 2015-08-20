/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;	//  different size
        
        unordered_map<int, bool> mp;	//	DP
        return isScramble(s1, 0, s2, 0, s1.size(), mp);
    }
    
    bool isScramble(const string &s1, const int b1, const string &s2, const int b2, const int n, unordered_map<int, bool> &mp) {
        int id = (b1 * s2.size() + b2) * s1.size() + n;
        
        if (mp.find(id) != mp.end())    return mp[id];
        
        string t1 = s1.substr(b1, n);
        string t2 = s2.substr(b2, n);
                
        if (t1 == t2) {
            mp[id] = true;
            return true;
        }	//  same string
        
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) {
            mp[id] = false;
            return false;
        }	//  they have different chars
        
        for (int i = 1; i < n; i++) {
            if (isScramble(s1, b1, s2, b2, i, mp) && isScramble(s1, b1 + i, s2, b2 + i, n - i, mp)) {
                mp[id] = true;
                return true;
            }   //  did not swap children of root  
            
            if (isScramble(s1, b1, s2, b2 + n - i, i, mp) && isScramble(s1, b1 + i, s2, b2, n - i, mp)) {
                mp[id] = true;
                return true;
            }   //  swap children of root
        }	//	divide into two parts, neither empty
        
        mp[id] = false;	//	not scrambled string
        return false;
    }
};