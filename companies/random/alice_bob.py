def solve(A):
    st = []
    for x in A:
        if not st or st[-1]!=x: st.append(x)
        else: st.pop()
    return "Alice" if ((len(A)-len(st)))%4!=0  else "Bob"

print(solve([1,3,3,1,5]))
print(solve([1,4,5,5,6]))
