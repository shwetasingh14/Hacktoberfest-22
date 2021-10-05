import numpy as np
import random
from numpy.random.mtrand import rand

# Array Initialization
row = int(input("Enter no. of rows: "))
col = int(input("Enter no. of columns: "))

array1 = np.zeros((row,col))
array2 = np.zeros((row,col))

# Fill arrays with random values
for i in range(row):
    for j in range(col):
        array1[i][j] = random.randint(1,100)
        array2[i][j] = random.randint(1,100)

print("\nMatrix 1:")
print(array1)
print("\nMatrix 2:")
print(array2)

# Sum of Matrices
result_arr = np.zeros((row,col))
for i in range(row):
    for j in range(col):
        result_arr[i][j] = array1[i][j] + array2[i][j] 

print("\nSum of both matrices: ")
print(result_arr)

# Transpose of resultant matrix
transpose_arr = np.zeros((col,row))
for i in range(col):
    for j in range(row):
        transpose_arr[i][j]=result_arr[j][i]

print("\nTranspose of the resultant matrix: ")
print(transpose_arr)
print("\n")
