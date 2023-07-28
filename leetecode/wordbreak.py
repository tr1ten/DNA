# magic
class Solution:
    def wordBreak(self, s: str, W: List[str]) -> List[str]:
        def trie(): return defaultdict(trie)
        tr = trie()
        for w in W:
            reduce(dict.__getitem__,w,tr)['#'] = True
        def rec(node,idx):
            if idx==len(s): return [""] if '#' in node else []
            res = []
            if '#' in node: 
                for x in rec(tr,idx):
                    res.append(' ' + x)
            if s[idx] in node:
                for x in rec(node[s[idx]],idx+1):
                    res.append(s[idx] + x)
            return res
        return rec(tr,0)

            