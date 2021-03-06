/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(int A[], int n) {
        int color[3] = {0};

        for (int i = 0; i < n; i++) {
            color[A[i]]++;
        }

        for (int i = 0, j = 0; i < n; i++) {
            while (color[j]-- <= 0)  j++;
            
            A[i] = j;
        }
    }   //  O(n) time, O(1) space, two-pass, counting sort
};

class Solution {
public:
    void sortColors(int A[], int n) {
        int index[3] = {0};
        int color;

        for (int i = 0; i < n; i++) {
            color = A[i];
            for (int j = 2; j >= color; j--) {
                A[index[j]++] = j;
            }
        }
    }   //  O(n) time, O(1) space, one-pass?
};