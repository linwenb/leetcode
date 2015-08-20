/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int n = num.size()
        if (n == 0)    return 0;
        
        //  number points to head of the consecutive sequence ending at number
        //  if number is head, it points back to tail of the consecutive sequence
        unordered_map<int, int> mp;
        int val, tail, temp;
        
        for (int i = 0; i < n; i++) {
            val = num[i];
            
            if (mp.find(val) != mp.end()) continue; //  same number, already checked
            
            mp[val] = val;  //  point to itself, size is 1
            
            if (mp.find(val - 1) != mp.end()) {
                temp = mp[val - 1]; //  head
                mp[val] = temp;  //  val points to head
                mp[temp] = val;  //  head points to val
            }   //  num[i] - 1 exists
            
            if (mp.find(val + 1) != mp.end()) {
                tail = mp[val + 1]; //  tail
                temp = mp[val];     //  head
                mp[tail] = temp;    //  tail points to head
                mp[temp] = tail;    //  head points to tail
            }   //  num[i] + 1 exists
        }
        
        int longest = 0;    //  answer, length of logest consecutive elements sequence
        unordered_map<int, int>::const_iterator p;
        
        for (p = mp.begin(); p != mp.end(); p++) {
            val = p->second - p->first;     //  length of consecutive sequence
            if (val > longest) longest = val;
        }
        
        return longest + 1;
    }   //  O(n) time, O(n) space
};