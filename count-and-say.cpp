/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
    	//	no more than four 4s, one single char cnt is enough
        string ans = "1";
        string temp;
        
        char prev, cnt;
        
        while (--n) {
            prev = ans[0];
            cnt = '1';

            for (int i = 1; i < ans.size(); i++) {
                if (ans[i] == prev) {
                    cnt++;
                }	//	cnt increases by 1
                else {
                    temp = temp + cnt + prev;	//	append result

                    cnt = '1';		//	reset cnt and prev
                    prev = ans[i];
                }	//	ans[i] != prev
            }
            
            ans = temp + cnt + prev;	//	append the last part
            temp.clear();
        }
        
        return ans;
    }	//	O(nx) time, O(x) space
};