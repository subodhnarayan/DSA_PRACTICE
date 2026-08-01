# ///                    Sum of Two Number                 ////

# 1. Two Sum
# Solved
# Easy
# Topics
# premium lock icon
# Companies
# Hint
# You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# You can return the answer in any order.

 

# Example 1:

# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
# Example 2:

# Input: nums = [3,2,4], target = 6
# Output: [1,2]
# Example 3:

# Input: nums = [3,3], target = 6
# Output: [0,1]
 

# Constraints:

# 2 <= nums.length <= 104
# -109 <= nums[i] <= 109
# -109 <= target <= 109
# Only one valid answer exists.
 

# Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?



class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
       
        n=len(nums)
        # if n<2:
        #     return [-1,-1]
        
         ##brue force approach
         ## TC=0(N2) and SC=0(1)
        # for i in range(0,n-1):
        #     for j in range(i+1,n):
        #         sum=nums[i]+nums[j]
        #         if(sum==target):
        #             return [i,j]


        # return [-1,-1]
         
        #optimized approach
        #using map and instead of map we will use dict in python
        ## TC=0(N) and SC=0(N)

        my_map={}
        for i in range(0,n):
            rem=target-nums[i]
            if rem in my_map:
                return [i,my_map[rem]]
            
            my_map[nums[i]]=i

        return [-1,-1]

        