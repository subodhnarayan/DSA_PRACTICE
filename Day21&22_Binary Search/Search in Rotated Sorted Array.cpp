/*

Search in Rotated Sorted Array
Solved
Difficulty: Medium
Given an array arr[] of distinct elements, which was initially sorted in ascending order but then rotated at some unknown pivot, the task is to find the index of a target key.  If the key is not present in the array, return -1.

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
Output: 8
Explanation: 3 is found at index 8.
Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.
Input: arr[] = [33, 42, 72, 99], key = 42
Output: 1
Explanation: 42 is found at index 1.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
0 ≤ key ≤ 106

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)

*/



#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        
        //Brute Force Apporach
        //TC=(n)nnd SC=o(1)
        int n=arr.size();
        // for(int i=0;i<n;i++){
        //     if(arr[i]==key){
        //         return i;
        //     }
        // }
        // return -1;
        

         
         int start=-0;
         int end=n-1;
         
         while(start<=end){
             
             int mid=start+(end-start)/2;

             
             if(arr[mid]==key){
                 return mid;
             }
             
             
             //when left side is strictly sorted
             if(arr[start]<=arr[mid]){
                 // Check if the key lies within the boundaries of this sorted left half.
                 // Since the left side is uniform, if the key is between arr[start] and arr[mid],
                 // it is guaranteed to be here. We throw away the right side by moving 'end'.
                 if(arr[start]<=key && key<arr[mid]) // here key<=arr[mid] because arr[mid]==key is hadledy by first case
                {
                    end=mid-1; 
                }
                // Otherwise, the key must reside in the unsorted/rotated right half.
                else{
                    start=mid+1;
                }
             }
              // CASE 2: The right half of the search space is strictly sorted
             else{
                 
                 // Check if the key lies within the boundaries of this sorted right half.
                 // Since the right side is uniform, if the key is between arr[mid] and arr[end],
                 // it is guaranteed to be here. We throw away the left side by moving 'start'.
            
                 if(arr[mid]<key && key<=arr[end]){
                     start=mid+1;   
                 }
                 // Otherwise, the key must reside in the unsorted/rotated left half.
                 
                 else{
                     end=mid-1;
                 }
             }
         }
         return -1;
        
        
    }
};