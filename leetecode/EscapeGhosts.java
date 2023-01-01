import java.util.function.BiFunction;

class Solution {
    
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        BiFunction<int[],int[],Integer> dist = (from,other)->Math.abs(from[0]-other[0])+Math.abs(from[1]-other[1]);
        int src = dist.apply(new int[]{0,0},target);
        for(int[] g:ghosts) {
            if(src>=dist.apply(g, target)) return false;
        }
        return true;
    }
}