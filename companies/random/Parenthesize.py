def solve(s:str):
    if not s: return ""
    if 'and' not in s:
        if 'or' not in s: return s.strip()
        sp = s.split('or')
        ans = sp[0].strip()
        for i in range(1,len(sp)):
            ans = '(' + ans + ' or ' + sp[i].strip() + ')';
        return ans.strip()
    else:
        sp = s.split('and')
        ans = solve(sp[0])
        for i in range(1,len(sp)):
            ans += ' and ' + solve(sp[i])
        return ans.strip()

s1 = '"C++" or "C" and "HTML"';
s2 = '"C++ or C" or  "HTML" and "AWC"';
s3 = '"C++ or C" and "HTML" or "AWC"';

print(solve(s1))
print(solve(s2))
print(solve(s3))

