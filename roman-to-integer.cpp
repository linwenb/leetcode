/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = s.size();
        int ans = 0;
        int prev = 0;
        int curr;
        
        for (int i = n - 1; i >= 0; i--) {
            curr = mp[s[i]];

            if (curr >= prev)
                ans += curr;
            else    //  curr < prev
                ans -= curr;    //  IV, 500 - 100

            prev = curr;
        }   //  read from the highest digit

        return ans;
    }   //  O(n) time, O(1) space
};