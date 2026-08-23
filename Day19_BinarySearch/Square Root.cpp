/*
Square Root
Solved
Difficulty: EasyAccuracy: 54.03%Submissions: 390K+Points: 2Average Time: 20m
Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number.

Examples:

Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.
Input: n = 1
Output: 1
Explanation: 1 is a perfect square, so its square root is 1.
Constraints:

1 ≤ n ≤ 3*104
Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)



*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int start=1;
        int end=n;
        int sqrt=1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(mid*mid==n){
                return mid;
            }
            else if(mid*mid<n){
                sqrt=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            
        }
        return sqrt;
    }
};