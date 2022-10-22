class Solution
{
    static long floorSqrt(long x)
	 {
		   long h = x;
		   long l = 1;
		   while(l<=h){
		       long mid = (h+l)/2;
               long pq  = mid*mid;
               if(pq==x) return mid;
               if(pq<x) l = mid+1;
               else h = mid-1;
		   }
           return l*l > x ? l-1 : l;
	 }
     public static void main(String[] args) {
            long x = 26;
            System.out.println(floorSqrt(x));
     }
}
