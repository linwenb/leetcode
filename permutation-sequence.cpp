/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        /*
        (n,k) = (4,21)
        1. divide the solution set into 4 groups: "1xxx", "2xxx", "3xxx", and "4xxx", while each group has 3! = 6 members.
            From 21/6 = 3, we know that the 21th element is in the 3th group
        2. divide it into 3 sub-groups again: "41xx", "42xx" and "43xx", and each group has 2!=2 members.
            calculate 3/2 and get 1, so it's the 1st element of 1th sub-group - "421x"
        3. and so on
        */
        int nf[] = {1,1,2,6,24,120,720,5040,40320,362880}; //  0! - 9!
        
        list<int> lst;
        for (int i = 1; i <= n; i++) {
            lst.push_back(i);
        }
        
        list<int>::iterator p;
        
        string ans;
        k = (k - 1) % nf[n];  //  kth in 0 .... (k-1)
        
        for (int i = n - 1; i > 0; i--) {
            p = lst.begin();
            advance(p, k / nf[i]);	//	ans is at (k / nf[i])th subgroup
            
            ans += '0' + *p;
            
            k %= nf[i];		//	update k in sub-group
            
            lst.erase(p);
        }
        
        ans += '0' + lst.front(); //  last element left
        
        return ans;
    }	//	O(n) time, O(n) space
};