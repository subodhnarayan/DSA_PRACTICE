# Pairs with difference k
# Solved
# Difficulty: EasyAccuracy: 22.41%Submissions: 65K+Points: 2
# Given an array arr[] of positive integers. Find the number of pairs of integers whose absolute difference equals to a given number k.
# Note: (a, b) and (b, a) are considered the same. Also, the same numbers at different indices are considered different.

# The answer is guaranteed to fit in a 32-bit integer.

# Examples:

# Input: arr[] = [1, 4, 1, 4, 5], k = 3
# Output: 4
# Explanation: There are 4 pairs with absolute difference 3, the pairs are {1, 4}, {1, 4}, {4, 1} and {1, 4}.
# Input: arr[] = [8, 16, 12, 16, 4, 0], k = 4
# Output: 5
# Explanation: There are 5 pairs with absolute difference 4, the pairs are {8, 12}, {8, 4}, {16, 12}, {12, 16}, {4, 0}.
# Constraints:
# 1 <= arr.size() <= 2*105
# 1 <= k <= 2*105
# 0 <= arr[i] <= 105

# Expected Complexities
# Company Tags
# Adobe
# Topic Tags
# Arrays
# Related Articles
# Count Pairs Difference Equal K



def countPairs(self, arr, k):
    	# code here
    	n=len(arr)
    	count=0
    	# for i in range(0,n-1):
    	#     for j in range(i+1,n):
    	#         diff=abs(arr[i]-arr[j])
    	#         if diff==k:
    	#             count+=1
    	            
    	# return count
    
        my_freq={}
        for i in range(0,n):
            rem1=arr[i]-k
            rem2=arr[i]+k
            
            if rem1 in my_freq:
                count+=my_freq[rem1]
                
            if rem2 in my_freq:
                count+=my_freq[rem2]
                
            my_freq[arr[i]]=my_freq.get(arr[i],0)+1
            
            
        return count



# why here elif if not worked
# Using elif instead of if fails because both conditions can be true at the same time, and you 
# need to count pairs for both cases.

# If elif were used:

# Python
# if rem1 in my_freq:
#     count += my_freq[rem1]
# elif rem2 in my_freq:  # <--- SKIPPED if rem1 is True!
#     count += my_freq[rem2]
# Why Both Can Be True
# For a current element arr[i]:

# rem1 = arr[i] - k represents a smaller previous element.

# rem2 = arr[i] + k represents a larger previous element.

# If both rem1 and rem2 already exist in my_freq, arr[i] forms valid pairs with both of them simultaneously.

# Example
# Suppose k=2 and the array seen so far contains [1, 5]:

# Current element: arr[i] = 3

# rem1 = 3 - 2 = 1 (present in my_freq)

# rem2 = 3 + 2 = 5 (present in my_freq)

# 3 forms a valid pair with 1 (∣3−1∣=2) and with 5 (∣3−5∣=2).

# With two if statements, both 1 and 5 are counted (count+1+1).

# With elif, Python executes only the first block (rem1) and skips rem2, causing you to miss valid pairs and undercount the total.