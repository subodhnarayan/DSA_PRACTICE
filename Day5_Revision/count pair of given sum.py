# Solved
# Difficulty: MediumAccuracy: 50.11%Submissions: 67K+Points: 4Average Time: 15m
# You are given an array arr[] and an integer target. You have to count all pairs in the array such that their sum is equal to the given target.

# Examples:

# Input: arr[] = [1, 5, 7, -1, 5], target = 6 
# Output: 3
# Explanation: Pairs with sum 6 are (1, 5), (7, -1) and (1, 5). 
# Input: arr[] = [1, 1, 1, 1], target = 2 
# Output: 6
# Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).
# Input: arr[] = [10, 12, 10, 15, -1], target = 125
# Output: 0
# Explanation: There is no pair with sum = target
# Constraints:
# 1 ≤ arr.size() ≤ 105
# -104 ≤ arr[i] ≤ 104
# 0 ≤ target ≤ 104

# Expected Complexities
# Time Complexity: O(n)
# Auxiliary Space: O(n)
# Topic Tags
# ArraysHashtwo-pointer-algorithm
# Related Articles
# Count Pairs With Given Sum


class Solution:
    def countPairs(self, arr, target):
        n=len(arr)
        count=0
        #Brute Force Approach
        # TC=0(n2) and SC=0(1)
        # for i in range(0,n-1):
        #     for j in range(i+1,n):
        #         c_sum=arr[i]+arr[j]
        #         if c_sum==target:
        #             count+=1
                    
                    
                    
        # return count
        
        #optimized approach
        #TC=0(n) and sc=0(n)
        my_map={}
        for i in range(0,n):
            rem=target-arr[i]
            if rem in my_map:
                count+=my_map[rem]
                
            
            my_map[arr[i]]=my_map.get(arr[i],0)+1
            
        return count