/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        unordered_map<int, int> mp;     //  for DP
        
        return minDistance(word1, 0, word2, 0, mp);
    }
    
    int minDistance(const string word1, const int a,
            const string word2, const int b, unordered_map<int, int> &mp) {
        //  reach boundary
        if (a == word1.size())  return word2.size() - b;
        if (b == word2.size())  return word1.size() - a;
        
        int id = a * word2.size() + b;
        
        if (mp.find(id) != mp.end())    return mp[id];
        
        if (word1[a] == word2[b]) {
            int k = minDistance(word1, a + 1, word2, b + 1, mp);
            mp[id] = k;
            return k;
        }
        
        //  word1[a] != word2[b]
        vector<int> ans(3);
        ans[0] = minDistance(word1, a + 1, word2, b, mp);
        ans[1] = minDistance(word1, a, word2, b + 1, mp);
        ans[2] = minDistance(word1, a + 1, word2, b + 1, mp);
        
        sort(ans.begin(), ans.end());
        mp[id] = ans.front() + 1;
        return ans.front() + 1;
    }
};  //  recursive

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        if (n == 0) return m;
        if (m == 0) return n;
        
        vector<vector<int>> ans(n + 1, vector<int>(m + 1, 0));  //  DP
        
        //  initialization, ans[0][0] = 0;
        for (int i = 1; i <= n; ++i)  ans[i][0] = i;
        for (int i = 1; i <= m; ++i)  ans[0][i] = i;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    ans[i][j] = ans[i - 1][j - 1];
                }   //  no step is needed
                else {
                    ans[i][j] = min(ans[i - 1][j], ans[i][j - 1]);  //  a) or b)
                    ans[i][j] = min(ans[i][j], ans[i - 1][j - 1]) + 1;  //  or c)
                }   //  word1[i] != word2[j], take one more step
            }
        }
        
        return ans[n][m];
    }   //  O(n * m) time, O(n * m) space
};  //  iterative