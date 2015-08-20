/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

class Solution {
public:
    bool isNumber(const char *s) {
        /*
            *char to double.
        1. A (possibly empty) sequence of whitespace chars (discarded).
        2. An optional plus or minus sign (‘+’ or ‘-’).
        3. A floating point number in decimal:
            ***A nonempty sequence of digits optionally containing a decimal-point character—normally ‘.’.
            ***An optional exponent part, consisting of a character ‘e’ or ‘E’, an optional sign, and a sequence of digits.
        */
                
        while (*s == ' ') s++;  //  discard starting whitespaces
                
        if (*s == '\0') return false;   //  empty string
                
        if (*s == '+' || *s == '-') s++;    //  optional sign
        
        //  nonempty sequence of digits with optional dot
        bool numBeforeDot = (*s >= '0' && *s <= '9') ? true : false;
        while (*s >= '0' && *s <= '9') s++;
        
        if (*s == '.') {
            s++;
            
            //  no digits neither before nor after dot
            if (numBeforeDot == false && (*s < '0' || *s > '9')) return false;
            
            while (*s >= '0' && *s <= '9') s++;
        }
        else if (numBeforeDot == false) {
            return false;
        }   //  empty sequence of digits
        
        //  optional exponent part
        if (*s == 'e' || *s == 'E') {
            s++;
                        
            if (*s == '+' || *s == '-') s++;    //  optional sign
                        
            if (*s < '0' || *s > '9')   return false;   //  no digits after e/E
                        
            while (*s >= '0' && *s <= '9') s++; //  a sequence of digits
        }
                
        while (*s == ' ') s++;  //  discard ending whitespaces
                
        return (*s == '\0') ? true : false; //  fail matching if other chars exist
    }   //  O(n) time, O(1) space
};