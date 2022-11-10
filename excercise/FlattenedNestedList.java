/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    public List<Integer> ls;
    void dfs(NestedInteger ni){
        if(ni.isInteger()) ls.add(ni.getInteger());
        else{
            for(NestedInteger ns:ni.getList()){
                dfs(ns);
            }
        }
    }
    public NestedIterator(List<NestedInteger> nl) {
        ls = new ArrayList<Integer>();
        for(NestedInteger ns:nl){
                dfs(ns);
        }
    }
    int i =0;
    @Override
    public Integer next() {
        return ls.get(i++);
    }

    @Override
    public boolean hasNext() {
        return i<ls.size();
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */