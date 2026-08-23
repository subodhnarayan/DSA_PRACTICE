/*

Peak element
Solved
Difficulty: Medium
You are given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist).

If there are multiple peak elements, Return index of any one of them. The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".

Note: Consider the element before the first element and the element after the last element to be negative infinity.

Examples :

Input: arr = [1, 2, 4, 5, 7, 8, 3]
Output: true
Explanation: arr[5] = 8 is a peak element because arr[4] < arr[5] > arr[6].
Input: arr = [10, 20, 15, 2, 23, 90, 80]
Output: true
Explanation: Element 20 at index 1 is a peak since 10 < 20 > 15. Index 5 (value 90) is also a peak, but returning any one peak index is valid.
Constraints:
1 ≤ arr.size() ≤ 106
-231 ≤ arr[i] ≤ 231 - 1

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)

*/

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        
        //Brute force
        
        // for(int i=1;i<n-1;i++){
        //     if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
        //         return true;
        //     }
        // }
        
        //Optimized Approach using Binary Search
        //TC=O(logn)  and SC=0(1)
        
        
        int start=0;
        int end=n-1;
        while(start<end){
           int mid=start+(end-start)/2;
           
           if(arr[mid]>arr[mid+1]){   //go and keep checking in right side
               end=mid;
           }
           else{         //check in left side
               start=mid+1;
           }
           
        }
        
        return end;
        
    }
};