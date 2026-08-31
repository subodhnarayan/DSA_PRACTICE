/*
Equilibrium Point
Solved
Difficulty: Easy
Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2 
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.
Input: arr[] = [1, 1, 1, 1]
Output: -1
Explanation: There is no equilibrium index in the array.
Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.
Constraints:
3 <= arr.size() <= 105
-104 <= arr[i] <= 104

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)


*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        sum-=arr[0];
        
        int c_sum=0;
        if (sum==c_sum)
            return 0;
        for(int i=1;i<n;i++){
            c_sum+=arr[i-1]; //getting the left sum  
            sum-=arr[i];   //getting the right sum
            if(c_sum==sum){  //checking the left sum and right sum at i
                return i;
            }
            
        }
        return -1;
    
        
    }
};