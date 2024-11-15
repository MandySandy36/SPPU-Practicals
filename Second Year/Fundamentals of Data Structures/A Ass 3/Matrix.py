A=[]
B=[]
r=int(input("Enter no. of rows="))
c=int(input("Enter no. of columns="))
def getdata1():
	print("For matrix A:")
	print("Enter elements row wise")	
	for i in range(r):
		a=[]
		for j in range(c):
			a.append(int(input()))
		A.append(a)

def getdata2():
	print("For matrix B:")
	print("Enter elements row wise")	
	for i in range(r):
		b=[]
		for j in range(c):
			b.append(int(input()))
		B.append(b)
	print("Matrix B=",B)


def add_mat():
	a=[]
	for i in range(r):
		b=[]
		for j in range(c):
			d=A[i][j]+B[i][j]	
			b.append(d)
		a.append(b)
	print("C=A+B=",a)

def sub_mat():
	a=[]
	for i in range(r):
		b=[]
		for j in range(c):
			d=A[i][j]-B[i][j]	
			b.append(d)
		a.append(b)
	print("C=A-B=",a)

def mul_mat():
	a=[]
	for i in range(r):
		C=[]
		for j in range(r):
			c=0
			for k in range(r):
				c+=A[i][k]*B[k][j]	
			C.append(c)
		a.append(C)
	print("C=A*B=",a)
	
def trans(matrix):
        c=[]
        for i in range(len(matrix[0])):
                d=[]
                for j in range(len(matrix)):
                       d.append(matrix[j][i])
                c.append(d)
        print("Transpose of given matrix is:",c)



getdata1()
print("Matrix A=",A)
getdata2()
print("Matrix B=",B)
add_mat()
sub_mat()
mul_mat()
print("hence for matrix A:")
trans(A)
print("hence for matrix B:")
trans(B)