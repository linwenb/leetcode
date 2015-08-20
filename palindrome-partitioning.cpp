/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",

Return
  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;     //  answer
        if (s.size() == 0)  return ans;
        
        vector<string> ins;             //  instance
        unordered_map<int, bool> mp;    //  for DP
        
        helper(s, 0, mp, ins, ans);
        
        return ans;
    }   //  O(n^2) time, O(n) space
    
    void helper(string &s, int start, unordered_map<int, bool> &mp, vector<string> &ins, vector<vector<string>> &ans) {
        int n = s.size();

        if (start == n) {
            ans.push_back(ins);
            return;
        }   //  reach end, found
        
        for (int i = start; i < n; i++) {
            if (check(s, start, i, mp) != false) {
                ins.push_back(s.substr(start, i - start + 1));
                helper(s, i + 1, mp, ins, ans);
                ins.pop_back();
            }   //  s[start : i] is Palindrome
        }
    }   //  O(n^2) time, O(1) space
    
    bool check(string &s, int start, int end, unordered_map<int, bool> &mp) {
        if (start == end)   return true;    //  only single char
        
        int id = start * s.size() + end;
        if (mp.find(id) != mp.end())    return mp[id];
        
        while (start < end) {
            if (s[start] != s[end]) {
                mp[id] = false;
                return false;
            }   //  not Palindrome
            
            start++;
            end--;
        }
        
        mp[id] = true;  //  it is Palindrome
        return true;
    }   //  check if s[start : end] is Palindrome, O(n) time, O(1) space
};