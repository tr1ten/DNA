def solution(doc:str):
    ans = ""
    i = 0
    while i<len(doc):
        if doc[i]!='`':
            ans +=doc[i]
        else:
            i = i+1
            cur = ""
            while doc[i]!='`': 
                cur += doc[i]
                i+=1
            words = cur.split(" ")
            res = ""
            for x in words:
                if x[0].islower():
                    other = x.split("_")
                    now =  other[0]
                    for y in other[1:]:
                        now += y.capitalize()
                    res += now + " "
                else: res += x + " "
            ans += '`' + res.strip()+'`' 
        i+=1
    return ans

print(solution("Function `some_function` `short_arg very_long_argument` somefol `CONST` "))