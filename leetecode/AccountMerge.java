import java.util.*;
import java.util.HashSet;
class AccountMerge {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        List<List<String>> res = new ArrayList<>();
        HashMap<String,Integer> map = new HashMap<>();
        HashMap<Integer,String> idmap = new HashMap<>();
        int n = accounts.size();
        int id = n;
        for (List<String> acc : accounts) {
            for(String mail:acc){
                if(mail==acc.get(0)) continue;
                if(!map.containsKey(mail)) {
                    map.put(mail, id);
                    idmap.put(id++,mail);
                }
            }
        }
        QuickUnionWt uf = new QuickUnionWt(map.size()+n);
        for (int i = 0; i < n; i++) {
            for(String mail:accounts.get(i)){
                if(mail==accounts.get(i).get(0)) continue;
                uf.union(i, map.get(mail));
            }
        }
        HashMap<Integer,List<String>> ans = new HashMap<>(); 
        for (int i = n; i < map.size()+n; i++) {
            if(!ans.containsKey(uf.find(i))){
                ans.put(uf.find(i), new ArrayList<>());
            }
            ans.get(uf.find(i)).add(idmap.get(i));

        }
        for (int i = 0; i < n; i++) {
            List<String> ls = ans.get(uf.find(i));
            if(ls==null){
                continue;
            }
            ls.add(0,accounts.get(i).get(0));
            res.add(ls);
            ans.remove(uf.find(i));
        }
        return res;
    }
    public static void main(String[] args) {
        AccountMerge sol = new AccountMerge();
        List<List<String>> accounts = new ArrayList<>();
        accounts.add(Arrays.asList("John","johnsmith@mail.com","john_newyork@mail.com"));
        accounts.add(Arrays.asList("John","johnsmith@mail.com","john00@mail.com"));
        accounts.add(Arrays.asList("Mary","mary@mail.com"));
        accounts.add(Arrays.asList("John","johnnybravo@mail.com"));
        System.out.println("accounts: " + accounts);
        List<List<String>> res = sol.accountsMerge(accounts);
        System.out.println("res: " + res); 
    }
}
