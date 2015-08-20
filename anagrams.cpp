/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        /*
        Input: ["act","rye","aye","dog", "god","cud","cat","old","fop","bra"]
        Output: ["act","cat","dog","god"]
        */
        
        unordered_map<string, vector<string>> mp;
        
        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());

            mp[temp].push_back(s);
        }   //  sort string, use it as key
        
        vector<string> ans;        
        unordered_map<string, vector<string>>::iterator p;
        
        for (p = mp.begin(); p != mp.end(); p++) {
            if (p->second.size() > 1) {
                ans.insert(ans.end(), p->second.begin(), p->second.end());
            }	//	more than two words share the same key, anagrams !!
        }
        
        return ans;
    }	//	O(n * len * log len) time, O(n * len) space
};