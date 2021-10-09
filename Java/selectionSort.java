import java.util.*;
public class selectionSort
{
	static void sort(int arr[])
	{
		int n = arr.length;
		// One by one move boundary of unsorted subarray
		for (int i = 0; i < n-1; i++)
		{
			// Find the minimum element in unsorted array
			int min_idx = i;
			for (int j = i+1; j < n; j++)
				if (arr[j] < arr[min_idx])
					min_idx = j;

			// Swap the found minimum element with the first
			// element
			int temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
		}
	}
	// Prints the array
	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter array size: ");
		int n=sc.nextInt();
		int arr[]=new int[n];
		System.out.println("Enter array elements: ");
		for(int i=0;i<n;i++){
			arr[i]=sc.nextInt();
		}
		sort(arr);
		System.out.println("Sorted array");
		printArray(arr);
	}
}
/*
Output:
Enter array size: 
5
Enter array elements: 
123 45 76 87 94
Sorted array: 
45 76 87 94 123 
*/