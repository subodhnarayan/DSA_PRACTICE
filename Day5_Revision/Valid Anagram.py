# 242. Valid Anagram
# Solved
# Easy
# Topics
# premium lock icon
# Companies
# Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

# Example 1:

# Input: s = "anagram", t = "nagaram"

# Output: true

# Example 2:

# Input: s = "rat", t = "car"

# Output: false

 

# Constraints:

# 1 <= s.length, t.length <= 5 * 104
# s and t consist of lowercase English letters.
 

# Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:


        n1=len(s)
        n2=len(t)

        if n1!=n2:
            return False

        #Brute Force
        
        # sorted_s="".join(sorted(s))
        # sorted_t="".join(sorted(t))

        # return sorted_s==sorted_t

        #opmimal_apporach using hashmap
        # my_map1={}
        # my_map2={}

        # for str in s:
        #     my_map1[str]=my_map1.get(str,0)+1


        # for str in t:
        #     my_map2[str]=my_map2.get(str,0)+1


        # return my_map1==my_map2

        freq=[0]*26

        for ch in s:
            freq[ord(ch)-ord('a')]+=1


        for ch in t:
            freq[ord(ch)-ord('a')]-=1

        for ele in freq:
            if ele != 0:
                return False


        return True
        



        