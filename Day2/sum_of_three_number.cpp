15. 3Sum
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        set<vector<int>> st;
        int n=nums.size();
        if (n < 3){return ans;}
        sort(nums.begin(),nums.end());
        // for(int i=0;i<n-2;i++){
        //     for (int j=i+1;j<n-1;j++){
        //         for(int k=j+1;k<n;k++){
        //             int sum=nums[i]+nums[j]+nums[k];
        //             if (sum==0){
        //                 vector<int> temp={nums[i],nums[j],nums[k]};
        //                 st.insert(temp);
        //             }
                
        //         }
        //     }
        // }
        // ans.assign(st.begin(),st.end());
        // return ans;
         

         //optimized way
         //TC=O(n2) and SC=0(0)

        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int start=i+1;
            int end=n-1;
            while(start<end){
                int rem=0-nums[i];
                int sum=nums[start]+nums[end];

                if(sum==rem){
                ans.push_back({nums[i],nums[start],nums[end]});
                start++;
                end--;
                while(start<end && nums[start]==nums[start-1]) start++;
                while(start<end && nums[end]==nums[end+1]) end--;
            }
            else if(sum>rem){
                end--;
            }
            else{
                start++;
            }
        }
        } 
    return ans;
    }
};