/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        unordered_map<int, int> mp;	//	DP
        
        return numDecodings(s, n, 0, mp);
    }	//	O(n) time, O(n) space
    
    int numDecodings(const string &s, const int &n, const int pos, unordered_map<int, int> &mp) {
        if (pos > n - 1) return 1;
        
        if (mp.find(pos) == mp.end()) {
            if (pos == n - 1) {
                mp[pos] = (s[pos] == '0') ? 0 : 1;
            }
            //  general cases
            else if (s[pos] == '0') {
                mp[pos] = 0;
            }   //  invalid decoding
            else if (s[pos] == '1') {
                mp[pos] = numDecodings(s, n, pos + 1, mp) + numDecodings(s, n, pos + 2, mp);
            }   //  two posible ways decoding
            else if (s[pos] == '2') {
                if (s[pos + 1] >= '1' && s[pos + 1] <= '6') {
                    mp[pos] = numDecodings(s, n, pos + 1, mp) + numDecodings(s, n, pos + 2, mp);
                }   //  two posible ways decoding
                else {
                    mp[pos] = numDecodings(s, n, pos + 2, mp);
                }   //  s[pos + 1] == '0' || s[pos + 1] > '6'
            }
            else {
                mp[pos] = numDecodings(s, n, pos + 1, mp);
            }   //  s[pos] > '2'
        }
        
        return mp[pos];
    }
};	//	recursive

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        vector<int> ans(n + 1); //  DP
        ans[0] = 1;
        
        if (s[0] != '0')  ans[1] = 1;
        
        for (int i = 1; i < s.size(); i++){
            if (s[i] != '0')  ans[i + 1] += ans[i]; //  s[i] is a letter
            
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                ans[i + 1] += ans[i - 1];
            }   //  s[i-1 : i] is a letter
        }
         
        return ans.back();  //  ans[n]
    }   //  O(n) time, O(n) space
};	//	iterative