
/*
Binary Search is a searching algorithm for finding an element's position in a sorted array.
Binary search can be implemented only on a sorted list of items.

Time Complexities
Best case: O(1)
Average case: O(Log n)
Worst case: O(Log n)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n, int key)
{
    int s=0; // start with 0, first element of the array
    int e=n-1; // end with n-1, last element of the array
    int mid;
    while(s<=e) // run the loop whenever the end is grater or equel to start
    {
        int mid= s+(e-s)/2; // To avoid overflow
        if(arr[mid]==key)
        {
            return mid;   
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return -1; // If the element is not found then return defult value -1
}
signed main() {
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
//Driver Code
int Arr[8]={1,5,8,4,6,11,0,2};
cout<<binarySearch(Arr,8,8);
return 0;
}
