/* Problem Statement: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
*/

import java.util.Scanner;
class Main {
    public static int fib(int n) {
        //Base Condition
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int f[]=new int[n+1];
        //Assign starting elements -> 0,1
        f[0]=0;
        f[1]=1;
        //Run loop till n
        for(int i=2;i<=n;i++)
        {
            f[i]=f[i-1]+f[i-2];
        }
        //return the F(n) value
        return f[n];
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(fib(n));

    }
}

/* 
Test Case-1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Test Case-2:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

*/
