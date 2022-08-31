import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;;
class Solution {
    public Node cloneGraph(Node node) {
        if(node==null) return null;
        HashMap<Integer,ArrayList<Integer>> hm = new HashMap<>();
        HashSet<Integer> visited = new HashSet<>();
        Queue<Node> pq = new LinkedBlockingQueue<>();
        pq.add(node);
        Node temp;
        while(!pq.isEmpty()){
            temp = pq.remove();
            visited.add(temp.val);
            hm.put(temp.val,new ArrayList<>());
            for(Node adj:temp.neighbors){
                hm.get(temp.val).add(adj.val);
                if(!visited.contains(adj.val)) pq.add(adj);
            }
        }
        int V = hm.size();
        Node[] a = new Node[V];
        for(int i=1;i<=V;i++){
            a[i-1] = new Node(i);
        }
        for(int i=1;i<=V;i++){
            temp = a[i-1];
            temp.neighbors = new ArrayList<Node>();
            for(int adj:hm.get(temp.val)){
                temp.neighbors.add(a[adj-1]);
            }
        }
        return a[0];

    }
}