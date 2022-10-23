class Solution {
    public boolean lemonadeChange(int[] bills) {
        // 5 10
        int[] g = new int[]{0,0};
        for(int b:bills){
            switch(b){
                case 5:
                    g[0]++;
                    break;
                case 10:
                    if(g[0]==0) return false;
                    else {
                        g[0]--;
                        g[1]++;
                        break;
                    }
                case 20:
                    if(g[1]>0 && g[0]>0){
                        g[1]--;
                        g[0]--;
                    }
                    else if(g[0]>2){
                        g[0] -=3;
                    }
                    else return false;
                    break;
            }
        }
        return true;
    }
}