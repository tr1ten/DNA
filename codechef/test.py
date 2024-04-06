from itertools import permutations
def check(digits:str):
    st = set()
    for x in permutations(digits):
        num = "".join(x)
        if num[0]!='0': st.add(int(num)**2)
    print(*st)
        
check("13000")
    