def anagram(a, b):
     
    # the sorted strings are checked
    if(sorted(a)== sorted(b)):
        print("The strings are anagrams.")
    else:
        print("The strings are not anagrams.")
         
# driver code 
a ="debit card"
b ="bad credit"
anagram(a, b)