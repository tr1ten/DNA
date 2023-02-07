def f2(n): return ((9**(n+1))-1)//8;
def ff(x,prev=10):
   x = str(x)
   if(not x): return 0;
   n = int(x[0]) 
   d = len(x)-1
   if(prev<n): n-=1
   ans =0;
   if(prev==10): 
       ans += f2(d)
       n -=1
   ans +=  (9**d)*(n)+(0 if prev==int(x[0]) else ff(x[1:],int(x[0])))
   return ans
x,y = map(int,input().split());
print(ff(y+1)-ff(x))