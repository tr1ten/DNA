x1,y1,x2,y2 = map(int,input().split())
x11,y11,x22,y22 = map(int,input().split())
if (x1<=x11<=x2 and y2<=y11<=y1) or (x1<=x22<=x2 and y2<=y22<=y1):
    print("overlap")
else: print("no overlap")