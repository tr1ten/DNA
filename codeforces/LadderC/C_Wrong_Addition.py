if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        a,b = input().split()
        p2 = len(b)-1
        s = ""
        flag = True
        res = ""
        for i in range(len(a)-1, -1, -1):
            if p2 < 0:
                flag = False
                break
            if a[i] > b[p2]:
                if p2 == 0 or b[p2-1] > '1':
                    flag = False
                    break
                res += str(10+int(b[p2]) - int(a[i]))
                p2 -= 2
            else:
                res += str((int(b[p2])-int('0'))-(int(a[i])-int('0')))
                p2 -= 1
        while p2 >= 0:
            res += b[p2]
            p2 -= 1
        while len(res) > 1 and res[-1] == '0':
            res = res[:-1]
        if not flag:
            print(-1)
        else:
            res = res[::-1]
            print(res)