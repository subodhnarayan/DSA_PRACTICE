 /*

First and Last in Sorted
Solved
Difficulty: MediumAccuracy: 37.36%Submissions: 364K+Points: 4Average Time: 15m
Given a sorted array arr[] with possibly some duplicates, find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.

Examples:

Input: arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5
Output: [2, 5]
Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5
Input: arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125], x = 7
Output: [6, 6]
Explanation: First and last occurrence of 7 is at index 6
Input: arr[] = [1, 2, 3], x = 4
Output: [-1, -1]
Explanation: No occurrence of 4 in the array, so, output is [-1, -1]
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i], x ≤ 109

Expected Complexities
Company Tags
AmazonGoogleMicrosoft
Topic Tags
ArraysBinary Search


*/

class Solution {
public:
    int endIndex(vector<int> &arr,int x){
        int n=arr.size();
        
        int endInd=-1;
        
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(arr[mid]==x){
                endInd=mid;
                left=mid+1;
            }
            else if(arr[mid]>x){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        
        if(endInd==n){
            endInd=-1;
        }
        return endInd;
    }
    int firstInd(vector<int> &arr,int x){
        int n=arr.size();
        
        int startInd=-1;
        
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(arr[mid]==x){
                startInd=mid;
                right=mid-1;
            }
            else if(arr[mid]>x){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        
        
        return startInd;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        //Brute force Approach
        //TC=0(n) and SC=0(1)
        // int n=nums.size();
        // int first=INT_MAX;
        // int last=INT_MIN;

        
        // for(int i=0;i<n;i++){
        //     if(nums[i]==target){
        //         first=min(first,i);
        //         last=max(last,i);
        //     }
        // }

        // if(first==INT_MAX) first=-1;
        // if(last==INT_MIN) last=-1;
        // return {first,last};

        //optmized appraoch using binary search
        int n=nums.size();
        int start=0;
        int end=n-1;

        if (nums.empty()) return {-1, -1};
       return {firstInd(nums,target),endIndex(nums,target)};
    }
};