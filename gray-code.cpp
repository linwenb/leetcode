/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        int curr = 0;
        int maxNum = pow(2.0, n);
        int temp, p;
        
        unordered_set<int> s;
        s.insert(0);
        
        vector<int> ans;
        ans.push_back(0);
        
        while (maxNum-- > 0) {
            p = 1;

            for (int i = 0; i < n; i++, p <<= 1) {
                temp = curr ^ p;		//	change ith bit
                
                if (s.find(temp) == s.end()) {
                    curr = temp;
                    s.insert(curr);
                    ans.push_back(curr);
                    break;
                }	//	new gray code
            }	//	O(n) time
        }	//	O(2^n) time
        
        return ans;
    }	//  O(n * 2^n) time, O(2^n) space
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        
        int maxNum = pow(2.0, n);
        
        for (int i = 0; i < maxNum; ++i) {
            ans.push_back(binaryToGray(i));
        }
        
        return ans;
    }   //  O(2^n) time, O(1) space
    
    int binaryToGray(int num) {
        return (num >> 1) ^ num;
    }   //  O(1) time, O(1) space
};	//	much clever