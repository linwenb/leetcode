/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) {
        string ans;
        if (nRows == 0) return ans;
        if (nRows == 1) return s;

        int n = s.size();
        
        for (int i = 0; i < n; i += 2 * nRows - 2) {
            ans.push_back(s[i]);
        }   //  first line
        
        for (int j = 1; j < nRows - 1; j++) {
            for (int i = j, k = 0; i < n; k ^= 1) {
                ans.push_back(s[i]);
                
                if (k == 0) {
                    i += 2 * (nRows - 1 - j);
                }   //  k even
                else {
                    i += 2 * j;
                }   //  k odd
            }
        }   //  lines in the middle
        
        for (int i = nRows - 1; i < n; i += 2 * nRows - 2) {
            ans.push_back(s[i]);
        }   //   last line
        
        return ans;
    }   //  O(n) time, O(1) space
};