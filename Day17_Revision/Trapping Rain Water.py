
# 42. Trapping Rain Water
# Solved
# Hard
# Topics
# premium lock icon
# Companies
# Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

# Example 1:


# Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
# Output: 6
# Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
# Example 2:

# Input: height = [4,2,0,3,2,5]
# Output: 9
 

# Constraints:

# n == height.length
# 1 <= n <= 2 * 104
# 0 <= height[i] <= 105


class Solution:
    def trap(self, arr: List[int]) -> int:
        n=len(arr)
        max_ind=-1
        max_val=0
        water=0
        for i in range(0,n):
            if max_val<arr[i]:
                max_ind=i
                max_val=arr[i]
                
        
        left_max=arr[0]
        for j in range(1,max_ind):
            if arr[j]>left_max:
                left_max=arr[j]
                
            else:
                water+=(left_max-arr[j])
                
            
            
            
        right_max=arr[n-1]
        for j in range(n-2,max_ind,-1):
            if arr[j]>right_max:
                right_max=arr[j]
                
            else:
                water+=(right_max-arr[j])
            
            
        return water
        

        
            
