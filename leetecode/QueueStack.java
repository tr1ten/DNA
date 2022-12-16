class MyQueue {
    Stack<Integer> mst;
    Stack<Integer> other;
    static Stack<Integer> temp;
    int ptr; //no need of this, why somebody would do this?
    static{
        temp = new Stack<>();
    }
    public MyQueue() {
      mst = new Stack<>();
      other = new Stack<>();
    }
    public void push(int x) {
        if(mst.size()-ptr==0 && other.isEmpty()){
            mst.push(x);
            other.push(x);
        }
        else{
            mst.push(x);
        }
    }
    public int pop() {
        ptr++;
        int ret = other.pop();
        if(!other.isEmpty()){ // not dirty state
            return ret;
        }
        // dirty need O(N)
        while(mst.size()>ptr){
            int v = mst.pop();
            temp.push(v);
            other.push(v);
        }
        while(!temp.isEmpty()) mst.push(temp.pop());
        return ret;
    }
    
    public int peek() {
        return other.peek();
    }
    
    public boolean empty() {
        return mst.size()-ptr==0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */