/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        
        if (n1 + n2 != n3)  return false;
        
        if (n1 == 0)    return s2 == s3;
        if (n2 == 0)    return s1 == s3;
        
        unordered_set<int> st;  //  DP, avoid repeating checking
        
        return isInterleave(s1, 0, s2, 0, s3, 0, st);
    }
    
    bool isInterleave(const string &s1, const int i1, const string &s2, const int i2,
                const string &s3, const int i3, unordered_set<int> &st) {
        if (i1 == s1.size() && i2 == s2.size()) return true;	//	both reach end
        
        if (i1 == s1.size())    return s2.substr(i2) == s3.substr(i3);
        if (i2 == s2.size())    return s1.substr(i1) == s3.substr(i3);
        
        int id = i1 * s2.size() + i2;
        
        if (st.find(id) != st.end())    return false;	//	already check, failed
        
        st.insert(id);	//	visiting
        
        char c1 = s1.at(i1);
        char c2 = s2.at(i2);
        char c3 = s3.at(i3);
        
        if (c1 != c3 && c2 != c3) {
            return false;
        }
        else if (c2 != c3) {
            return isInterleave(s1, i1 + 1, s2, i2, s3, i3 + 1, st);	//	curr char of s3 from s1
        }   //  c1 == c3
        else if (c1 != c3) {
            return isInterleave(s1, i1, s2, i2 + 1, s3, i3 + 1, st);	//	curr char of s3 from s2
        }   //  c2 == c3
        else {
            if (isInterleave(s1, i1 + 1, s2, i2, s3, i3 + 1, st) == true)   return true;	//	curr char of s3 from s1
            
            return isInterleave(s1, i1, s2, i2 + 1, s3, i3 + 1, st);	//	curr char of s3 from s2
        }   //  c1 == c3 && c2 == c3
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        
        if (n1 + n2 != n3)  return false;   //  sizes not match
        if (n1 == 0 && n2 == 0 && n3 == 0)  return true;    //  all empty
        if (n1 == 0)    return s2 == s3;
        if (n2 == 0)    return s1 == s3;
        
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));  //  DP
        dp[0][0] = true;
        
        for (int i = 0; i < n1; ++i) {
            if (s1[i] == s3[i] && dp[i][0]) dp[i + 1][0] = true;
        }   //  s1[0 : i] == s3[0 : i]
        
        for (int i = 0; i < n2; ++i) {
            if (s2[i] == s3[i] && dp[0][i]) dp[0][i + 1] = true;
        }   //  s2[0 : i] == s3[0 : i]
        
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                //  curr char of s3 from s1
                if (s1[i] == s3[i + j + 1] && dp[i][j + 1]) dp[i + 1][j + 1] = true;
                
                //  curr char of s3 from s2
                if (s2[j] == s3[i + j + 1] && dp[i + 1][j]) dp[i + 1][j + 1] = true;
            }
        }
        
        return dp.back().back();  //    dp[n1-1][n2-1]
    }   //  O(n^2) time, O(n^2) space
};