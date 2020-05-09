
global zcnt 
global ocnt

def fibo(n):
	global zcnt 
	global ocnt 
	if n == 0:
		zcnt += 1
		return 0
	elif n == 1:
		ocnt += 1
		return 1
	else:
		return fibo(n-1) + fibo(n-2)
	

t = int(input())
for i in range(0, t):
	zcnt = 0
	ocnt = 0
	n = int(input())
	fibo(n)
	print(zcnt, ocnt)
