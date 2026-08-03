 /*Pairs with difference k
Difficulty: Easy  Accuracy: 22.41%  Points: 2
Given an array arr[] of positive integers. Find the number of pairs of integers whose absolute difference equals to a given number k.
Note: (a, b) and (b, a) are considered the same. Also, the same numbers at different indices are considered different.

The answer is guaranteed to fit in a 32-bit integer.

Examples:

Input: arr[] = [1, 4, 1, 4, 5], k = 3
Output: 4
Explanation: There are 4 pairs with absolute difference 3, the pairs are {1, 4}, {1, 4}, {4, 1} and {1, 4}.
Input: arr[] = [8, 16, 12, 16, 4, 0], k = 4
Output: 5
Explanation: There are 5 pairs with absolute difference 4, the pairs are {8, 12}, {8, 4}, {16, 12}, {12, 16}, {4, 0}.
Constraints:
1 <= arr.size() <= 2*105
1 <= k <= 2*105
0 <= arr[i] <= 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
Company Tags
Adobe
Topic Tags
Arrays


 */

#include <bits/stdc++.h>
using namespace std;


int countPairs(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int count=0;
        
        //Brute force Approach
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(abs(arr[i]-arr[j])==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        //Optimized Approach
        
        // unordered_map<int,int> mp;
        // for(int i=0;i<n;i++){
        //     int rem1=(arr[i]-k);
        //     int rem2=(arr[i]+k);
        //     if(mp.find(rem1)!=mp.end()){
        //         count+=mp[rem1];
        //     }
        //     if(mp.find(rem2)!=mp.end()){
        //         count+=mp[rem2];
        //     }
        //     mp[arr[i]]++;
            
        // }
        // return count;
        
       unordered_map<int,int> mp;
        for(int x:arr) mp[x]++;
        
        for(int x:arr){
            if(mp.count(x+k)){
                count+=mp[x+k];
            }
        }
        return count;
    }


    

