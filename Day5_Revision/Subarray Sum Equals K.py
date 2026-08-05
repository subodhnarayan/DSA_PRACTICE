# 560. Subarray Sum Equals K
# Solved
# Medium
# Topics
# premium lock icon
# Companies
# Hint
# Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

# A subarray is a contiguous non-empty sequence of elements within an array.

 

# Example 1:

# Input: nums = [1,1,1], k = 2
# Output: 2
# Example 2:

# Input: nums = [1,2,3], k = 3
# Output: 2
 

# Constraints:

# 1 <= nums.length <= 2 * 104
# -1000 <= nums[i] <= 1000
# -107 <= k <= 107


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:

        n=len(nums)
        count=0
        #Brute Force Approach
        #TC=0(n2) and SC=0(n)
        # for i in range(0,n):
        #     c_sum=0
        #     for j in range(i,n):
        #         c_sum+=nums[j]
        #         if c_sum==k:
        #             count+=1


        # return count


        #optimized appraoch
        #TC=0(n) and SC=0(n)
        prefixsum_map={}
        c_sum=0
        for i in range(0,n):
            c_sum+=nums[i]

            if c_sum==k:
                count+=1

            rem=c_sum-k
            if rem in prefixsum_map:
                count+=prefixsum_map[rem]


            prefixsum_map[c_sum]=prefixsum_map.get(c_sum,0)+1

        return count





# Explanation

# buddy here i am not able to understnand  rem=c_sum-k
#             if rem in prefixsum_map:
#                 count+=prefixsum_map[rem] how is is finding subraay. because subarray in contigous right
# The core idea relies on a key property of Prefix Sums: any contiguous subarray sum between 
# index i and index j can be written as the difference between two prefix sums.

# Subarray Sum(i to j)=PrefixSum[j]−PrefixSum[i−1]
# Step-by-Step Logic
# Targeting k:
# We want to find a contiguous subarray whose sum equals k:

# PrefixSum[j]−PrefixSum[i−1]=k
# Rearranging the Equation:

# PrefixSum[i−1]=PrefixSum[j]−k
# Here, c_sum is PrefixSum[j] (the running total up to the current element) and rem is PrefixSum[i−1].

# Why it guarantees contiguous elements:

# PrefixSum[j] is the sum of elements from index 0 to j: (nums[0]+⋯+nums[j]).

# PrefixSum[i−1] is the sum of elements from index 0 to i−1: (nums[0]+⋯+nums[i−1]).

# When you subtract PrefixSum[i−1] from PrefixSum[j], all terms from index 0 to i−1 cancel out completely, leaving only the contiguous block:

# nums[i]+nums[i+1]+⋯+nums[j]
# Concrete Example
# Consider nums = [1, 2, 3], k=3.

# At index 0 (nums[0] = 1):

# c_sum = 1

# rem = 1 - 3 = -2 (not in map)

# Store prefixsum_map[1] = 1

# At index 1 (nums[1] = 2):

# c_sum = 3 (sum of [1, 2])

# c_sum == k → count += 1 (Subarray [1, 2])

# Store prefixsum_map[3] = 1

# At index 2 (nums[2] = 3):

# c_sum = 6 (sum of [1, 2, 3])

# rem = 6 - 3 = 3

# Is 3 in prefixsum_map? Yes! (It was recorded at index 1).

# This means subtracting the prefix up to index 1 (1 + 2 = 3) from the prefix up to index 2 (1 + 2 + 3 = 6) 
# leaves the contiguous subarray [3] starting right after index 1.

# count += prefixsum_map[3] → count increments by 1.

# Key Takeaway
# By checking if rem (c_sum - k) exists in your hash map, you are asking: 
# "Have we seen an earlier prefix sum that, if chopped off from the beginning of our current total,
#  leaves a contiguous middle section summing to exactly k?"

       