import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;


class GuessNumber {
    public static int binlog( int bits ) // returns 0 for bits=0
	{
		int log = 0;
		if( ( bits & 0xffff0000 ) != 0 ) { bits >>>= 16; log = 16; }
		if( bits >= 256 ) { bits >>>= 8; log += 8; }
		if( bits >= 16  ) { bits >>>= 4; log += 4; }
		if( bits >= 4   ) { bits >>>= 2; log += 2; }
		return log + ( bits >>> 1 );
	}
    static void guess(int n){
        ArrayList<Integer> pos = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pos.add(i+1);
        }
        ArrayList<Integer> npos = new ArrayList<>();
        int h = binlog(n);
        Scanner sc = new Scanner(System.in);
        while (h-->0) {
            Collections.shuffle(pos);
            List<Integer> ls = new ArrayList<>();
            Iterator<Integer> itr = pos.iterator();
            int t=pos.size()/2;
            int l=(n-pos.size())/2;
            List<Integer> nl = new ArrayList<>();
            while (itr.hasNext() && t-->0) {
                int a = itr.next();
                ls.add(a);
                nl.add(a);
                itr.remove();
            }
            Collections.shuffle(npos);
            Iterator<Integer> it = npos.iterator();
            while (it.hasNext() && l-->0) {
                nl.add(it.next());
            }
            Collections.sort(nl);
            for (int x:nl) {
                System.out.print(x+ " ");
            }
            System.out.println();
            int i = sc.nextInt();
            if(i>0){
                npos.addAll(pos);
                pos.clear();
                pos.addAll(ls);
            }
            else{
                npos.addAll(ls);
            }
        }
        if(pos.size()>1) System.out.println("There's ambiguity in choosen number");
        else System.out.println("Your number is "+pos.get(0));
    }

    public static void main(String[] args) {
        guess(128);
    }        
}
