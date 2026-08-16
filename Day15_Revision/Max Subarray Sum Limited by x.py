class Solution:
    def maxSum(self, arr, x):
        # code here
        max_sum=0
        n=len(arr)
        
        #Brute Force   TC=0(n2) and SC=0(1)
        # for i in range(0,n):
        #     sum=0
        #     for j in range(i,n):
        #         sum+=arr[j]
                
        #         if sum<=x:
        #             max_sum=max(max_sum,sum)
                    
        
        # return max_sum
        
        #optimized approach
        #TC=0(n) and SC=0(1)
        sum=0
        i=0
        for j in range(0,n):
            sum+=arr[j]
            
            while sum>x:
                sum-=arr[i]
                i+=1
                
            max_sum=max(max_sum,sum)
            
            
        return max_sum
                