/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
        int digit[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        
        unordered_map<int, string> mp;

        mp[1] = "I";
        mp[4] = "IV";    //  buffer this to avoid handle complicated cases
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";
        
        string ans;

        for (int i = 12; i >= 0; i-- ) {
            while (num >= digit[i]) {
                ans += mp[digit[i]];
                num -= digit[i];
            }
        }   //  from the highest digit

        return ans;
    }   //  O(1) time, O(1) space
};