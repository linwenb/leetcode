/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int n = words.size();

        int start = 0;
        int len = 0;

        int wordSize;   //  length of current processing word
        
        vector<string> ans;
        
        for (int i = 0; i < n; i++) {
            wordSize = words[i].size();
            
            if (start == i) {
                len = wordSize;
            }   //  row is empty
            else if (len + 1 + wordSize <= L) {
                len += 1 + wordSize;    //  with one space
            }   //  line size not yet exceeds L
            else {
                ans.push_back(fullJustify(words, start, i - 1, len, L));
                
                start = i;  //  new start position
                i--;        //  revisit this word
            }   //  line size exceeds L
        }
        
        ans.push_back(lastLine(words, start, len, L));
        
        return ans;
    }   //  O(?) time, O(1) space
    
    string lastLine(const vector<string> &words, const int start, const int len, const int L) {
        string ans = words[start];
        ans.reserve(L);
        
        int n = words.size();
        for (int i = start + 1; i < n; i++) {
            ans.append(1, ' ');
            ans.append(words[i]);
        }   //  left-justified
        
        ans.resize(L, ' ');     //  append enough spaces
        
        return ans;
    }
    
    string fullJustify(const vector<string> &words, const int start, const int end, const int len, const int L) {
        string ans = words[start];
        ans.reserve(L);
        
        if (start == end) {
            ans.resize(L, ' ');
        }   //  number of words is 1
        else {
            int nSlot = end - start;               // number of empty slots
            int nSpace = (L - len) / nSlot + 1;  // number of spaces in each slot
            int nOneMore = (L - len) % nSlot;    // left slots assigned one more space
            
            for (int i = start + 1; i <= end; i++) {
                if (i - start <= nOneMore) {
                    ans.append(nSpace + 1, ' ');
                }   // left slots with one more space
                else {
                    ans.append(nSpace, ' ');
                }   // right slots
                
                ans.append(words[i]);
            }
        }   //  number of words is greater than 1

        return ans;
    }
};