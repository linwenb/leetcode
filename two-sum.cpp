/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        multimap<int, int> mp;	//	may have duplicate numbers
        for (int i = 0; i<numbers.size(); i++) {
            mp.insert(pair<int, int>(numbers[i], i + 1));
        }
        
        multimap<int, int>::iterator i = mp.begin();
        multimap<int, int>::reverse_iterator j = mp.rbegin();
        
        int sum;
        while (true) {
            sum = i->first + j->first;
            
            if (sum == target) {
                break;
            }
            else if (sum > target) {
                j++;
            }
            else {
                i++;
            }   // sum < target
        }
        
        vector<int> ans;
        ans.push_back(i->second);
        ans.push_back(j->second);
        
        sort(ans.begin(), ans.end());   //  index1 must be less than index2
        return ans; 
    }   //  O(n log n) time, O(n) space
};


//	O(n) time, O(n) space