/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        //  foreach element, 2Sum subproblem        
        vector<vector<int>> ans;

        int n = num.size();
        if (n < 3) return ans;
        
        stable_sort(num.begin(), num.end());
        
        vector<int> ins(3);
        int st, end;
        int val;    //  temp
        
        for (int i = 0; i < n - 2; i++) {
            //  skip same elements
            if (i > 0 && num[i] == num[i - 1])    continue;
            
            st = i + 1;
            end = n - 1;

            while (st < end) {                
                if (st > i + 1 && num[st] == num[st - 1]) {
                    st++;
                    continue;
                }   //  skip same elements
                
                if (end < n-1 && num[end] == num[end + 1]) {
                    end--;
                    continue;
                }   //  skip same elements
                
                val = num[i] + num[st] + num[end];
                
                if (val == 0) {
                    ins[0] = num[i];
                    ins[1] = num[st];
                    ins[2] = num[end];
                    
                    ans.push_back(ins);
                    
                    st++;
                    end--;
                }   //  found!
                else if (val < 0) {
                    st++;
                }
                else {
                    end--;
                }   //  val > 0
            }
        }
        
        return ans;
    }   //  O(n^2) time, O(1) space
};