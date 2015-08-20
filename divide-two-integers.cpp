/*
Divide two integers without using multiplication, division and mod operator.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        //  dividend / divisor
        bool flag = ((dividend > 0) ^ (divisor > 0)) ? true : false;	//	sign of result
        
        unsigned int uDividend = abs(dividend);	//	unsigned dividend
        unsigned int uDivisor = abs(divisor);	//	unsigned divisor
        
        if (uDivisor == 1)	return flag ? -uDividend : uDividend;        
        if (uDividend == uDivisor)	return flag ? -1 : 1;
        
        int ans = 0;        
        unsigned int tempUDivisor;  //  temp unsigned divisor for fast computing
        int mark;               	//  temp result from tempUDivisor
        
        while (uDividend >= uDivisor) {
            tempUDivisor = uDivisor;
            mark = 1;

            while (uDividend >= tempUDivisor) {
                uDividend -= tempUDivisor;
                ans += mark;
                
                tempUDivisor <<= 1;     //  temp divisor * 2 for fast computing
                mark <<= 1;         //  mark also * 2
            }
        }
        
        return flag ? -ans : ans;
    }	//	O(?) time, O(1) space
};