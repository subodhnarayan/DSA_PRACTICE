#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

// Function to find the minimum length of a subarray with a sum EXACTLY equal to the target
int minSubArrayLenExact(int target, vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> prefixsum_mp;
    
    // Base case: handles subarrays that start exactly at index 0
    prefixsum_mp[0] = -1; 
    
    int small = INT_MAX;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        int rem = sum - target;
        
        // If the remainder exists, we found a matching subarray
        if (prefixsum_mp.find(rem) != prefixsum_mp.end()) {
            small = min(small, i - prefixsum_mp[rem]);
        }
        
        // Store the prefix sum with its index
        prefixsum_mp[sum] = i;
    }
    
    // Return 0 if no valid subarray was found
    return (small == INT_MAX) ? 0 : small;
}

int main() {
    // Test Case 1: Subarray [2, 3] at the end equals 5. Smallest length should be 2.
    vector<int> nums1 = {1, 4, 2, 3};
    int target1 = 5;
    cout << "Test 1 Result: " << minSubArrayLenExact(target1, nums1) << " (Expected: 2)" << endl;

    // Test Case 2: The very first element equals the target. Smallest length should be 1.
    vector<int> nums2 = {7, 1, 2, 3};
    int target2 = 7;
    cout << "Test 2 Result: " << minSubArrayLenExact(target2, nums2) << " (Expected: 1)" << endl;

    // Test Case 3: Target cannot be formed exactly. Should return 0.
    vector<int> nums3 = {1, 2, 3};
    int target3 = 10;
    cout << "Test 3 Result: " << minSubArrayLenExact(target3, nums3) << " (Expected: 0)" << endl;

    // Test Case 4: Multiple matches ([1, 2, 3] len 3 vs [6] len 1). Should pick the shortest (1).
    vector<int> nums4 = {1, 2, 3, 0, 6};
    int target4 = 6;
    cout << "Test 4 Result: " << minSubArrayLenExact(target4, nums4) << " (Expected: 1)" << endl;

    return 0;
}
