/*
Write a function to find the longest common prefix string amongst an array of strings
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {        
        string ans;

        int n = strs.size();
        if (n == 0)   return ans;
        
        int minLen = INT_MAX;   //  min length of words in strs
        for (int i = 0; i < n; i++) {
            if (strs[i].size() < minLen) {
                minLen = strs[i].size();
            }
        }
        
        char c;     //  temp
        for (int i = 0; i < minLen; i++) {
            c = strs[0][i];

            for (int j = 1; j < n; j++) {
                if (strs[j][i] != c)    return ans;
            }

            ans += c;
        }
        
        return ans;
    }   //  O(n * minLen) time, O(1) space
};