def countsubarray(arr,k):
    n=len(arr)
    sum=0
    count=0
    i=0

    #Brute Force Approch

    #TC=0(n2) and SC=(n)

    # for i in range(0,n):
    #     sum=0
    #     for j in range(i,n):
    #         sum+=arr[j]

    #         if sum<=k:
    #             count+=1


    for j in range(0,n):
        sum+=arr[j]
        # Shrink window if sum exceeds k, but don't let i pass j
        while sum>k and i<=j:
            sum-=arr[i]
            i+=1

        # Count all valid subarrays ending at index j
        count+=(j-i+1)       # This will the overal count of the subarray after adding that number



    return count



    






