///                    Sum of Two Number                 ////

1. Two Sum
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?



vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<1) return {-1,-1};
        //Brute Force Approach
        //TC=O(n2) and SC=O(1)
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         int sum=nums[i]+nums[j];
        //         if(sum==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {-1,-1};


        //optimized approach using hashmap
        //TC=0(n) and SC=0(n)

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end()){
                return {i,mp[rem]};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};

    }
