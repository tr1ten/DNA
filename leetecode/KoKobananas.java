import java.util.Arrays;

class FKin {
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        Arrays.sort(piles);
        int high = piles[n-1];
        int l = 1;
        int mid=0,k=0;
        while(high>=l){
            mid = (high+l)/2;
            k = 0;
            System.out.println("checking for"+mid);
            for(int i=0;i<n;i++){
                k+=Math.ceil(piles[i]*1.0/mid);
                System.out.println(k);
            }
            if(k==h) return mid;
            if(k>h) l = mid+1;
            else high = mid-1;
        
        }
        return mid;
    }
    public static void main(String[] args) {
        FKin s = new FKin();
        int[] piles = {3,6,7,11};
        int h = 8;
        System.out.println(Math.ceil(7*1.0/3));
    }
}