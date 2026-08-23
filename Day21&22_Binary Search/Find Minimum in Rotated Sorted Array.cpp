/*

Sorted and Rotated Minimum
Solved
Difficulty: Easy
A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

Examples:

Input: arr[] = [5, 6, 1, 2, 3, 4]
Output: 1
Explanation: 1 is the minimum element in the array.
Input: arr[] = [3, 1, 2]
Output: 1
Explanation: Here 1 is the minimum element.
Input: arr[] = [4, 2, 3]
Output: 2
Explanation: Here 2 is the minimum element.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 109

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        //Brute Force Appraoch
        //TC=O(n)  and SC=O(1)
        // int ans=arr[0];
        // for(int i=1;i<n;i++){
        //     ans=min(ans,arr[i]);
        // }
        // return ans;

        //Optimized Approach using Binary Search
        //TC=O(long) and SC=O(1)
        
        int start=0;
        int end=n-1;
        
        while(start<end){
            int mid=start+(end-start)/2;
            
            if(arr[mid]>arr[end]){ // this means the minimum element is in right sorted array so let check in that
                start=mid+1;
            }
            else{
                //this mean the minimum element is the left sorted order if(arr[mid]<=arr[end]) then we need to find in the left side right
                end=mid;
            }
        }
        return arr[start];
        
        
    }
};