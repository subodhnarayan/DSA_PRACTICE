/*
Find Kth Rotation
Difficulty: Easy
Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Examples:

Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 107

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        
        //Brute Force
        //TC=O(N) and SC=0(1)
        // int min_ind=0;
        // int min_num=arr[0];
        
        // for(int i=0;i<n;i++){
        //   if(min_num>arr[i]){
        //       min_num=arr[i];
        //       min_ind=i;
        //   }
        // }
        
        // return min_ind;
        
        //OPTIMIZED APPROACH
        
        int start=0;
        int end=n-1;
        
        while(start<end){
            int mid=start+(end-start)/2;
            
            if(arr[mid]>arr[end]){  //checking whether it lies in right sorted array and 
            //we need to find minumum so we need push more toward right
                start=mid+1;
            }
            else{      //checking in left sorted and if present and push left and find the index
                end=mid;
            }
        }
        return end;
        
        
    }
};
