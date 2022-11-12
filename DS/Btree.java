package DS;

import java.util.*;
/**
 * Btree - Balance tree
 */
class Btree {
    class BNode{
        BNode[] childs;
        Integer[] keys;
        boolean isLeaf;
        int n;
        BNode(boolean leaf){
            childs = new BNode[2*t-1];
            keys = new Integer[2*t];
            n=0;
            isLeaf = leaf;
        }
        @Override
        public String toString(){
            return Arrays.toString(keys);
        }
    }
    BNode root; 
    int t; // degree
    Btree(int degree){
        this.t = degree;
        root=new BNode(true);
        root.n = 0;
    }
    // Node y D x:ci splits into two nodes, y and z, and the
    // median key S of y moves up into y’s parent x.
    void splitChild(BNode x,int i){
        BNode y = x.childs[i];
        BNode z = new BNode(y.isLeaf);
        z.n = t-1; // right part
        for (int j = 0; j < t-1; j++) {
            z.keys[j] = y.keys[j+t]; // copy all t...2t-1 keys from y to right part
        }
        // if not leaf node, copy all childs
        if(!y.isLeaf){
            for (int j = 0; j < t; j++) {
                z.childs[j] = y.childs[j+t];
            }
        }
        y.n = t-1; // now reduce the keys size 
        // process parent x
        for (int j = x.n; j >= i+1; j--) {
            x.childs[j+1] = x.childs[j]; // move all keys one place 
        }
        x.childs[i] = z; // set right child
        for (int j = x.n-1; j >= i; j--) {
            x.childs[j+1] = x.childs[j]; 
        }
        x.keys[i] = y.keys[t-1];
        x.n++;
    }
    void insert(int key){
        BNode r = this.root;
        if(r.n==2*t-1){
            BNode node = new BNode(false);
            this.root = node;
            node.n = 0;
            node.childs[0] = r;
            splitChild(node, 0);
            insertNonFull(node, key);
        }
        else insertNonFull(r, key);
    }
    void insertNonFull(BNode x,int k){
        if(x.isLeaf){
            int i = x.n-1;
            while (i>=0 && k<x.keys[i]) {
                x.keys[i+1] = x.keys[i];
                i--;
            }
            x.keys[i+1] = k;
            x.n++; 
        }
        else {
            int i = x.n-1;
            while (i>=0 && k<x.keys[i]) {
                i--;
            }
            i++;
            if(x.childs[i].n==2*t-1){
                splitChild(x, i);
                if(k>x.keys[i]) i++;
            }
            insertNonFull(x.childs[i], k);
        }

    }
    boolean search(BNode x,int k){
        int i=0;
        while (i<x.n && k>x.keys[i]) {
            i++;
        }
        if(i<x.n && k==x.keys[i]) return true;
        if(x.isLeaf) return false;
        return search(x.childs[i], k);
    }
    void display(BNode x){
        if(x==null) return;
        // keys
        for (int i = 0; i < x.n; i++) {
            System.out.print(x.keys[i]+" ");
        }
        for (int i = 0; i < x.n+1; i++) {
            display(x.childs[i]);
        }
    }
    public static void main(String[] args) {
        Btree tree = new Btree(2);
        tree.insert(10);
        tree.insert(20);
        // System.out.println(tree.search(tree.root,  12));
        tree.insert(5);
        tree.insert(30);
        tree.insert(7);
        tree.insert(17); // not working for this
    }
}