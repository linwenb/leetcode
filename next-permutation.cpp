/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        /*
        1. find a rightmost pair, a1 and a2, to exchange. s.t. a1 < a2 and num[a1] < num[a2], a1 as large as possible
        2. exchange num[a1] and num[a2]. Sort all the items after a1, making the number as small as possible
        */
        
        if (num.size() == 0)    return;
        
        int a1 = 0;
        int a2 = num.size() - 1;
        
        for (int i = 1; i < num.size(); i++) {
            if (num[a1] < num[i] && num[i] < num[a2]) {
                a2 = i;
            }   //  smaller num[a2]
            
            if (num[i - 1] < num[i]) {
                a1 = i - 1;
                a2 = i;
            }   //  larger a1
        }
        
        //  exchange num[a1] and num[a2]
        int temp = num[a1];
        num[a1] = num[a2];
        num[a2] = temp;
        
        //	sort items after a1
        sort(num.begin() + a1 + 1, num.end());
    }	//	O(n log n) time, O(1) space
};