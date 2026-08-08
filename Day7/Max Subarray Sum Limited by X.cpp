 /*
Max Subarray Sum Limited by X
Solved
Difficulty: EasyAccuracy: 43.78%Submissions: 18K+Points: 2
Given an array arr[] of integers and a number x, find the sum of subarray having a maximum sum less than or equal to the given value of x.

Examples:

Input: arr[] = [1, 2, 3, 4, 5], x = 11 
Output: 10
Explanation: Subarray having maximum sum is [1, 2, 3, 4].
Input: arr[] = [2, 4, 6, 8, 10], x = 7 
Output: 6
Explanation: Subarray having maximum sum is [2, 4] or [6].
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
1 ≤ x ≤ 109

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
Topic Tags
sliding-windowtwo-pointer-algorithmArrays

*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSum(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int ans=0;
        //Brute force Approach
        //TC=0(n) and SC=0(n)
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=arr[j];
        //         if(sum<=x)
        //         ans=max(ans,sum);
        //     }
        // }
        // if(ans==INT_MIN) return 0;
        // return ans;
        
        //optimal approach using two pointer
        int sum=0;
        int i=0;
        for(int j=0;j<n;j++){
            sum+=arr[j];
            while(sum>x){
                sum-=arr[i];
                i++;
            }
            ans=max(sum,ans);
        }
        return ans;
    }
};