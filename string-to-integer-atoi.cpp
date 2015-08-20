/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class Solution {
public:
    int atoi(const char *str) {
        char *p = const_cast<char*>(str);   //  p could move forward
        
        while (*p == ' ') p++;  //  discards beginning whitespaces

        bool sign = true;   //  default positive if no sign symbol
        
        //  check the first non-whitespace char
        if (*p == '-') {
            sign = false;
            p++;
        }   //  minus sign
        else if (*p == '+') {
            p++;
        }   //  plus sign
        else if (isdigit(*p) == false) {    //  not digit
            return 0;
        }   //  empty or additional chars
        
        int ans = 0;

        for (int i = 0; isdigit(p[i]); i++) {
            if (i < 9 || (i == 9 && ans < 214748364)) {
                ans = ans * 10 + (p[i] - '0');
            }   //  not out of range
            else if (i > 9 || ans > 214748364) {
                return sign ? INT_MAX : INT_MIN;
            }   //  > 9 digits || 9 digits but > 214748364X, out of range
            else {
                if (sign == true && p[i] >= '7') {
                    return INT_MAX;
                }   //  >= 2147483647
                else if (sign == false && p[i] >= '8') {
                    return INT_MIN;
                }   //  <= -2147483648
                else {
                    ans = ans * 10 + (p[i] - '0');
                }
            }   //  == 214748364X, may be out of range 
        }
        
        return sign ? ans : -ans;
    }   //  O(n) time, O(1) space
};