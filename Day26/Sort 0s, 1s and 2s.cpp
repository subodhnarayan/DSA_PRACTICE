/*
Sort 0s, 1s and 2s
Solved
Difficulty: Medium
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
Note: You need to solve this problem without utilizing the built-in sort function.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s, 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s, 1s and 2s are segregated into ascending order.
Follow up: Could you come up with a one-pass algorithm using only constant extra space?

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 2

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        int i=0;
        int j=0;
        int k=n-1;
        
        while(j<=k){
            if(arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j++; // Safe to move j forward because arr[i] was already processed
            }
            else if(arr[j]==1){
               j++; // 1 is in the middle segment, just move forward
            }
            else
            {
             swap(arr[j],arr[k]);
             k--; 
                // Do NOT increment j here! Re-evaluate arr[j] on the next iteration.
            }
        }
    }
};