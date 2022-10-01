
/*
Binary Search is a searching algorithm for finding an element's position in a sorted array.
Binary search can be implemented only on a sorted list of items.

Time Complexities
Best case: O(1)
Average case: O(Log n)
Worst case: O(Log n)

Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

int main()
{
    int n=6;
    int nums[] = {-1,0,3,5,9,12};
    int l=0, r=n-1, f=0;
    int target = 9;
        
        while(l<=r){
            //find mid
            int m = l + (r-l)/2;
            
            //Element find in the array
            if(nums[m]==target){
                cout << "Element find index at:" << m;
                f=1;
                break;
            }
            
            //if arr[mid]>target then search in left side array  
            else if(nums[m]>target)
                r=m-1;
            
            //if arr[mid]<target then search in right side array     
            else
                l=m+1;
        }
    
    if(f==0){
        cout << "Element not found";
    }
    
    return 0;
}
