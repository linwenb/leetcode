/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

	Only one letter can be changed at a time
	Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
	Return 0 if there is no such transformation sequence.
	All words have the same length.
	All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        string curr, temp;
        int n;  //  number of words at this step
        int len = start.size();   //  length of a word

        int ans = 1;  //  answer, steps
        
        queue<string> Queue;    //  for BFS
        unordered_set<string> visited;
        
        Queue.push(start);      //  start BFS
        visited.insert(start);
        
        while (Queue.empty() == false) {
            n = Queue.size();
            ans++;  //  step number increases one
            
            while (n-- > 0) {
                curr = Queue.front();
                Queue.pop();
                
                for (int i = 0; i < len; i++) {
                    temp = curr;
                    
                    for (int j = 0; j < 26; j++) {
                        temp[i] = 'a' + j;
                        
                        if (temp == end)    return ans; // found !!
                        
                        if (dict.find(temp) != dict.end() && visited.find(temp) == visited.end()) {
                            Queue.push(temp);
                            visited.insert(temp);
                        }   // in dict and not visited yet
                    }   // foreach letter
                }   // foreach position
            }
        }
        
        return 0;   // not found
    }   //  O(n * len) time, O(n) space
};