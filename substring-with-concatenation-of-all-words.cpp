/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int n = S.size();
        int m = L.size();
        
        string curr;	//	temp
        
        unordered_map<string, int> mpL;     //  for fast query
        unordered_map<string, int> mpCnt;	//	for fast count words covered so far
        unordered_map<string, int>::iterator p;
        
        for (int i = 0; i < m; i++) {
            curr = L[i];
            p = mpL.find(curr);

            if (p == mpL.end()) {
                mpL[curr] = 1;
            }   //  word not yet in mpL
            else {
                p->second++;
            }   //  word already in mpL
        }   //  store all word in L into mpL
        
        vector<int> ans;
        int start;          //  start index of concatenation
        int strCovered;     //  count the number of words in L covered
        string stWord;
        
        int len = L.front().size();   //  length of word in L
        unordered_map<string, int>::iterator pCnt;
        
        for (int i = 0; i < len; i++) {
            start = i;
            strCovered = 0;
            
            for (int j = i; j < n; j += len) {
                curr = S.substr(j, len);
                p = mpL.find(curr);

                if (p == mpL.end()) {
                    mpCnt.clear();
                    strCovered = 0;
                    start = j + len;
                }   //  word not in L, reset everything
                else {
                    pCnt = mpCnt.find(curr);

                    if (pCnt == mpCnt.end()) {
                        mpCnt[curr] = 1;
                        strCovered++;
                    }   //  word not in mpCnt
                    else if (pCnt->second < p->second) {
                        pCnt->second++;
                        strCovered++;
                    }   //  word in mpCnt and not yet occurs exceed its occurance in L
                    else {
                        stWord = S.substr(start, len);

                        while (stWord != curr) {
                            mpCnt[stWord]--;
                            strCovered--;
                            start += len;
                            stWord = S.substr(start, len);
                        }   //  remove the words until the word as curr word
                        
                        start += len;
                    }   //  curr word occurs exceed its occurance in L
                }   //  word in L
                
                if (strCovered == m) {
                    ans.push_back(start);
                    
                    //  remove the first word
                    stWord = S.substr(start, len);
                    mpCnt[stWord]--;
                    strCovered--;
                    start += len;
                }   //  found, concatenation of each word in L exactly once
            }   //  traverse words by words
            
            mpCnt.clear();
        }   //  go through all posible words, increse index by 1 each time
        
        return ans;
    }	//	O(n * len) time, O(m * len) space
};