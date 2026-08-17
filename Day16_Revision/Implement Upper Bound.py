# Implement Upper Bound
# Solved
# Difficulty: EasyAccuracy: 52.54%Submissions: 68K+Points: 2
# Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
# The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

# Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.

# Examples :

# Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
# Output: 3
# Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.
# Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
# Output: 6
# Explanation: 6 is the smallest index in arr[], at which element (arr[6] = 25) is larger than 11.
# Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
# Output: 7
# Explanation: As no element in arr[] is greater than 100, return the length of array.
# Constraints:
# 1 ≤ arr.size() ≤ 106
# 1 ≤ arr[i] ≤ 106
# 1 ≤ target ≤ 106

# Expected Complexities
# Time Complexity: O(log n)
# Auxiliary Space: O(1)


class Solution:
    def upperBound(self, arr, target):
        # code here
        n=len(arr)
        #Brute Force
        # for i in range(0,n):
        #     if arr[i]>target:
        #         return i
                
                
                
        # return n
        
        
        index=-1
        start=0
        end=n
        
        while start<end:
            mid=start+(end-start)//2
            
            if arr[mid]<=target:
                start=mid+1
                
            else:
                end=mid
                
        
        return start
        