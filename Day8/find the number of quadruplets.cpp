// Problem :-> Given a sorted array of size N; find the number of quadruplets (i,j,k,l) such that -> a[i] + a[j] > k1 && a[k] + a[l] > k2  

// -> Will i < j < k < l -> Yes; 

// -> What is the nature of numbers in the array -> Both positive / negative ; 

// -> Bound on array elements and k1,k2 -> abs(a[i],k1,k2)<=100000000;

// Input -> [1,1,1,1,2,2] k1=1 k2 = 3;
// -> 6 [1,2,5,6],[2,3,5,6],[3,4,5,6],[1,4,5,6],[1,3,5,6],[2,4,5,6];



#include<bits/stdc++.h>
using namespace std;


// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int countPairsGreatherThan(vector<int> arr,int start,int end,int tar){
    int k=start;
    int l=end;
    int c=0;
    while(k<l){
        if(arr[k]+arr[l]>tar){
            c+=l-k;
            l--;
        }
        else{
            k++;
        }
    }
    return c;
}

int main() {
   int n = 6;
    int k1 = 5, k2 = 8;
    vector<int> arr = {1, 2, 4, 5, 7, 9};
    int count = 0 ;
    
    for(int j=1;j<n-2;j++){
        int i=0;
        int count1=0;
        while(i<j){
            if(arr[i]+arr[j]>k1){
                count1++;
            }
            i++;
        }
        
        if (count1>0){
            int count2=countPairsGreatherThan(arr,j+1,n-1,k2);
            count+=count1*count2;
        }
    }
    cout<<count;
    
    return 0;
}