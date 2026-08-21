/*
Sorted Insert Position
Solved
Difficulty: EasyAccuracy: 38.99%Submissions: 111K+Points: 2
Given a sorted array arr[] (0-index based) of distinct integers and an integer k, find the index of k if it is present in the arr[]. If not, return the index where k should be inserted to maintain the sorted order.

Examples :

Input: arr[] = [1, 3, 5, 6], k = 5
Output: 2
Explanation: Since 5 is found at index 2 as arr[2] = 5, the output is 2.
Input: arr[] = [1, 3, 5, 6], k = 2
Output: 1
Explanation: The element 2 is not present in the array, but inserting it at index 1 will maintain the sorted order.
Input: arr[] = [2, 6, 7, 10, 14], k = 15
Output: 5
Explanation: The element 15 is not present in the array, but inserting it after index 4 will maintain the sorted order.
Constraints:
1 ≤ arr.size() ≤ 104
-103 ≤ arr[i] ≤ 103
-103 ≤ k ≤ 103

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)





*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        
        int n=arr.size();
        //Brute Force
        //TC=0(n) and SC=0(n)
        // for(int i=0;i<n;i++){
        //     if(arr[i]>=k){
        //         return i;
        //     }
        // }
        // return n;
        
        int start=0;
        int end=n-1;
        
        int index=n;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(arr[mid]==k){
                return mid;
            }
            else if(arr[mid]>k){
                index=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return index;
    }
};