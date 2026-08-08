#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> & arr,int start,int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}


int getScoreDifferent(vector<int> arr, int n){
    //    int first_play=0;
    //    int second_play=0;
    //    for (int i=0;i<n;i++){
    //     if(i%2==0){
    //         first_play+=arr[i];
    //     }
    //     else{
    //         second_play+=arr[i];
    //     }
    //      if(arr[i]%2==0 && i<n-1){
    //             reverse(arr,i+1,n-1);
    //     }
    //    }
    //    return first_play-second_play;


    //optmized approach using two pointer
    //TC=0(n) and SC-0(1)

    int turn=1;
    int first_sum=0;
    int second_sum=0;
    int start=0,end=n-1;

    bool reverse=false;
    int selected=0;
    while(start<=end){
        if(turn%2==1){

            if(reverse==false){
           first_sum+=arr[start]; selected=arr[start]; start++;
            }
            else{
                first_sum+=arr[end]; selected=arr[end]; end--;
            }
        }
        else{
             if(reverse==false){
           second_sum+=arr[start]; selected=arr[start]; start++;
            }
            else{
                second_sum+=arr[end]; selected=arr[end]; end--;
            }
        }

        if(selected%2==0){
            if(reverse==false){
                reverse=true;
            }
            else{
             reverse=false;
            }
        }
        turn++;
    }
    return first_sum-second_sum;
}


int main(){
    vector<int> arr = {3, 6, 2, 3, 5};
    int n = arr.size();
    cout << "Score Difference: " << getScoreDifferent(arr, n) << endl;
    return 0;
}