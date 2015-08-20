/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        //  4Sum, make pairs, be 2Sum problem, so hard for me
        int n = num.size();
        if (n < 4) return vector<vector<int>>(); //  invalid input
        
        multimap<int, pair<int,int>> mp;   //  <sum of two numbers, two indexes>
        set<vector<int> > ans;   //  remove duplicates
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                mp.insert(make_pair(num[i] + num[j], make_pair(i, j)));
            }
        }
        
        vector<int> instance(4);
        multimap<int, pair<int,int>>::iterator iter, p;
        pair<multimap<int, pair<int,int>>::iterator, multimap<int, pair<int,int>>::iterator> ret;   //  for range search
        set<int> index;
        int val;
        
        for (iter = mp.begin(); iter != mp.end(); iter++) {
            val = target - iter->first;
            if (mp.find(val) == mp.end())   continue;   //  sum == target not found
            
            ret = mp.equal_range(val);  //  range search, several results may exist
            
            for (p = ret.first; p != ret.second; p++) {
                index.clear();
                
                index.insert(iter->second.first);
                index.insert(iter->second.second);
                index.insert(p->second.first);
                index.insert(p->second.second);
                
                if (index.size() < 4)  continue;    //  all 4 indexes should different
                
                instance[0] = num[iter->second.first];     // pair.first
                instance[1] = num[iter->second.second];
                instance[2] = num[p->second.first];
                instance[3] = num[p->second.second];
                
                sort(instance.begin(), instance.end());     //  non-descending order
                
                ans.insert(instance);
            }
        }
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }   //  O(n^2) time, O(n^2) space
};