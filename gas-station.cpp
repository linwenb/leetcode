/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	int n = gas.size();

        vector<int> diff(n);        
        int start = 0;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {            
            if (sum < 0) {
                start = i;
                sum = 0;
            }	//	cannot reach station i, lets start from i

            diff[i] = gas[i] - cost[i];	//	remaining gas from station i to i+1
            sum += diff[i];				//	remaining gas in car
        }	//	find the starting index
        
        if (sum < 0)    return -1;	//	not found
        
        for (int i = 0; i < start; i++) {
            sum += diff[i];
            
            if (sum < 0)    return -1;
        }	//	check if we can travel around the circuit once
        
        return start;	//	found
    }   //  O(n) time, O(n) space
};