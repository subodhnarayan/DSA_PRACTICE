/*

Trapping Rain Water
Solved
Difficulty: HardAccuracy: 33.14%Submissions: 532K+Points: 8Average Time: 20m
Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Examples:

Input: arr[] = [3, 0, 1, 0, 4, 0, 2]
Output: 10
Explanation: Total water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units.

Input: arr[] = [3, 0, 2, 0, 4]
Output: 7
Explanation: Total water trapped = 0 + 3 + 1 + 3 + 0 = 7 units.
Input: arr[] = [1, 2, 3, 4]
Output: 0
Explanation: We cannot trap water as there is no height bound on both sides.
Input: arr[] = [2, 1, 5, 3, 1, 0, 4]
Output: 9
Explanation: Total water trapped = 0 + 1 + 0 + 1 + 3 + 4 + 0 = 9 units.
Constraints:
1 < arr.size() < 105
0 < arr[i] < 103

Expected Complexities
Company Tags
FlipkartAmazonMicrosoftGoogleGoldman SachsAdobe
Topic Tags
ArraysStacktwo-pointer-algorithm


*/



#include <bits/stdc++.h>
using namespace std;



int maxWater(vector<int> &arr) {
        
        
        //Brute Force Approach
        
        //TC=0(N) and SC=0(1)
        
        // int n=arr.size();
        // int sum=0;
        
        // for(int i=0;i<n;i++){
        //     int leftmax=0,rightmax=0;
            
        //     for(int j=0;j<=i;j++){
        //         leftmax=max(leftmax,arr[j]);
        //     }
            
        //     for(int k=i;k<n;k++){
        //         rightmax=max(rightmax,arr[k]);
        //     }
            
        //     sum+=(min(leftmax,rightmax)-arr[i]);
        // }
        
        // return sum;
        
        
        
        
        // code here
        //TC=0(2N) and Sc=O(1)
        
    //     int n=arr.size();   //7
        
    //     int maxheight=0;
    //     int maxindex=-1;   
        
    //     int sum=0;
        
    //     for(int i=0;i<n;i++){
    //         if(maxheight<arr[i]){
    //             maxindex=i;
    //             maxheight=arr[i];
    //         }
    //     }
        
    //   // maxindex=4
        
        
        
    //     //getting water from left
        
    //     int leftmaxheight=arr[0];
    //     for(int i=1;i<maxindex;i++){  // it will have from 1 to 3
            
    //         if(arr[i]>leftmaxheight){
    //             leftmaxheight=arr[i];
    //         }
    //         else{
    //         int height=leftmaxheight-arr[i];
    //         sum+=height;
    //         }
    //     }
        
    //     //getting water from right
        
    //     int rightmaxheight=arr[n-1];
    //     for(int i=n-2;i>maxindex;i--){
            
    //         if(rightmaxheight<arr[i]){
    //             rightmaxheight=arr[i];
    //         }
    //         else{
    //             int height=rightmaxheight-arr[i];
    //             sum+=height;
    //         }
    //     }
        
    //     return sum;
    
    
    //two pointer approach
    
    int left=0;
    int right=arr.size()-1;
    int leftmax=arr[left],rightmax=arr[right];
    
    int water=0;
    
    while(left<right){
        
        if(leftmax<rightmax){
            left++;
            leftmax=max(leftmax,arr[left]);
            water+=(leftmax-arr[left]);
        }
        else{
            right--;
            rightmax=max(rightmax,arr[right]);
            water+=(rightmax-arr[right]);
        }
        
    }
    
    return water;
        
    }