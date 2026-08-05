# 15. 3Sum
# Solved
# Medium
# Topics
# premium lock icon
# Companies
# Hint
# Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

# Notice that the solution set must not contain duplicate triplets.

 

# Example 1:

# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
# Explanation: 
# nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
# nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
# nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
# The distinct triplets are [-1,0,1] and [-1,-1,2].
# Notice that the order of the output and the order of the triplets does not matter.
# Example 2:

# Input: nums = [0,1,1]
# Output: []
# Explanation: The only possible triplet does not sum up to 0.
# Example 3:

# Input: nums = [0,0,0]
# Output: [[0,0,0]]
# Explanation: The only possible triplet sums up to 0.
 

# Constraints:

# 3 <= nums.length <= 3000
# -105 <= nums[i] <= 105



class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:

        n=len(nums)
        nums.sort()

        #Brute Force Approach
        #TC=0(n3) and sc=0(n)
        # my_set=set()
        # for i in range(0,n-2):
        #     for j in range(i+1,n-1):
        #         for k in range(j+1,n):
        #             sum=nums[i]+nums[j]+nums[k]
        #             if sum == 0:
        #                 my_set.add((nums[i],nums[j],nums[k]))

        
        # my_arr=[]
        # for ele in my_set:
        #     my_arr.append(list(ele))


        # return my_arr


        #optimized Approach
        my_ans=[]
        if n<3:
            return my_ans
        for i in range(0,n-2):
            if(i>0) and nums[i]==nums[i-1]:
                continue

            start=i+1
            end=n-1
            while start<end:
                rem=0-nums[i]
                c_sum=nums[start]+nums[end]
                if rem==c_sum:
                    my_ans.append([nums[i],nums[start],nums[end]])
                    start+=1
                    end-=1

                    while start<end and nums[start-1]==nums[start]:
                        start+=1
                    
                    while start<end and nums[end]==nums[end+1]:
                        end-=1

                elif rem<c_sum:
                    end-=1

                else:
                    start+=1


        return my_ans