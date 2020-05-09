from sys import stdin

sum = 0
n = int(input())

for i in range(0, n):
	num = int(stdin.read(1))
	sum += num
	print(sum)
