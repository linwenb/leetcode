/*
Implement pow(x, n).
*/

class Solution {
public:
    double pow(double x, int n) {
        if (x == 1.0)   return 1.0;
        if (x == -1.0)   return (n & 1) ? -1.0 : 1.0;
        
        if (n < 0)  return pow(1 / x, -n);
        
        if (n == 0) return 1.0;
        if (n == 1) return x;
        
        double k = pow(x, n / 2);	//	reduce time to half
        
        return (n & 1) ? k * k * x : k * k;	//	n is odd or even
    }	//	O(log n) time, O(log n) space
};