/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

	Only one letter can be changed at a time
	Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:
	All words have the same length.
	All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        string curr, temp;

        bool found = false;     //  indicate we found the answer or not
        int len = start.size(); //  length of a word
        int nOneLevel;          //  number of words at one level        
        unordered_set<string> currrLevel;    //  help to find multipath at one level
        
        queue<string> Queue;    //  for BFS        
        unordered_map<string, vector<string>> path; //  buffer results and help to check word visited or not

        Queue.push(start);      //  start BFS
        path[start] = vector<string>();

        while (Queue.empty() == false && found == false) {
            nOneLevel = Queue.size();

            while (nOneLevel-- > 0) {
                curr = Queue.front();
                Queue.pop();
                
                for (int i = 0; i < len; i++) {
                    temp = curr;
                    
                    for (int j = 0; j < 26; j++) {
                        temp[i] = 'a' + j;
                        
                        if (temp == end) {
                            if (found == false) {
                                path[temp] = vector<string>(1, curr);
                                found = true;
                            }   //  first time found the answer
                            else {
                                path[temp].push_back(curr);
                            }   //  other paths
                        }   // found !!
                        
                        if (found == false && dict.find(temp) != dict.end()) {
                            if (path.find(temp) == path.end()) {
                                Queue.push(temp);
                                path[temp] = vector<string>(1, curr);                                
                                currrLevel.insert(temp);
                            }   //  not visited yet
                            else if (currrLevel.find(temp) != currrLevel.end()) {
                                path[temp].push_back(curr);
                            }   //  already visited at the same level, it is an alternated path
                        }   // answer not found and temp in dict
                    }   // foreach letter
                }   // foreach position
            }   //  at one level
            
            currrLevel.clear();     //  remember to clear !!!
        }   //  not yet visit all possible words and not yet found the answer
        
        vector<vector<string>> ans;     //  answer
        
        if (path.find(end) != path.end()) {
            list<string> lst;
            lst.push_back(end);
            
            generateAns(path, lst, ans);
        }      //   if found, store paths into ans
        
        return ans;
    }
    
    void generateAns(unordered_map<string, vector<string>> &path, list<string> &lst, vector<vector<string>> &ans) {
        unordered_map<string, vector<string>>::iterator p = path.find(lst.front());
        
        if (p->second.empty() == true){
            vector<string> v(lst.begin(), lst.end());
            ans.push_back(v);
            return;
        }   //  reach start string
        
        int n = p->second.size();
        for (int i = 0; i < n; i++) {
            lst.push_front(p->second[i]);
            generateAns(path, lst, ans);
            lst.pop_front();
        }   //  foreach path
    }
};