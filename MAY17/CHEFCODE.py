n, k = map(int, input().strip().split())
a = list(map(int, input().strip().split()))
a_ = a[:]
count = 0
while True:
	b = []
	for i in a_:
		for j in a:
			if i*j <=k:
				b.append(i*j)
				count+=1
