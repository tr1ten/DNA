# Online Python Compiler
# Use this online editor to run Python code online
# Write your code here
t = int(input())
for i in range(t):
	s = input()
	if s=="abc":
		print("YES")
		continue
	# abc 
	ls = list(s)
	f = False
	for j in range(3):
		for k in range(j+1,3):
			ls[j],ls[k] = ls[k],ls[j]
			if ls==['a','b','c']:
				f=True
			ls[j],ls[k] = ls[k],ls[j]
			
	if f==True: print("YES")
	else: print("NO")