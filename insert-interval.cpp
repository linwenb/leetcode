/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int n = intervals.size();
        vector<Interval> ans;
        
        if (n == 0)  {
            ans.push_back(newInterval);
            return ans;
        }
        
        int lIndex = findLeftIndex(intervals, newInterval);
        int rIndex = findRightIndex(intervals, newInterval);
        
        if (lIndex == -1 && rIndex == n) {
            ans.push_back(newInterval);
            return ans;
        }   //  newInterval covers the whole intervals
        
        int st, en;  //  start and end value for a merged interval

        if (lIndex == -1) {
            st = newInterval.start;
        }   //  newInterval.start before the leftmost endpoint of intervals
        else {
            if (newInterval.start <= intervals[lIndex].end) {
                st = intervals[lIndex].start;
            }   //  newInterval.start in intervals[lIndex]
            else {
                st = newInterval.start;
                lIndex++; //  ans should include intervals[lIndex]
            }   //  newInterval.start after intervals[lIndex]
            
            ans.insert(ans.end(), intervals.begin(), intervals.begin() + lIndex);
        }   //  newInterval.start after the leftmost endpoint of intervals
        
        if (rIndex == n) {
            en = newInterval.end;
            ans.push_back(Interval(st, en));    //  merged interval will cover all remaining
        }   //  newInterval.end after the rightmost endpoint of intervals
        else {
            if (newInterval.end >= intervals[rIndex].start) {
                en = intervals[rIndex].end;
                rIndex++;    //  ans should NOT include intervals[rIndex]
            }   //  newInterval.end in intervals[rIndex]
            else {
                en = newInterval.end;
            }   //  newInterval.end before intervals[rIndex]
            
            ans.push_back(Interval(st, en));    //  merged interval
            ans.insert(ans.end(), intervals.begin() + rIndex, intervals.end()); //  remaining intervals
        }   //  newInterval.end before the rightmost endpoint of intervals
        
        return ans;
    }   //  O(n) time, O(1) space
    
    int findLeftIndex(const vector<Interval> &intervals, const Interval &newInterval) {
        //  find the first index i s.t. intervals[i].start <= newInterval.start
        int x = newInterval.start;
        if (intervals.front().start > x)    return -1;  //  not found
        
        int left = 0;      //  binary search
        int right = intervals.size() - 1;
        int mid;
        
        while (left < right - 1) {   //  avoid infinite loop
            mid = left + (right - left) * 0.5;

			if (intervals[mid].start == x) {
				return mid;
			}
			else if (intervals[mid].start > x) {
				right = mid - 1;
			}
			else {
				left = mid;
			}   //  intervals[mid].start < x
        }
        
        return (intervals[right].start <= x) ? right : left;    //  two elements left
    }   //  O(log n) time, O(1) space
    
    int findRightIndex(const vector<Interval> &intervals, const Interval &newInterval) {
        //  find the last index i s.t. newInterval.end <= intervals[i].end
        int x = newInterval.end;
        if (x > intervals.back().end)    return intervals.size();   //  not found
        
        int left = 0;   //  binary search
        int right = intervals.size() - 1;
        int mid;
        
        while (left < right - 1) {   //  avoid infinite loop
            mid = left + (right - left) * 0.5;

			if (intervals[mid].end == x) {
				return mid;
			}
			else if (intervals[mid].end < x) {
				left = mid + 1;
			}
			else {
				right = mid;
			}   //  intervals[mid].end > x
        }
        
        return (x <= intervals[left].end) ? left : right;
    }   //  O(log n) time, O(1) space
};