package Complexity;

class PQ{

    public static void main(String[] args) {
        int r = 0;
        int n= 100000000;
        int j=0;
        for(j=1;r<=n;j++){
            r = r +j;
        }
        System.out.println(j);
        
    }
    // space complexity is O(1)
    // time complexity is O(sqrt(n))
}
