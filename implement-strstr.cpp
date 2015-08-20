/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (*needle == '\0')   return haystack;
        
        int hayLen = strlen(haystack);
        int neeLen = strlen(needle);
        
        for (int i = 0; i < hayLen - neeLen + 1; i++) {	//	unnecessary checking to reduce time
            for (int k = 0; *(haystack + i + k) == *(needle + k); k++) {
                if (k == neeLen - 1)	return haystack + i;	//	found !!
            }	//	then go through needle
        }	//	go through haystack
        
        return NULL;	//	needle not part of haystack
    }	//	O(n * m) time, O(1) space
};