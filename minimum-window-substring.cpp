/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size();
        int m = T.size();

        if (n < m)  return "";  //  impossible to cover all chars in T

        //  fast check char in T or not, use map instead of set because of duplicate numbers
        unordered_map<char, int> mpT;
        unordered_map<char, int> mpCnt;     //  how many times char covered inside window
        unordered_map<char, int>::iterator p;
        
        char temp;
        
        for (int i = 0; i < m; i++) {
            temp = T[i];
            p = mpT.find(temp);

            if (p == mpT.end()) {
                mpT[temp] = 1;
                mpCnt[temp] = 0;
            }   //  char not yet in mpT
            else {
                p->second++;
            }   //  duplicate char in mpT
        }   //  load all chars in T into mpT, O(m) time
        
        int ansSt = 0;      //  start index of optimal window
        int ansLen = n + 1; //  length of optimal window
        
        int st = 0;         //  start index of window
        int end = 0;        //  end index of window
        int len = 0;        //  temp, length of window
        int nCovered = 0;   //  number of chars in T that covered
        
        unordered_map<char, int>::iterator cnt;
        
        while (end < n) {            
            while (end < n && nCovered < m) {
                temp = S[end];
                p = mpT.find(temp);

                if (p != mpT.end()) {
                    cnt = mpCnt.find(temp);
                    cnt->second++;
                                        
                    if (cnt->second <= p->second)    nCovered++;    //  curr char not yet covered
                }   //  char in T
                
                end++;
            }   //  now, not yet cover all chars in T, move end
            
            if (nCovered < m)  break;  //  cannot covers all chars in T
                        
            while (st < end && nCovered == m) {
                temp = S[st];
                p = mpT.find(temp);

                if (p != mpT.end()) {
                    len = end - st;

                    if (len < ansLen) {
                        ansSt = st;
                        ansLen = len;
                    }   //  better solution
                    
                    cnt = mpCnt.find(temp);
                    cnt->second--;
                                        
                    if (cnt->second < p->second)    nCovered--; //  curr char will not be covered
                }   //  char in T
                
                st++;
            }   //  now move start, until not all chars in T covered
        }
                
        if (ansLen == n + 1)    return "";  //  cannot covers all chars in T
        
        return S.substr(ansSt, ansLen);
    }   //  O(n) time, O(m) space
};