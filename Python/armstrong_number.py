#armstrong number
#user input
number=input("Enter the number :- ")
#storing the order of number in n
n=len(str(number))

sum=0
#changing the data type to int so that we can use it in looping
number=int(number)
int_num =int(number)

while int_num > 0 : 
    l_digit=int_num%10
    sum =sum + l_digit**n
    int_num//=10 
 
if number==sum:
    print(number,"is an Armstrong Number")
else:
    print(number,"is not an Armstrong Number")
    
    
'''
Output: 
Enter the number :- 153
153 is an Armstrong Number

Enter the number :- 351
351 is not an Armstrong Number
'''
