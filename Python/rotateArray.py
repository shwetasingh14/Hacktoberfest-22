def rotateArray(arr,n,d):
  tempArray=[]
  i=0
  while (i<d):
    tempArray.append(arr[i])
    i=i+1
  i=0
  while (n>d):
    arr[i]=arr[d]
    i=i+1
    d=d+1
  arr[:]=arr[:i]+tempArray
  return arr


arr=[1,2,3,4,5,6,7]
rotateArray(arr,len(arr),2)