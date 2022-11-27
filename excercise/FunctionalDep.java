package excercise;
import java.util.*;

public class FunctionalDep {
    HashSet<HashSet<Integer>> candidaSet;
    HashSet<HashSet<Integer>> allAttribuSet;
    HashSet<HashSet<Integer>> superKeySet;
    HashMap<HashSet<Integer>, Boolean> dp;
    boolean dfs(HashSet<Integer> set, HashMap<HashSet<Integer>, HashSet<Integer>> FD,int n) {
        if(set.size() == n) {
            return true;
        }
        if(dp.containsKey(set)) {
            return dp.get(set);
        }
        HashSet<Integer> temp = new HashSet<Integer>(set);
        boolean res = false;
        for(HashSet<Integer> key : FD.keySet()) {
            if(set.containsAll(FD.get(key))) continue;
            if(set.containsAll(key)) {
                set.addAll(FD.get(key));
                if(dfs(set, FD, n)) {
                    res = true;
                    break;
                }
            }
        }
        dp.put(temp, res);
        return res;
        
    }
    FunctionalDep(HashMap<HashSet<Integer>, HashSet<Integer>> FD,int n){
        dp = new HashMap<HashSet<Integer>, Boolean>();
        // find all combinations of attributes using bit mask
        allAttribuSet = new HashSet<HashSet<Integer>>();
        for(int i=0;i<(1<<n);i++){
            HashSet<Integer> temp = new HashSet<Integer>();
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){
                    temp.add(j);
                }
            }
            allAttribuSet.add(temp);
        }
        
        superKeySet = new HashSet<HashSet<Integer>>();
        candidaSet = new HashSet<HashSet<Integer>>();
        // find all candidate keys and super keys
        for(HashSet<Integer> key:allAttribuSet){
            boolean res = dfs(new HashSet<>(key),FD,n);
            if(res){
                superKeySet.add(key);
            }
        }
        for (HashSet<Integer> skey : superKeySet) {
            // if it candidate key then removing any of its attribute will make it non super key.
            boolean flag = true;
            for(int k:skey){
                HashSet<Integer> temp = (HashSet<Integer>)skey.clone();
                temp.remove(k);
                if(superKeySet.contains(temp)){
                    flag = false;
                    break;
                }    
            }
            if(flag) candidaSet.add(skey);
        }
    }

    
    public static void main(String[] args) {
        int n = 5;
        HashMap<HashSet<Integer>, HashSet<Integer>> FD = new HashMap<HashSet<Integer>, HashSet<Integer>>();
        HashSet<Integer> key = new HashSet<Integer>();
        HashSet<Integer> value = new HashSet<Integer>();
        key.add(0);
        value.add(1);
        FD.put(key, value);
        key = new HashSet<Integer>();
        value = new HashSet<Integer>();
        key.add(1) ;
        key.add(2);
        value.add(4);
        FD.put(key, value);
        key = new HashSet<Integer>();
        value = new HashSet<Integer>();
        key.add(3);
        key.add(4);
        value.add(0);
        FD.put(key, value);
        // FD -> {0} -> {1}, {1,2} -> {4}, {3,4} -> {0}
        FunctionalDep obj = new FunctionalDep(FD,n);
        System.out.println("Super Keys are : ");
        System.out.println(obj.superKeySet);
        System.out.println("Candidate Keys are : ");
        System.out.println(obj.candidaSet);
    }
}
