def f(s, x, y):
    res = 0
    save = ""
    for i in range(len(s)):
        for j in range(i+1, len(s)):
            a = s[i:j+1]
            if (a.count(x) and a.count(y)):
                if (res < a.count(y)-a.count(x) or (res == a.count(y)-a.count(x) and len(a) < len(save))):
                    save = a
                res = max(res, a.count(y)-a.count(x))

    return res, save


def sub(s,c1, c2):  # c2 > c1
    res = 0
    i = 0
    a = b = 0
    for j in range(len(s)):
        if(s[j] not in [c1,c2]): continue
        a += s[j] == c1
        b += s[j] == c2
        while (i < j and b-a < 0):
            a -= s[i] == c1
            b -= s[i] == c2
            i += 1
        while (a > 1 and i < j and s[i] != c2):
            a -= s[i] == c1
            i += 1
        if (a and b):
            res = max(b-a, res)
    return res


s = '''fsoxzotgvxguvudpgntfujuvrkgkfwqalayujcbryotoyslfwhhwfxgwrbitncjpvpowejsyboaeqhpvgkjxijisnrjbawpedhrlablukuhzxhlrclmbbszoloeqqfhguocowsadhxkkvxxupwxyvqdqcagxldmzsuvjqjedteoizobbmtlnzmllaxbysymnhactdqyhipvazsqpnwulnsguchspaycvtbzdnhzrjjlbjmtvhtrcqcutthlyjjrhyjilayiqsjusojpypnuspxfxvcffpiebmlfdoqebsiqtflsddoxmcpooqkkjkgsgenvpwszzhqbqbaognwgdswtmiishmwgiknqfixlzqgbcsmfbfupbzvzbxexrdcoilspuae'''

# for i in set(s):
#     for j in set(s):
print(f(s, 'f', 'j'))
s2 = 'jpvpowejsyboaeqhpvgkjxijisnrjbawpedhrlablukuhzxhlrclmbbszoloeqqfhguocowsadhxkkvxxupwxyvqdqcagxldmzsuvjqjedteoizobbmtlnzmllaxbysymnhactdqyhipvazsqpnwulnsguchspaycvtbzdnhzrjjlbjmtvhtrcqcutthlyjjrhyjilayiqsjusoj'
print(sub(s, 'f', 'j'))
print(s.index(s2),s.index(s2)+len(s2))
