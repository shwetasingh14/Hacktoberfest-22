# Most Optimised Sorting Algorithm

def merge_sort(arr):
    if len(arr) > 1:
        #defining 2 subarrays
        left_arr = arr[: len(arr)//2]  
        right_arr = arr[len(arr)//2:]

        #recursion on left & right arr
        merge_sort(left_arr)
        merge_sort(right_arr)

        #merging - remember to compare leftmost elem of 1 arr to leftmost elem of another arr
        i = 0 #pointer for left arr
        j = 0 #pointer for right arr
        k = 0 #merge arr pointer

        while i < len(left_arr) and j < len(right_arr):
            if left_arr[i] < right_arr[j]:
                arr[k] = left_arr[i]
                i +=1
            else:
                arr[k] = right_arr[j]
                j+=1
            k+=1

        while i<len(left_arr):
            arr[k] = left_arr[i]
            i+=1
            k+=1

        while j<len(right_arr):
            arr[k] = right_arr[j]
            j +=1
            k+=1

arr = [2,4,7,1,2,9,6,3,7,9,2]
merge_sort(arr)
print("Sorted Array : " ,arr)
