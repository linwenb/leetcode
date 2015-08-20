/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        
        if (n < 2) return n;
        
        int maxCount = 2;
        int count;
        int numDuplPts;
        int slope;
        
        unordered_map<int, int> lines;
        unordered_set<int> visited;
        
        //	n - maxCount to reduce searching time
        for (int i = 0; i < n - maxCount; i++) {
            
            //  check this point visited or not
            count = points[i].x * 10000 + points[i].y;

            //	duplicate point, visited
            if (visited.find(count) != visited.end())    continue;
            
            //  not visited yet            
            visited.insert(count);
            count = 1;
            numDuplPts = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    numDuplPts++;
                    continue;
                }   //  duplicate points
                
                if (points[i].x == points[j].x) {
                    slope = INT_MAX;
                }   //  this is a vertical line
                else {
                    slope = (int)((double)(points[i].y - points[j].y) / (points[i].x - points[j].x) * 100000.0);
                }   //  slope is stored with only 5 digits after dot
                
                if (lines.find(slope) == lines.end())	lines[slope] = 1; //  form a new line
                
                lines[slope]++; //  one more point on that line
                if (count < lines[slope])   count = lines[slope];
            }	//	for the remaining points
            
            count += numDuplPts;
            
            if (count > maxCount)   maxCount = count;
            
            lines.clear();
        }
        
        return maxCount;
    }   //  O(n^2) time, O(n) space
};