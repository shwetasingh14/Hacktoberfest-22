//https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
public class Reversearray{
    public static void main(String args[]){
        //Intializing the original array
        int arr[] = new int [] {1,3,6,9,4,2};
        System.out.println("Original Array:");
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
        System.out.println("Array in reverse:");
        for(int i=arr.length-1;i>=0;i--){
            System.out.print(arr[i]+" ");
        }
    }
}

//other method to reverse array

/*
int length = array.length;
		for(int i=0;i<length/2;i++) {
			int swap = array[i];
			array[i] = array[length-i-1];
			array[length-i-1] = swap;
		}
or
Collections.reverse(Arrays.asList(array)); 
for(int i=intArray.length-1;i>=0;i--)
         System.out.print(intArray[i] + "  ");
 */
