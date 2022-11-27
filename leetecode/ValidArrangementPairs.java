class Solution {
    HashMap<Integer, Stack<Integer>> adj;
    ArrayList<int[]> res;
    void dfs(int u){
        if(adj.get(u)==null) return;
        Stack<Integer> st = adj.get(u);
        while(!st.isEmpty()){
            int v = st.pop();
            res.add(new int[]{u,v});
            dfs(v);
        }
    }
    public int[][] validArrangement(int[][] pairs) {
         adj = new HashMap<>();
        HashMap<Integer,Integer> ind = new HashMap<>();
        HashMap<Integer,Integer> outd = new HashMap<>();
        res = new ArrayList<>();
        for(int[] ed:pairs){
            int u=ed[0],v=ed[1];
            if(!adj.containsKey(u)) adj.put(u,new Stack<>());
            adj.get(u).push(v);
            ind.put(u,ind.getOrDefault(u,0));
            ind.put(v,ind.getOrDefault(v,0)+1);
            outd.put(u,outd.getOrDefault(u,0)+1);
            outd.put(v,outd.getOrDefault(v,0));
            
        }
        int u =-1;
        for(int key:ind.keySet()){
            if(outd.get(key)-ind.get(key)==1){
                    u = key;
                    break;
            }
            u = key;
        }
        dfs(u);
        return res.toArray(new int[pairs.length][2]);
        
        
    }
}