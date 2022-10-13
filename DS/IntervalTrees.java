package DS;

public class IntervalTrees {
    class IntervalNode{
        int start;
        int end;
        IntervalNode left;
        IntervalNode right;
        IntervalNode(int s,int e){
            this.start = s;
            this.end = e;
        }
        IntervalNode(int s,int e,IntervalNode l,IntervalNode r){
            this(s, e);
            left = l;
            right = r;
        }
    }
    IntervalNode root;
    IntervalTrees(){
        this.root = null;
    }
    private IntervalNode _recAdd(IntervalNode node,int start,int end){
        if(node==null) return new IntervalNode(start,end);
        if(node.start>=end) node.left = _recAdd(node.left, start, end);
        if(node.end<=start) node.right = _recAdd(node.right, start, end);
        return node;
    }
    public void add(int start,int end){
        this.root = _recAdd(root, start, end);
    }
    private boolean _recIn(IntervalNode node,int start,int end){
        if(node==null) return false;
        if(node.start>=end) return _recIn(node.left, start, end);
        if(node.end<=start) return _recIn(node.right, start, end);
        return true;
    }
    public boolean intersect(int start,int end){
        return _recIn(root, start, end);
    }
    public static void main(String[] args) {
        IntervalTrees it = new IntervalTrees();
        it.add(1, 3);
        it.add(2, 4);
        it.add(5, 7);
        it.add(6, 8);
        System.out.println(it.intersect(0, 9));
        System.out.println(it.intersect(3, 4));
        System.out.println(it.intersect(4, 5));
        System.out.println(it.intersect(4, 6));
        System.out.println(it.intersect(6, 8));
        System.out.println(it.intersect(7, 10));

    }
}
