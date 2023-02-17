def extended(a,b):
    if(b==0): return (1,0,a) # x`, y',gcd
    dash = extended(b,a%b)
    return (dash[1],dash[0]-(a//b)*dash[1],dash[2])

print(extended(34,24))