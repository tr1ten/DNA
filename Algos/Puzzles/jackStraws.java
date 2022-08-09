package Algos.Puzzles;

import java.util.HashMap;
import java.util.HashSet;

/**
 * Line
 */
// To-Do
class Point {
    double x;
    double y;

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

public class jackStraws {
    public static double getSlope(Point p1, Point p2) {
        if (p1.x == p2.x) {
            return (p2.y - p1.y) > 0 ? Double.POSITIVE_INFINITY : Double.NEGATIVE_INFINITY;
        }
        return ((p2.y - p1.y) / (p2.x - p1.x));
    }

    public static Point findIntersection(Point f1, Point f2, Point p1, Point p2) {
        double m1 = getSlope(f1, f2);
        double m2 = getSlope(p1, p2);
        // if(m1==Double.MAX_VALUE && ((p1.x <+f2.x && p2.x >= f2.x) || (p2.x <+f2.x &&
        // p1.x >= f2.x) ))
        // {
        // return
        // }
        if (m1 == m2) {
            return new Point(Double.POSITIVE_INFINITY, Double.POSITIVE_INFINITY);
        }
        double x = ((p2.y - f1.y) - p2.x * m2 - m1 * f1.x) / (m1 - m2);
        double y = m2 * (x - p2.x) + p2.y;
        return new Point(x, y);
    }

    public static boolean isConnected(int l1, int l2, Point[][] endPoints) {
        HashMap<Integer, HashSet<Integer>> hm = new HashMap<>();
        for (int i = 0; i < endPoints.length; i++) {
            hm.put(i, new HashSet<>());
            for (int j = i + 1; j < endPoints.length; j++) {
                Point intersection = findIntersection(endPoints[i][0], endPoints[i][1], endPoints[j][0],
                        endPoints[j][1]);
                if (intersection.x != Double.POSITIVE_INFINITY) {
                    hm.get(i).add(j);
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Point[][] endPoints = {
            {new Point(0,2),new Point(0,0)},
            {new Point(0,0),new Point(0,1)}
        };
        System.out.println(isConnected(0,1, endPoints));
    }
}
