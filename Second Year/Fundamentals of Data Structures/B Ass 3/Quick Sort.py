def Quick(arr,low,high):
    if(low<high):
        m=Partition(arr, low,high)
        Quick(arr,low,m-1)
        Quick (arr,m+1,high)

def Partition(arr,low,high):
    pivot = arr[low]
    i=low+1
    j=high
    flag = False 
    while(not flag):
        while(i<=j and arr[i] <=pivot):
            i = i + 1
        while ( i <= j and arr[i]>=pivot):
            j = j - 1
        if(j < i):
            flag = True
        else:
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
        temp = arr[low]
        arr[low] = arr[j]
        arr[j] = temp
    return j

#Driver Code

print("\nHow many students are there?")
n = int(input())
array = []
i=0
for i in range(n):
    print("\n Enter percentage marks")
    item = float(input())
    array.append(item)
print("You have entered following scores...\n")
print(array)
print("\n The sorted Scores are...")
Quick (array,0,n-1)
print(array)
print("Top Five Scores are...")
for i in range (len(array)-1,1,-1):
    print(array[i])