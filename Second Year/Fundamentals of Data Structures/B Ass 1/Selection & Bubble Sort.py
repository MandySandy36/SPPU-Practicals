def SelectionSort(arr,n):
    for i in range(n):
        Min = i
        for j in range(i+1,n):
            if(arr[j]<arr[Min]):
                Min = j
                temp=arr[i]
                arr[i]=arr[Min]
                arr[Min]=temp
    print(arr)

def BubbleSort(arr,n):
    i = 0
    for i in range(n-1):
        for i in range(0,n-i-1):
            if(arr[j] > arr[j+1]):
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    print(arr)

print("Top Five Scores are...")
for i in range (len(arr)-1,1,-1):
    print(arr[i])

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
    print("\n 1. Selection Sort")
    print("\n 2. Bubble Sort")
    print("\n 3. Exit")
    if(choice == 1):
        print("\n The sorted Scores are...")
        SelectionSort(array,n)
    elif(choice ==2):
        print("\n The sorted Scores are...")
        BubbleSort(array,n)
    else:
        print("Exitting")
        break