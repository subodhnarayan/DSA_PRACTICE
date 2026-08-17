# Move All Zeroes to End
# Solved
# Difficulty: EasyAccuracy: 45.51%Submissions: 477K+Points: 2Average Time: 15m
# You are given an array arr[] of non-negative integers. You have to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array.

# Examples:

# Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
# Output: [1, 2, 4, 3, 5, 0, 0, 0]
# Explanation: There are three 0s that are moved to the end.
# Input: arr[] = [10, 20, 30]
# Output: [10, 20, 30]
# Explanation: No change in array as there are no 0s.
# Input: arr[] = [0, 0]
# Output: [0, 0]
# Explanation: No change in array as there are all 0s.
# Constraints:
# 1 ≤ arr.size() ≤ 105
# 0 ≤ arr[i] ≤ 105

# Expected Complexities
# Time Complexity: O(n)
# Auxiliary Space: O(1)


class Solution:
	def pushZerosToEnd(self, arr):
    	# code here
    	i=0
    	n=len(arr)
    	
    	#first approach
    	
        # 	for j in range(0,n):
        # 	    if arr[j]!=0:
        # 	        arr[i]=arr[j]
        # 	        i+=1
    	        
    # 	for k in range(i,n):
    # 	    arr[k]=0
    
        k=0
        for i in range(0,n):
            if arr[i]!=0:
                
                arr[i],arr[k]=arr[k],arr[i]
                k+=1
                
            
            
            
            
            
        
        
            
    
    
    