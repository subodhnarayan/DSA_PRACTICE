/*

Number of Occurrence
Solved
Difficulty: Easy
Given a sorted array arr[] and a number target, find the number of occurrences of target in given array. 

Examples:

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findFirst(vector<int>&arr, int target){
        int n=arr.size();
        int index=-1;
        
        int start=0;
        int end=n-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(arr[mid]==target){
                index=mid;
                end=mid-1;
            }
            else if(arr[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return index;
        
    }
    int findLast(vector<int>&arr, int target){
        int n=arr.size();
        int index=-1;
        
        int start=0;
        int end=n-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(arr[mid]==target){
                index=mid;
                start=mid+1;
            }
            else if(arr[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return index;
        
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int count=0;
        //Brute Force Approach
        //TC=0(n) and SC=(1)
        // for(int i=0;i<n;i++){
        //     if(arr[i]==target){
        //         count++;
        //     }
        // }
        // return count;
        
        //Optimized Approach using Binary Search
        
        //TC=0(logn) and SC=0(1)
        
        int first=findFirst(arr,target);
        if(first==-1) return 0;
        
        return ((findLast(arr,target)-first)+1);
    }
};
