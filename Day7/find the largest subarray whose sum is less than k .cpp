#include<bits/stdc++.h>
using namespace std;

int atMostSum(vector<int> arr, int k){
    int n=arr.size();
    int count=0;
   
    //Brute Force Approach
    //TC=0(n2) and SC=0(1)
    // for(int i=0;i<n;i++){
    //      int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=arr[j];
    //         if(sum<=k){
    //             count=max(count,j-i+1);
    //         }
    //     }
    // }
    // return count;


    //optimized approach using two pointer if all the intergers are positive

    int i=0;
    int sum=0;
    for(int j=0;j<n;j++){
        sum+=arr[j];
        while(sum>k && i<=j){
            sum-=arr[i];
            i++;
        }
        count=max(count,j-i+1);
    }
    return count;
}





int main() {
    vector<int> arr = { 1, 2, 1, 0, 1, 1, 0 };
    int k = 4;
    int res = atMostSum(arr, k);
    cout << res << endl;
    return 0;
}