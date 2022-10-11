
import java.lang.reflect.Array;
import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.TreeMap;
class TreeNode {
    TreeNode right;
    TreeNode left;
    int val;
    TreeNode(int val) {this.val = val;}
    TreeNode(int val,TreeNode r,TreeNode l) {
        this.val = val;
        this.right = r;
        left = l;
    }

}
class RandomWC {
    public int commonFactors(int a,int b){
        int cnt = 1;
        HashSet<Integer> hs = new HashSet<>();
        int min;
        int max;
        if(a<b){
             min=a;
             max=b;}
        else {
            min = b;
            max = a;
        }
        for (int i = 2; i <=min; i++) {
            if(min%i==0 && max%i==0) cnt++;
        }
        return cnt;
    }
    public int maxSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int mx = Integer.MIN_VALUE;
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                int sum= grid[i-1][j-1] + grid[i-1][j+1] + grid[i-1][j] + grid[i][j] + grid[i+1][j-1] + grid[i+1][j+1] + grid[i+1][j];
                mx = Math.max(mx, sum);
            }
        }
        return mx;    
    }
    HashSet<Integer> setB(int a){
        int i=0;
        HashSet<Integer> hs = new HashSet<>();
        while (a!=0) {
            if((a&1)==1) hs.add(i);
            a = a>>1;
            i++;
        }
        return hs;
    }
    public int minimizeXor(int num1, int num2) {
        HashSet<Integer> ca = setB(num1);
        HashSet<Integer> cb = setB(num2);
        if(ca.size()==cb.size()) return num1;
        else if(cb.size()>ca.size()){
            int x=num1;

            int i=0;
            int d = cb.size()-ca.size();
            while (d>0) {
                if(!ca.contains(i)){
                    x = x | 1 << i;
                    d--;
                }
                i++;
            }
            return x;
        }
        else{
            List<Integer> ls = new ArrayList<>(ca);
            Collections.sort(ls,Comparator.reverseOrder());
            int d = cb.size();
            int i=0;
            int x=0;
            while (d-->0) {
                x = x | 1 << ls.get(i++);
            }
            return x;
        }
    }
        HashMap<String,Integer> hm = new HashMap<>();
        public int deleteString(String s) {
            if(s.length()==0) return 0;
            if(hm.containsKey(s)) return hm.get(s);
            if((s.length() - s.replace(s.charAt(0)+"", "").length())==s.length()) return s.length();
            int pa1 = 0;
            int pa2=0;
            int pb1= 1;
            int pb2=1;
            int sz = s.length();
            int mx = Integer.MIN_VALUE;
            while (pb1<sz && pb2<sz) {
                if(s.substring(pa1,pa2+1).equals(s.substring(pb1,pb2+1))){
                    mx = Math.max(mx, deleteString(s.substring(pa2+1,s.length())));
                }
                pa2++;
                pb1 = pa2+1;
                pb2 = pb1 + (pa2-pa1);
            }
            if(mx==Integer.MIN_VALUE) {
                hm.put(s,1);
                return 1;
            }
            else{
                hm.put(s, mx+1);
                return hm.get(s);
            }
        }
}