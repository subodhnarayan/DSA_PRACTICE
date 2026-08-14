/*

680. Valid Palindrome II
Solved
Easy
Topics
premium lock icon
Companies
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.


*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
     bool isPalindrome(string& s,int start,int end) {
        // code here
        
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start=0;
        int end=s.size()-1;

        while(start<end){
            if(s[start]!=s[end]){
                return isPalindrome(s,start+1,end) || isPalindrome (s,start,end-1);
            }
            start++;
            end--;
        }
        return true;
        
    }
};