def largestsubarray(arr,k):
    n=len(arr)
    max_len=0
    sum=0
    i=0

    #Brute Force Solution TC=0(n2) and SC=01(1)

    # for i in range(0,n):
    #    sum=0
    #     for j in range(i,n):
    #         sum+=arr[j]

    #         if(sum<k):
    #             max_len=max(max_len,j-i+1)


    #Optimized Approach using two pointer
    for j in range(0,n):
        sum+=arr[j]

        while sum>=k and i<=j:
            sum-=arr[i]
            i+=1

        max_len=max(max_len,j-i+1)

    return max_len











