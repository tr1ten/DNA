def f(x):
    for i in range(1,x+2):
        if(x%i!=0): return i
for i in range(1,1000): print((i,f(i)),end=" ")