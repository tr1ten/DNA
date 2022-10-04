
class FlattenedLL
{
    public class Node
    {   
	int data;
	Node next;
	Node bottom;
	
	Node(int d)
	{
		data = d;
		next = null;
		bottom = null;
	}
    @Override
    public String toString() {
        return "Node [data=" + data + "]";
    }
    }
    Node flatten(Node root)
    {
        if(root==null) return null;
        Node node = root;
        Node master=null;
        while(node!=null){
            Node dhead = new Node(0);
            Node temp = dhead;
            Node temp1 = master;
            Node temp2 = node;
            while(temp1!=null && temp2!=null){
                if(temp1.data<temp2.data){
                    temp.bottom = new Node(temp1.data);
                    temp1 = temp1.bottom;
                }
                else{
                    temp.bottom = new Node(temp2.data);
                    temp2 = temp2.bottom;    
                }
                temp = temp.bottom;
                
            }
            while(temp2!=null){
                temp.bottom = new Node(temp2.data);
                temp2 = temp2.bottom;
                temp = temp.bottom;
            }
            while(temp1!=null){
                temp.bottom = new Node(temp1.data);
                temp1 = temp1.bottom;
                temp = temp.bottom;
            }
            master = dhead.bottom;
            node = node.next;
        }
        return master;
    }
    public static void main(String[] args) {
        // test
        FlattenedLL ff = new FlattenedLL();
        Node root = ff.new Node(5);
        root.next = ff.new Node(7);
        root.next.next = ff.new Node(8);
        root.next.next.next = ff.new Node(30);
        root.bottom = ff.new Node(10);
        root.bottom.bottom = ff.new Node(20);
        root.bottom.bottom.bottom = ff.new Node(28);
        root.bottom.bottom.bottom.bottom = ff.new Node(35);
        root.next.bottom = ff.new Node(19);
        root.next.bottom.bottom = ff.new Node(22);
        root.next.bottom.bottom.bottom = ff.new Node(50);
        root.next.next.bottom = ff.new Node(40);
        root.next.next.bottom.bottom = ff.new Node(45);
        root.next.next.next.bottom = ff.new Node(60);
        root.next.next.next.bottom.bottom = ff.new Node(70);
        root.next.next.next.bottom.bottom.bottom = ff.new Node(80);
        root.next.next.next.bottom.bottom.bottom.bottom = ff.new Node(90);
        Node node= ff.flatten(root);
        while(node!=null){
            System.out.print(node.data+" ");
            node = node.bottom;
        }
    }
}
