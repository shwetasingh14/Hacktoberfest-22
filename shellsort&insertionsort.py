class sort:
    def shellsort(self,array):
        gap=len(array)
        while gap>0:
            i=0
            j=gap
            while j < len(array):
                if array[i]>array[j]:
                    array[i],array[j]=array[j],array[i]
                
                i=i+ 1
                j=j+ 1
                
                k=i
                while k-gap>-1:
                    if array[k-gap]>array[k]:
                        array[k-gap],array[i]=array[k],array[k-gap]
                    k=k-1
            gap//=2
        
    
    
    def insertionsort(self,array):
        for i in range(1,len(array)):
            key=array[i]
            j=i-1
            while j>=0 and key<array[j]:
                array[j+1]=array[j]
                j=j-1
            array[j+1]=key
    
    def addmarks(self,array):
        array=[]
        n1=int(input("total no of students: "))
        for i in range(n1):
            print("student ",i+1," percentage: ")
            marks=float(input())
            array.append(marks)
            
s=sort()
percen=[]
percentage=[]
n=int(input("total no of students: "))
for i in range(n):
    print("student ",i+1," percentage: ")
    marks=float(input())
    if(marks>100):
        print("Percentage can't be greater than 100")
        print("student ",i+1," percentage: ")
        marks=float(input())
    
    percentage.append(marks)
print("----------------------------------------------------------------")
print("Percentage of students->",percentage)
print("-----------------------------------------------------------------")
while True:
    print("1) Insertion sort")
    print("2) Shell sort")
    print("3) Add marks")
    choice=int(input("Enter your choice: "))
    if(choice==1):
        
        s.insertionsort(percentage)
        print("Sorted order ",percentage)
        print("Top 5 score ",percentage[n:n-6:-1])
        print("------------------------------------------------------------------")
    elif(choice==2):
        s.shellsort(percentage)
        print("Sorted order ",percentage)
        print("Top 5 score ",percentage[n:n-6:-1])
        print("-------------------------------------------------------------------")
    elif(choice==3):
        percen=[]
        s.addmarks(percen)
        print(percen)
       
        print("-------------------------------------------------------------------")
    else:
        exit()