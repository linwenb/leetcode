/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
    In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        list<string> qq;

        size_t index;
        string prefix;
                
        while (path.size() > 1) {
            index = path.find('/', 1);  //  find the index of second '/'
            
            if (index == string::npos) {
                prefix = path;
                path.clear();
            }   //  no second '/' exists
            else {
                prefix = path.substr(0, index);
                path = path.substr(index);
            }   //  prefix + path
            
            
            if (prefix == "/" || prefix == "/.") {
                continue;
            }   //  ignore "//" or "/."
            else if (prefix == "/..") {
                if (qq.empty() == false)   qq.pop_back();
            }   //  go back to parent directory
            else {
                qq.push_back(prefix);
            }   //  prefix == "/xxxx"
        }   //  until path is "/" or ""
        
        if (qq.empty() == true) return string("/"); //  result just "/"
        
        string ans;
        while (qq.empty() == false) {
            ans += qq.front();
            qq.pop_front();
        }

        return ans;
    }   //  O(n) time, O(n) space
};