// Time : O(n*(log n))
// Space : O(n)

import java.util.Arrays;

public class Main
{
	public static void main(String[] args) {
		int[] nums = {87,98,4,65,14,13,12,-34,-345,65,12,19,50,0,1};
		System.out.println(Arrays.toString(nums));
		mergeSort(nums);
		System.out.println(Arrays.toString(nums));
	}
	
	static void mergeSort(int[] arr) {
	    int size = arr.length;
	    int mid = size/2;
	    
	    // single element
	    if (size<2) return;
	    
	    // divide into two arrays
	    int[] left = new int[mid];
	    int[] right = new int[size-mid];
	    for (int i=0; i<mid; i++) {
	        left[i] = arr[i];
	    }
	    for (int i=mid; i<size; i++) {
	        right[i-mid] = arr[i];
	    }
	    
	    mergeSort(left);
	    mergeSort(right);
	    
	    merge(arr,left,right);
	}
	
	static void merge(int[] arr, int[] left, int[] right) {
	    int leftsize = left.length;
	    int rightsize = right.length;
	    
	    // compare and copy (merge) elements into original array
	    int i=0, j=0, k=0;
	    while (i<leftsize && j<rightsize) {
	        if (left[i]<=right[j]) {
	            arr[k++] = left[i++];
	        }else{
	            arr[k++] = right[j++];
	        }
	    }
	    while (i<leftsize) {
	        arr[k++] = left[i++];
	    }
	    while (j<rightsize) {
	        arr[k++] = right[j++];
	    }
	}
	
}
