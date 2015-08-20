/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
                
        string digit;
		for (int i = 0; i < n; i++) {
			if (digits[i] != '0' && digits[i] != '1')	digit += digits[i];
		}	//	ignore '0' and '1'

		n = digit.size();
        if (n == 0) {
            ans.push_back(string());
            return ans;
        }
        
        char mp[][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int mpCnt[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
        
        int k;
        vector<int> cnt(n + 1, 0);	//	help to go through all posibilities

        string ins;		//	one instance of mapping letters
        ins.resize(n);
        
        while (cnt[n] == 0) {
            for (int i = 0; i < n; i++) {
                ins = mp[digit[i] - '0'][cnt[i]];
            }	//	digit[i] maps to cnt[i]-th letter
            
            ans.push_back(ins);
            
            k = 0;
            cnt[k]++;	//	next instance
            while (k < n && cnt[k] == mpCnt[digit[k] - '0']) {
                cnt[k] = 0;
                cnt[k + 1]++;	//	change next digit's mapping
                k++;
            }	//	reach the limit
        }
        
        return ans;
    }	//	O(3^n) time, O(n) space
};