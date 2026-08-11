

# First and Last in Sorted
# Solved
# Difficulty: MediumAccuracy: 37.36%Submissions: 364K+Points: 4Average Time: 15m
# Given a sorted array arr[] with possibly some duplicates, find the first and last occurrences of an element x in the given array.
# Note: If the number x is not found in the array then return both the indices as -1.

# Examples:

# Input: arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5
# Output: [2, 5]
# Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5
# Input: arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125], x = 7
# Output: [6, 6]
# Explanation: First and last occurrence of 7 is at index 6
# Input: arr[] = [1, 2, 3], x = 4
# Output: [-1, -1]
# Explanation: No occurrence of 4 in the array, so, output is [-1, -1]
# Constraints:
# 1 ≤ arr.size() ≤ 106
# 1 ≤ arr[i], x ≤ 109

# Expected Complexities
# Company Tags
# AmazonGoogleMicrosoft
# Topic Tags
# ArraysBinary Search



class Solution:
    def find_last(self,nums:List[int], target:int) ->int:
        n=len(nums)
        last_ind=-1
        start=0
        end=n-1
        while start<=end:
            mid=start+(end-start)//2
            if nums[mid]==target:
                last_ind=mid
                start=mid+1
            elif nums[mid]>target:
                end=mid-1
            else:
                start=mid+1
        
        return last_ind

    def find_first(self,nums:List[int], target:int) ->int:
        n=len(nums)
        first_ind=-1
        start=0
        end=n-1
        while start<=end:
            mid=start+(end-start)//2
            if nums[mid]==target:
                first_ind=mid
                end=mid-1
            elif nums[mid]>target:
                end=mid-1
            else:
                start=mid+1
        
        return first_ind
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        n=len(nums)

        if n==0:
            return [-1,-1]

        # first_ind=n
        # last_ind=-1

        #Brute Force Appraoch
        # for i in range(0,n):
        #     if nums[i]==target:
        #         first_ind=min(first_ind,i)
        #         last_ind=max(last_ind,i)

        # if first_ind==n:
        #     first_ind=-1

        # return [first_idx,last_idx]


        return [self.find_first(nums,target),self.find_last(nums,target)]








        
        