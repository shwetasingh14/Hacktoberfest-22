def bubbleSort(arr): 
    n = len(arr) 

    for i in range(n-1):   
        for j in range(0, n-i-1): 
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
    
    n2 = [arr[i] for i in range(len(arr))]     
    print(f"\nThe sorted array is: {n2}")


# Driver code to test above 
arr = [64, 34, 25, 12, 22, 11, 90] 
bubbleSort(arr)
