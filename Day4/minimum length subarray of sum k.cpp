#include <bits/stdc++.h> // Includes all STL libraries at once
using namespace std;
vector<int> minSubarray(vector<int> arr, int n, int x)
{
     unordered_map<int,int> prefixsum_mp;
     int first=-1;
     int last=-1;
     prefixsum_mp[0]=-1;
     int sum=0;
     int small=INT_MAX;
    for(int i =0;i<n;i++){
            sum+=arr[i];
            int rem=sum-x;
            if(prefixsum_mp.find(rem)!=prefixsum_mp.end()){
            int len = i - prefixsum_mp[rem];
            if (len < small) {
            small = len;
            first = prefixsum_mp[rem] + 1;
            last = i;
            }
            }
            prefixsum_mp[sum]=i;
        }
        if(small==INT_MAX) return {};

        vector<int> ans;
        for(int i=first;i<=last;i++){
            ans.push_back(arr[i]);
        }
        return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> result = minSubarray(arr, arr.size(), 7); // 3 + 4 = 7
    
    for(int num : result) {
        cout << num << " "; // Output: 3 4
    }
    return 0;
}

