class Solution {
    public int numberOfWeakCharacters(int[][] props) {
        Arrays.sort(props,(a,b)->a[0]-b[0]);
        TreeMap<Integer,Integer> tm = new TreeMap<>(); // attack group, max defence value of equal or higher group
        int max = 0;
        int n = props.length;
        int i = n-1;
        while(i>=0){
            max = Math.max(props[i][1],max);
            tm.put(props[i][0],max);
            i--;
        }
        int res = 0;
        for(i=0;i<n;i++){
            int[] x = props[i];
            Integer c = tm.ceilingKey(x[0]+1);
            if(c!=null && tm.get(c)>x[1]) res++;
        }
        return res;
    }
}