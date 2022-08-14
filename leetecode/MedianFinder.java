
import java.util.PriorityQueue;

class MedianFinder {
    PriorityQueue<Integer> maxq;
    PriorityQueue<Integer> minq;

    public MedianFinder() {
        minq = new PriorityQueue<>((a, b) -> a - b);
        maxq = new PriorityQueue<>((a, b) -> b - a);
    }


    public void addNum(int num) {
        if (minq.size() == 0 && maxq.size() == 0) {
            maxq.add(num);
            return;
        }
        if (maxq.size() == minq.size()) {
            if (maxq.peek() > num) maxq.add(num);
            else minq.add(num);
            return;
        }
        if (maxq.size() > minq.size()) {
            if (maxq.peek() < num) minq.add(num);
            else {
                minq.add(maxq.remove());
                maxq.add(num);
            }
        } else {
            if (minq.peek() > num) maxq.add(num);
            else {
                maxq.add(minq.remove());
                minq.add(num);
            }
        }
    }

    public double findMedian() {
        if (minq.size() == maxq.size()) {
            double sm = minq.peek() + maxq.peek();
            return sm/ 2;
        }
        return minq.size() > maxq.size() ? minq.peek() : maxq.peek();
    }

    public static void main(String[] args) {
        // test
//        ["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian"]
//        [[],[12],[],[10],[],[13],[],[11],[],[5],[],[15],[],[1],[],[11],[],[6],[],[17],[],[14],[],[8],[],[17],[],[6],[],[4],[],[16],[],[8],[],[10],[],[2],[],[12],[],[0],[]]
        MedianFinder mf = new MedianFinder();
        mf.addNum(12);
        System.out.println(mf.findMedian());
        mf.addNum(10);
        System.out.println(mf.findMedian());
        mf.addNum(13);
        System.out.println(mf.findMedian());
        mf.addNum(11);
        System.out.println(mf.findMedian());
        mf.addNum(5);
        System.out.println(mf.findMedian());
        mf.addNum(15);
        System.out.println(mf.findMedian());
        mf.addNum(1);
        System.out.println(mf.findMedian());
        mf.addNum(11);
        System.out.println(mf.findMedian());
        mf.addNum(6);
        System.out.println(mf.findMedian());
        mf.addNum(17);
        System.out.println(mf.findMedian());
        mf.addNum(14);
        System.out.println(mf.findMedian());
        mf.addNum(8);
        System.out.println(mf.findMedian());
        mf.addNum(17);
        System.out.println(mf.findMedian());
        mf.addNum(6);
        System.out.println(mf.findMedian());
        mf.addNum(4);
        System.out.println(mf.findMedian());
        mf.addNum(16);
        System.out.println(mf.findMedian());
        mf.addNum(8);
        System.out.println(mf.findMedian());
        mf.addNum(10);
        System.out.println(mf.findMedian());
        mf.addNum(2);
        System.out.println(mf.findMedian());
        mf.addNum(12);
        System.out.println(mf.findMedian());
        mf.addNum(0);
        System.out.println(mf.findMedian());

    }
}