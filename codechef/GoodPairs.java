
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            HashMap<Integer,Integer> map = new HashMap<>();
            for(int i=0;i<n;i++){
                map.put(arr[i],map.getOrDefault(arr[i],0)+1);
            }
            int res =0;
            for(int i:map.keySet()){
                int val = map.get(i);
                if(val>1){
                    res += (val*(val-1))/2;
                }
            }
            System.out.println(res);
        }
	}
}
