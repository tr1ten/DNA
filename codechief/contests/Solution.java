/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader()
		{
			br = new BufferedReader(
				new InputStreamReader(System.in));
		}

		String next()
		{
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				}
				catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() { return Integer.parseInt(next()); }

		long nextLong() { return Long.parseLong(next()); }

		double nextDouble()
		{
			return Double.parseDouble(next());
		}

		String nextLine()
		{
			String str = "";
			try {
				if(st.hasMoreTokens()){
					str = st.nextToken("\n");
				}
				else{
					str = br.readLine();
				}
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

	public static void main(String[] args)
	{
		FastReader s = new FastReader();
		int n = s.nextInt();
		while (n-- > 0) {
            int N = s.nextInt();
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = s.nextInt();
            }
            int sa= 0;
            int o =0;
            for (int i = 0; i < arr.length-1; i++) {
                if(arr[i]!=arr[i+1]){
                    o++;
                }
                else{
                    sa++;
                }
            }
            if(arr[0]!=arr[arr.length-1]){
                o++;
            }
            if(o-sa==1) System.out.println("Bob");
            else System.out.println("Alice");
            

		}
	}
}
