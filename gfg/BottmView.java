
class Solution
{
    class Pair{
        Node node;
        int line;
        Pair(Node node,int l){
            this.node = node;
            this.line =l;
        }
    }
    //Function to return a list containing the bottom view of the given tree.
    public ArrayList <Integer> bottomView(Node root)
    {
        HashMap<Integer,Integer> hm =new HashMap<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root,0));
        while(!q.isEmpty()){
            Pair p = q.remove();
            hm.put(p.line,p.node.data);
            if(p.node.left!=null) q.add(new Pair(p.node.left,p.line-1));
            if(p.node.right!=null) q.add(new Pair(p.node.right,p.line+1));
        }
        List<Integer> sortedKeys = new ArrayList<Integer>(hm.keySet());
        Collections.sort(sortedKeys);
        ArrayList<Integer> res = new ArrayList<>(); 
        for(int k:sortedKeys){
            res.add(hm.get(k));
        }
        return res;
    }
}