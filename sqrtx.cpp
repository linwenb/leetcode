/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int sqrt(int x) {
        if (x <= 1)  return x;
        
        //  Binary search
        int left = 0;
        int right = x;
        int mid;
                
        while (left < right - 1) {
            mid = left + (right - left) * 0.5;
                        
            if (mid == x / mid) {   //  mid * mid might overflow
                return mid;
            }   //  found !!
            else if (mid < x / mid) {
                left = mid;
            }
            else {
                right = mid;
            }   //  mid > x / mid
        }   //  until left == right + 1 to avoid infinite loop
        
        return left;
    }   //  O(log x) time, O(1) space
};