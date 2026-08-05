# Longest Subarray with Sum K
# Solved
# Difficulty: MediumAccuracy: 24.64%Submissions: 851K+Points: 4
# Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

# Examples:

# Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
# Output: 6
# Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
# Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
# Output: 5
# Explanation: Subarrays with sum = -5 are [-5] and [-5, 8, -14, 2, 4]. The length of the longest subarray with a sum of -5 is 5.
# Input: arr[] = [10, -10, 20, 30], k = 5
# Output: 0
# Explanation: No subarray with sum = 5 is present in arr[].
# Constraints:
# 1 ≤ arr.size() ≤ 105
# -104 ≤ arr[i] ≤ 104
# -109 ≤ k ≤ 109

# Expected Complexities
# Time Complexity: O(n)
# Auxiliary Space: O(n)
# Company Tags
# Amazon
# Topic Tags
# ArraysHashMapprefix-sum
# Related Articles
# Longest Sub Array Sum K




class Solution:
    def longestSubarray(self, arr, k):
        n=len(arr)
        longest=0
        
        #Brute force
        #TC=0(n2) and SC=0(n)
        # for i in range(0,n):
        #   c_sum=0
        #   for j in range(i,n):
        #       c_sum+=arr[j]
        #       if c_sum==k:
        #           longest=max(longest,j-i+1)
               
        # return longest
        
        
        #Optimized approach
        #TC=0(n) and SC=0(n)
        my_map={}
        c_sum=0
        for i in range(0,n):
            c_sum+=arr[i]
            
            
            if c_sum==k:
                longest=max(longest,i+1)
                
            rem=c_sum-k
            if rem in my_map:
                longest=max(longest,i-my_map[rem])
                
            
            if c_sum not in my_map: # we will write to get largest subarray length
                my_map[c_sum]=i
                
                
        return longest
            
            
       
       