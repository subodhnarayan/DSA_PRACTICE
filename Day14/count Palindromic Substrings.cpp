/*

647. Palindromic Substrings
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(string &s, int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int expand(string &s,int start,int end){
        int count=0;
        while(start>=0 && end<s.size() && s[start]==s[end]){
            count++;  //getting the count when find same in opposite end
            start--;
            end++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        int n=s.size();

        //Brute Force Approach
        //TC=O(n3)
        // for (int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(isPalindrome(s,i,j)){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //Optimized way using the expanded form

        //TC=0(N2) and SC=0(1)
        for(int i=0;i<n;i++){
            count+=expand(s,i,i);  //checking for odd length substring
            count+=expand(s,i,i+1);
        }

        return count;
    }
};


