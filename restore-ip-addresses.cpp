/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        list<string> ins;
        vector<string> ans;
        
        restoreIpAddresses(s, ins, ans);
        
        return ans;
    }
    
    void restoreIpAddresses(const string s, list<string> &ins, vector<string> &ans) {
        string temp;
        if (s.empty() == true && ins.size() == 4) {
            temp = ins.front();
            
            for (list<string>::const_iterator p = ins.begin() + 1; p != ins.end(); p++) {
                temp.append(".");
                temp.append(*p);
            }	//	start from the second one

            ans.push_back(temp);
        }	//	found one valid combination
        
        if (s.empty() == true || ins.size() == 4)   return;		//	already found or failed
        
        int t;	//	how many digits at most in next section
        if (s.front() == '0') {
            t = 1;
        }	//	just one because 0X is invalid
        else if (s.size() < 3) {
            t = s.size();
        }	//	less than 3 digits left
        else {
            t = 3;
        }	//	at most 3 digits
        
        for (int i = 1; i <= t; i++) {
            temp = s.substr(0, i);
            
            if (i == 3 && temp > "255") continue;	//	invalid
            
            ins.push_back(temp);
            restoreIpAddresses(s.substr(i), ins, ans);
            ins.pop_back();
        }	//	i digits in next section
    }
};