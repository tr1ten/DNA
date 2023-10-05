def k_boyee(A,k): # floor(n/k)<
    if k==1: return [A[0]] if A.count(A[0])==len(A) else []
    cands=[float('inf')]*(k-1)
    cnts=[0]*(k-1)
    for x in A:
        if x in cands: cnts[cands.index(x)] +=1
        elif 0 in cnts: 
            cands[cnts.index(0)] = x
            cnts[cnts.index(0)] +=1
        else: cnts = [x-1 for x in cnts]
    ckc = Counter()
    for x in A:
        if x in cands: ckc[x]+=1
    return [x for  x in ckc if ckc[x]>len(A)//k]