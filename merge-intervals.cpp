/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
    	vector<Interval> ans;

    	int n = intervals.size();        
        if (n == 0)  return ans;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int tSt = intervals.front().start;	//	start value of merged interval
        int tEnd = intervals.front().end;	//	end value of merged interval
        
        for (int i = 1; i < n; i++) {
            if (intervals[i].start <= tEnd) {
                if (intervals[i].end > tEnd)	tEnd = intervals[i].end;   //  merge
            }
            else {
                ans.push_back(Interval(tSt, tEnd));	//	insert the merged interval
                
                tSt = intervals[i].start;
                tEnd = intervals[i].end;
            }   //  intervals[i].start > tEnd
        }
        
        ans.push_back(Interval(tSt, tEnd));		//	remember the last one        
        return ans;
    }	//	O(n) time if sorted, O(1) space
    
    static bool cmp(const Interval &a, const Interval &b) {
        if (a.start < b.start)  return true;
        else if (a.start > b.start) return false;
        else if (a.end > b.end) return true;
        else    return false;
    }	//	must be static, since it inside the class
};