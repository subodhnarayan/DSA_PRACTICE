

# Anagram
# Solved
# Difficulty: EasyAccuracy: 44.93%Submissions: 497K+Points: 2Average Time: 20m
# Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not.
# Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order.

# Examples:

# Input: s1 = "geeks" s2 = "kseeg"
# Output: true 
# Explanation: Both the string have same characters with same frequency. So, they are anagrams.
# Input: s1 = "allergy", s2 = "allergyy" 
# Output: false 
# Explanation: Although the characters are mostly the same, s2 contains an extra 'y' character. Since the frequency of characters differs, the strings are not anagrams. 
# Input: s1 = "listen", s2 = "lists" 
# Output: false 
# Explanation: The characters in the two strings are not the same — some are missing or extra. So, they are not anagrams.
# Constraints:
# 1 ≤ s1.size(), s2.size() ≤ 105
# s1, s2 consists of lowercase English letters.

# Expected Complexities
# Time Complexity: O(n + m)
# Auxiliary Space: O(1)
# Company Tags
# FlipkartDirectiAdobeGoogleNagarroMedia.net
# Topic Tags
# Strings Sorting




class Solution:
    def areAnagrams(self, s1, s2):
       # code here
      freq=[0]*26
      
      n1=len(s1)
      n2=len(s2)
      
      if n1!=n2:
          return False
      
      
      for i in range(0,n1):
          freq[ord(s1[i])-ord('a')]+=1
          freq[ord(s2[i])-ord('a')]-=1
          
          
      for i in freq:
          if i!=0:
              return False
              
              
      return True
          
      
       