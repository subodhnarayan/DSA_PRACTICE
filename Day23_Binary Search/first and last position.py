# 34. Find First and Last Position of Element in Sorted Array
# Medium
# Topics
# Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

# If target is not found in the array, return [-1, -1].

# You must write an algorithm with O(log n) runtime complexity.

 

# Example 1:

# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]
# Example 2:

# Input: nums = [5,7,7,8,8,10], target = 6
# Output: [-1,-1]
# Example 3:

# Input: nums = [], target = 0
# Output: [-1,-1]
 

# Constraints:

# 0 <= nums.length <= 105
# -109 <= nums[i] <= 109
# nums is a non-decreasing array.
# -109 <= target <= 109


class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        n=len(nums)
        start=0
        end=n-1
        startind=-1

        while start<=end:
            mid=start+(end-start)//2

            if nums[mid]==target:
                startind=mid
                end=mid-1

            elif nums[mid]<target:
                start=mid+1

            else:
                end=mid-1

        if startind==-1:
            return [-1,-1]
        
        start=0
        end=n-1
        endind=-1

        while start<=end:
            mid=start+(end-start)//2

            if nums[mid]==target:
                endind=mid
                start=mid+1

            elif nums[mid]<target:
                start=mid+1

            else:
                end=mid-1


        return [startind,endind]


        