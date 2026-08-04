
 /*
Anagram
Solved
Difficulty: EasyAccuracy: 44.93%Submissions: 497K+Points: 2Average Time: 20m
Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not.
Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order.

Examples:

Input: s1 = "geeks" s2 = "kseeg"
Output: true 
Explanation: Both the string have same characters with same frequency. So, they are anagrams.
Input: s1 = "allergy", s2 = "allergyy" 
Output: false 
Explanation: Although the characters are mostly the same, s2 contains an extra 'y' character. Since the frequency of characters differs, the strings are not anagrams. 
Input: s1 = "listen", s2 = "lists" 
Output: false 
Explanation: The characters in the two strings are not the same — some are missing or extra. So, they are not anagrams.
Constraints:
1 ≤ s1.size(), s2.size() ≤ 105
s1, s2 consists of lowercase English letters.

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(1)
Company Tags
FlipkartDirectiAdobeGoogleNagarroMedia.net
Topic Tags
Strings Sorting

*/


#include <bits/stdc++.h>
using namespace std;


bool areAnagrams(string& s1, string& s2) {
        // code here
       
        int n1=s1.size();
        int n2=s2.size();
        if(n1!=n2) return false;
        
        //Brute Force Approach
        //TC=(nlongn) and SC=0(1)
        // sort(s1.begin(),s1.end());
        // sort(s2.begin(),s2.end());
        
        // return s1==s2;
        
        
        
      //  better appraoch
        
        //  unordered_map<char,int> mp1;
        //  unordered_map<char,int> mp2;
        
        // for(char ch:s1){
        //     mp1[ch]++;
        // }
        
        // for(char ch:s2){
        //     mp2[ch]++;
        // }
        
        // return mp1==mp2;
        
        
        //optimized approach
        
        int freq[24]={0};
        
        for(int i=0;i<n1;i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        
        for(int cnt:freq){
            if(cnt!=0) return false;
        }
        return true;
    }