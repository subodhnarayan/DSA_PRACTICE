# 680. Valid Palindrome II
# Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

# Example 1:

# Input: s = "aba"
# Output: true
# Example 2:

# Input: s = "abca"
# Output: true
# Explanation: You could delete the character 'c'.
# Example 3:

# Input: s = "abc"
# Output: false
 

# Constraints:

# 1 <= s.length <= 105
# s consists of lowercase English letters.

class Solution:
    def isPalindrome(self,s:str,start:int,end:int)->bool:
        while start<end:
            if s[start]!=s[end]:
                return False

            start+=1
            end-=1

        return True
    def validPalindrome(self, s: str) -> bool:
        n=len(s)
        start=0
        end=n-1
        while start<end:
            if s[start]!=s[end]:
                return self.isPalindrome(s,start+1,end) or self.isPalindrome(s,start,end-1)
            start+=1
            end-=1

        return True