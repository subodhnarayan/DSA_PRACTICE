// Number of subarrays whose sum <= K

#include<bits/stdc++.h>
using namespace std;


int twopointerbruteforce(vector<int> arr,int k){

    //TC=O(n2) and SC=0(n)
    int n=arr.size();
    int sum=0;
    int count=0;
    //vector<int> arr={2,1,1,5,8};
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
          sum+=arr[j];
          if(sum<=k){
            count++;
          }

        }
         
    }
    return count;
}




int twopointer(vector<int> arr,int k){

    //TC=O(2n)=(n) and SC=o(n)
    int n=arr.size();
    int i=0;
    int sum=0;
    int count=0;
    for(int j=0;j<n;j++){
        sum+=arr[j];
        while(sum>k){
            sum-=arr[i];
            i++;
        }
       count+=(j-i+1);    //check the length
    }
    return count;
}

int main(){
    // int n;
    // cin>>n;
    // int k;
    // cin>>k;
    vector<int> arr={2,1,1,5,8};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    cout<<twopointer(arr,4);
    cout<<"\n";
    cout<<twopointerbruteforce(arr,4);
}
