def countsubarray(arr,k):
    n=len(arr)
    sum=0
    count=0

    #Brute Force Approch

    #TC=0(n2) and SC=(n)

    for i in range(0,n):
        for j in range(i,n):
            sum+=arr[j]

            if sum<=k:
                count+=1



    






