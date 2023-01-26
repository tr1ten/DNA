from sys import stdin,setrecursionlimit
setrecursionlimit(10**7)
def kThCharaterOfDecryptedString(s, k) :

	# Your code goes here
    cur = 0
    cnt = 0
    while(cur<k):
        i = cur
        while(i<len(s) and not s[i].isdigit()):
            i+=1
        j = i
        res = ""
        while(i<len(s) and s[i].isdigit()):
            res += s[i]
            i+=1
        prev = cnt
        cnt +=int(res)*(j-cur)
        if(k<=cnt): return s[cur + (k-prev-1)%(j-cur)];
        cur = i
    return "fk"

print(kThCharaterOfDecryptedString("dajidas988ksajlkdn908",9000))