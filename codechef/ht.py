n = 12310
buf = []
save = []
for i in range(1,10*n):
    buf.append((i*(i+1)//2)%n)
    if i%(n if n%2 else 2*n)==0:
        if save: 
            print(buf==save)
        else: save = buf
        buf = []
    
    # print((i*(i+1)//2)%n,end=" ")
print()