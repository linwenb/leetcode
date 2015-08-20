/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int n = s.size();
    	int start = 1;  //  start position, from 1, which is larger than default 0
        int ans = 0;
        int cnt = 0;
        
        vector<int> lastPos(256, 0);    //  not use 0 index, all default position 0
        
        char c;	//	temp
        
        for (int i = 0; i < n; ++i) {
            c = s[i];
            //  duplicate char occurs as the start char     a.....a
            //  or the char after the start one             i.a...a
            if (lastPos[c] >= start) {
                cnt -= lastPos[c] - start + 1;
                start = lastPos[c] + 1; //  start from the next char of last duplicate
            }
            
            lastPos[c] = i + 1; //  update its last occur position
            cnt++;  //  count curr char

            if (cnt > ans)  ans = cnt;
        }
        
        return ans;
    }	//	O(n) time, O(1) space
};