package Complexity;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Set;
import java.util.TreeSet;

public class Dequ {
    public static void main(String[] args) {
        TreeSet<Set<Integer>> ts = new TreeSet<>((a,b)->b.size()-a.size());
        Set<Integer> s = new TreeSet<>();
        // add {1,3,2} {1,4,6} {1,4,5,7}
        s.add(1);
        s.add(3);
        s.add(2);
        ts.add(s);
        s = new TreeSet<>();
        s.add(1);
        s.add(4);
        s.add(6);
        ts.add(s);
        System.out.println(ts);
    }
}
