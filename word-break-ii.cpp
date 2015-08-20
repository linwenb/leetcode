/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int maxSize = 0;	//	find the maximum length of a word in dict
        for (unordered_set<string>::const_iterator it = dict.begin(); it != dict.end(); it++) {
            if ((*it).size() > maxSize)		maxSize = (*it).size();
        }
        
        maxSize++;  //  for for-loop condition, explain later

        unordered_map<string, vector<string>> repeat;

        return wordBreak(s, dict, repeat, maxSize);
    }   //  O(2^n) time, O(n^2) space
    
    vector<string> wordBreak(const string &s, const unordered_set<string> &dict, unordered_map<string, vector<string>> &repeat, const int &maxSize) {
        if (repeat.find(s) != repeat.end())   return repeat[s];
        
        vector<string> ans;
        
        //  s is a word in dict
        if (dict.find(s) != dict.end())     ans.push_back(s);

        string first, second;
        //  maxSize needs +1, but s.size() does not
        //  because we need to make sure neither first nor second is empty string
        int n = (s.size() < maxSize)? s.size() : maxSize;
            
        vector<string> temp;
        for (int i = 1; i < n; i++) {
            first = s.substr(0, i);
    
            //  first not in dict
            if (dict.find(first) == dict.end()) continue;
                
            //  first in dict
            second = s.substr(i);
            temp = wordBreak(second, dict, repeat, maxSize);
                   
            for (int j = 0; j < temp.size(); j++)   ans.push_back(first + ' ' + temp[j]);
        }

        repeat[s] = ans;  //  buffer result
        return ans;
    }
};