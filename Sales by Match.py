Sales by Match

'''
Question:

There is a large pile of socks that must be paired by color. Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.
 
Sample Input

STDIN                       Function
-----                       --------
9                           n = 9
10 20 20 10 10 30 50 10 20  ar = [10, 20, 20, 10, 10, 30, 50, 10, 20]


Sample Output:

3

'''


#code


import math
import os
import random
import re
import sys



def sockMerchant(n, ar):
    count=0
    s=set(ar)
    d={}
    for i in ar:
        if(i in d.keys()):
            d[i]+=1
        else:
            d[i]=1
            
    for i in d.keys():
        count+=d[i]//2
    return count
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
