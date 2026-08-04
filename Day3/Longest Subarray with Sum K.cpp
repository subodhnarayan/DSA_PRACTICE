 /*
Longest Subarray with Sum K
Solved
Difficulty: MediumAccuracy: 24.64%Submissions: 851K+Points: 4
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Subarrays with sum = -5 are [-5] and [-5, 8, -14, 2, 4]. The length of the longest subarray with a sum of -5 is 5.
Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
-109 ≤ k ≤ 109

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
Company Tags
Amazon
Topic Tags
ArraysHashMapprefix-sum
Related Articles
Longest Sub Array Sum K

*/

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int longest=0;
        
        //Brute Force
        //TC=0(N2) and SC=0(1)
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=arr[j];
        //         if(sum==k){
        //             longest=max(longest,j-i+1);
        //         }
        //     }
        // }
        // return longest;
        
        //optimized approach
        
        unordered_map<int,int> prefixsum_mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            // 1. If sum itself is k, subarray starts from index 0

            //if we dont want to put this statment here then in up we need to initialze with prefixxum_mp[0]=-1;
            if(sum==k){
                longest=max(longest,i+1);
            }
            
            // 2. If (sum - k) exists, a subarray summing to k exists
            int rem=sum-k;
            if(prefixsum_mp.find(rem)!=prefixsum_mp.end()){
                longest=max(longest,i-prefixsum_mp[rem]);
            }
            
            // 3. Store prefix sum ONLY if it doesn't already exist
            //we need longest length so we dont need to feed the lastest 
            
             if(prefixsum_mp.find(sum)==prefixsum_mp.end()){
               prefixsum_mp[sum]=i;
            }
            
        }
        return longest;
        
    }


