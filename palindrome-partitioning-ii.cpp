/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0)  return 0;
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        initialize(s, n, dp);
        
        return minCut(s, n, dp);
    }   //  O(n^2) time, O(n^2) space
    
    int minCut(const string &s, const int &n, const vector<vector<bool>> &dp) {
        vector<int> ans(n, n - 1);  //  worst case, n - 1 cuts
        
        for (int i = 0; i < n; i++) {
            if (dp[0][i] == true) {
                ans[i] = 0;
                continue;
            }   //  s[0 : i] is Palindrome
            
            for (int j = 1; j <= i; j++) {
                if (dp[j][i] == true && ans[j-1] + 1 < ans[i]) {
                    ans[i] = ans[j-1] + 1;
                }   //  s[j : i] is Palindrome
            }
        }
        
        return ans.back();
    }   //  O(n^2) time, O(n) space
    
    void initialize(const string &s, const int &n, vector<vector<bool>> &dp) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                }
            }
        }   //  check if s[i : j] is Palindrome
    }   //  O(n^2) time, O(1) space
};