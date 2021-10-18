import java.util.*;
public class iterative_and_RecursiveFactorial
{
    	// iterative approach for finding factorial
    	public static int iterative_fact(int n){
        		int fact=1;
        		for(int i=1;i<=n;i++){
            			fact=fact*i;
        		}
        		return fact;
    	}	
    	// recursive approach for finding factorial 
    	public static int recursive_fact(int n){
        		if(n<0){
            			return -1;
        		}
        		else if(n==0 || n==1){
            			return 1;
        		}
        		else{
            			return n*recursive_fact(n-1);
        		}
    	}
	// main method
	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
	    System.out.println("Enter the number: ");
	    int n=sc.nextInt();
	    if(n>=0){
	        System.out.println("Factorial of "+n+" in iterative approach is "+iterative_fact(n));
	        System.out.println("Factorial of "+n+" in recursive approach is "+recursive_fact(n));
	    }
	    else
	        System.out.println("Factorial of negative numbers do not exist");
	}
}

/*
Example Output 1:

Enter the number: 
-2
Factorial of negative numbers do not exist

Example Output 2:

Enter the number: 
0
Factorial of 0 in iterative approach is 1
Factorial of 0 in recursive approach is 1

Example Output 3:

Enter the number: 
5
Factorial of 5 in iterative approach is 120
Factorial of 5 in recursive approach is 120

*/
