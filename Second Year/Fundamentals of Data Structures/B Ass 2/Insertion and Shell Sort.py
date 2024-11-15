def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j+1] = key
    print(arr)
    print("Top Five Scores are...")
    for i in range(len(array)-1,1,-1):
        print(array[i])

def shellsort(arr):
    gap=len(arr)//2
    while gap>0:
        j=gap
        while j<n:
            i=j-gap
            while i>=0:
                if arr[i+gap]>arr[i]:
                    break
                else:
                    arr[i+gap],arr[i]=arr[i],arr[i+gap]
                i=i-gap
            j+=1
        gap=gap//2
    print("Top Five Scores are...")
    for i in range(len(array)-1,1,-1):
        print(array[i])

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
while(True):
    print("Main Menu")
    print("\n 1. Insertion Sort")
    print("\n 2. Shell Sort")
    print("\n 3. Exit")
    print("\nEnter the choice no.:")
    choice=int(input())
    if(choice == 1):
        print("\n The sorted Scores are...")
        insertionSort(array)
    elif(choice ==2):
        print("\n The sorted Scores are...")
        shellsort(array)
    else:
        print("Exitting")
        break