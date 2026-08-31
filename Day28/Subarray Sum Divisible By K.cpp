/*

Subarray Sum Divisible By K
Difficulty: Medium
You are given an integer array arr[] and a value k. The task is to find the count of all sub-arrays whose sum is divisible by k.





*/


Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)



class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    int subCount(vector<int>& arr, int k) {
        // Your code goes here
        int n=arr.size();
        int count=0;
        
        
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=arr[j];
        //         if(sum%k==0){
        //             count++;
        //         }
        //     }
        // }
        
        unordered_map<int,int> prefixsum;
        long long sum=0;
        prefixsum[0] = 1; // Represents an initial sum of 0 before array processing
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            
            int rem=sum%k;
            
            if(rem<0){
                rem+=k;
            }
            
            if(prefixsum.find(rem)!=prefixsum.end()){
                count+=prefixsum[rem];
            }
            
            prefixsum[rem]++;
            
        }
        
        
        return count;
    }
};
