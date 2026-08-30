/*
Count Sum Pairs in Sorted
Solved
Difficulty: Easy
You are given an integer target and an array arr[]. You need to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.

Note:  Pairs should have elements of distinct indexes. 

Examples :

Input: arr[] = [-1, 1, 5, 5, 7], target = 6
Output: 3
Explanation: There are 3 pairs which sum up to 6 : {1, 5}, {1, 5} and {-1, 7}.
Input: arr[] = [1, 1, 1, 1], target = 2
Output: 6
Explanation: There are 6 pairs which sum up to 2 : {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1} and {1, 1}.
Input: arr[] = [-1, 10, 10, 12, 15], target = 125
Output: 0
Explanation: There is no such pair which sums up to 125.
Constraints:
-105 <= target <=105
 2 <= arr.size() <= 105
-105 <= arr[i] <= 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code Here
        unordered_map<int,int> mp;
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            int rem=target-arr[i];
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[arr[i]]++;
        }
        return count;
        
    }
};