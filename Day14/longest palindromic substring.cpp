/*
5. Longest Palindromic Substring
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.


*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isPalindrome(string &s,int start,int end){

        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }

            start++;
            end--;
        }
        return true;
    }

    int expand(string &s, int start,int end){
        while(start>=0 && end<s.size() && s[start]==s[end]){  //expanding here to 
            start--;
            end++;
        }
        return end-start-1;    //returing the length of palindrome substring
    }
    string longestPalindrome(string s) {


        int ans=0;
        int n=s.size();

        if (n<=1){
            return s;
        }

        //Brute Force Apporach

        //TC=0(N3) and SC=0(1)

        // int start_ind=-1;
        // int end_ind=-1;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //       if(isPalindrome(s,i,j)){
        //         int diff=(j-i+1);
        //         if(ans<diff){
        //      start_ind=i;
        //      end_ind=j;
        //      ans=diff;
        //         }
        //       }
        //     }
        // }

        // return s.substr(start_ind, end_ind - start_ind + 1);


        //Optimized approach


        int start=0;
        int end=0;

        for(int i=0;i<n;i++){
            int len1=expand(s,i,i); //getting the length for odd cases
            int len2=expand(s,i,i+1); //getting the length for even cases
            int len=max(len1,len2);



            if(len>(end-start)){
              start=i-(len-1)/2;    //calcuating the first ind of the substring
              end=i+len/2;          //calcuating the last ind of the palind substring
            }
        }

        return s.substr(start,end-start+1);

    }
};