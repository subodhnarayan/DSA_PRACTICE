 /*
Count pairs with given sum
Solved
Difficulty: MediumAccuracy: 50.11%Submissions: 67K+Points: 4Average Time: 15m
You are given an array arr[] and an integer target. You have to count all pairs in the array such that their sum is equal to the given target.

Examples:

Input: arr[] = [1, 5, 7, -1, 5], target = 6 
Output: 3
Explanation: Pairs with sum 6 are (1, 5), (7, -1) and (1, 5). 
Input: arr[] = [1, 1, 1, 1], target = 2 
Output: 6
Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).
Input: arr[] = [10, 12, 10, 15, -1], target = 125
Output: 0
Explanation: There is no pair with sum = target
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
0 ≤ target ≤ 104

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
Topic Tags
ArraysHashtwo-pointer-algorithm
Related Articles
Count Pairs With Given Sum


*/
#include <bits/stdc++.h>
using namespace std

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int n=arr.size();
        int sum=0;
        
        //Brute Force Approach
        //TC=0(n2) and Sc=0(1)
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if((arr[i]+arr[j])==target){
        //             sum++;
        //         }
        //     }
        // }
        // return sum;
        
        //optimized method
        //TC=0(n) and SC=0(n)
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int rem=target-arr[i];
            if(mp.find(rem)!=mp.end()){
                sum+=mp[rem];
            }
            mp[arr[i]]++;
        }
        return sum;
    }
};

