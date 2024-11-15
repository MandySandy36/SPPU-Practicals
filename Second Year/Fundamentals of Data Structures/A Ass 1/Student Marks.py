marks = []
x = int(input("Enter no of students : "))
for i in range(0, x):
    marks.append(float(input("Enter marks of students out of 100 : ")))
print(marks)

def avg():
    sum = 0
    for i in range(0, x):
        sum = sum + marks[i]
        avg = sum / x
    print("Average of score of Class : ", avg)
         
def Highest():
    max = -1
    for i in range(0, x):
        if marks[i] > max:
            max = marks[i]
    print("Highest marks scored : ", max)

def Lowest():
    min = 101
    for i in range(0, x):
        if marks[i] == -1:
            continue
        else:
            if marks[i] < min:
                min = marks[i]
    print("Lowest marks scored : ", min)

def absent():
    count = 0
    for i in range(0, x):
        if marks[i] == -1:
            count += 1
    print("total absent students are : ", count)

def frequency():
    max = 0
    high_freq = marks[0]
    for i in marks:
        freq = marks.count(i)
        if freq > max:
            max = freq
            high_freq = i
    print("Most frequent number is : " + str(high_freq))

avg()
Highest()
Lowest()
absent()
frequency()
