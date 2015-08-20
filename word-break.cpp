/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty() == true)  return false;

        int maxSize = 0;	//	find the maximum length of a word in dict, help to reduce time
        for (unordered_set<string>::const_iterator it = dict.begin(); it != dict.end(); it++) {
            if ((*it).size() > maxSize)		maxSize = (*it).size();
        }
        
        maxSize++;  //  for for-loop condition, explain later

        unordered_set<string> failures;     //  for DP

        return wordBreak(s, dict, failures, maxSize);
    }   //  O(?) time, O(n) space
    
    bool wordBreak(const string &s, unordered_set<string> &dict, unordered_set<string> &failures, int &maxSize) {
        if (dict.find(s) != dict.end())   return true;			//  s is a word in dict
        if (failures.find(s) != failures.end())   return false;	//	already visited s
        
        string first, second;   //  break s into two parts
		//  maxSize needs +1, but s.size() does not
        //  because we need to make sure neither first nor second is empty string
        int n = (s.size() < maxSize) ? s.size() : maxSize;
        
        for (int i = 1; i < n; i++) {
            first = s.substr(0, i);

            if ( dict.find(first) != dict.end() ) {
                second = s.substr(i);
                if (wordBreak(second, dict, failures, maxSize) == true)    return true;
            }	//	check only if first in dict
        }   //  check every possible segment
        
        failures.insert(s);     //  s cannot be segmented
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        
        if (n == 0)  return false;
        
        vector<vector<bool> > mp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                    mp[i][j] = true;
                }
            }
        }   //  mp[i][j] is true if s[i : j] in dict
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                for (int k = i; k < j; k++) {
                    if (mp[i][j] == false) {
                        mp[i][j] = mp[i][k] && mp[k + 1][j];
                    }
                }
            }
        }   //  mp[i][j] is true if s[i : j] can be segmented
        
        return mp[0][n - 1];
    }   //  O(n^3) time, O(n^2) space
};