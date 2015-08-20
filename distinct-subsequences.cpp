/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

class Solution {
public:
    int numDistinct(string S, string T) {
        unordered_map<int, int> mp;		//	for DP

        return numDistinct(S, 0, T, 0, mp);
    }   //  accepted, but too slow
    
    int numDistinct(string &S, int a, string &T, int b, unordered_map<int, int> &mp) {
        if (b == T.size())  return 1;				//	reach end of T, one subsequence of T in S
        if (S.size() - a < T.size() - b) return 0;	//	remaining chars in S less than those in T, no way to find subsequence
        
        int id = a * T.size() + b;        
        if (mp.find(id) != mp.end())    return mp[id];
        
        int ans = 0;
        
        if (S[a] == T[b])   ans += numDistinct(S, a + 1, T, b + 1, mp);	//	char matches, move one char in T
        
        ans += numDistinct(S, a + 1, T, b, mp);		//	discard S[a], continue searching
        
        mp[id] = ans;        
        return ans;
    }
};

class Solution {
public:
    int numDistinct(string S, string T) {
        /*
        ans[i + 1] means the number of distinct subsequences of T.substr(0...i) in S(0...j)
  
        ans[i + 1] (s[j]) = ans[i + 1] (S[j - 1])   (one option, discard S[j])
                          + ans[i]     (S[j - 1])   (the other option, use S[j] if S[j] == T[i])
                         or 0                       (S[j] != T[i] so not use S[j])
        */
        int n = S.size();
        int m = T.size();
        
        if (n < m)  return 0;
        
        vector<int> ans(m + 1); //  all 0
        ans[0] = 1;             //  initial condition

        for (int j = 0; j < n; j++) {
            //  traverse backwards so we use ans[i] from last time step
            for (int i = m - 1; i >= 0; i--) {  
                ans[i + 1] += (T[i] == S[j] ? ans[i] : 0);
            }
        }
        
        return ans.back();  //  ans[m]
    }   //  O(nm) time, O(m) space
};