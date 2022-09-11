import java.util.*;



public class MeetingRooms2 {
    static class Interval {
        int start, end;
        public String toString() {
            return "[" + start + ", " + end + "]";
        };
        Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    public int minMeetingRooms(List<Interval> intervals) {
        Collections.sort(intervals,(a,b)->a.start==b.start ? a.end-b.end : a.start-b.start);
        LinkedList<Interval> ll = new LinkedList<>(intervals);
        int ans=0;
        while(ll.size()>0){
            ListIterator<Interval> itr = ll.listIterator();
            Stack<Interval> st = new Stack<>();
            System.out.println(ll);
            while(itr.hasNext()){
                Interval val = itr.next();
                if(st.isEmpty()) {
                    itr.remove();
                    st.push(val);
                }
                else{
                    Interval intvl = st.peek();
                    if(val.start >= intvl.end){
                        itr.remove();
                        st.push(val);
                    }
                }
            }
            ans++;
    }
        return ans;
    }
    public static void main(String[] args) {
        MeetingRooms2 sol = new MeetingRooms2();
        List<Interval> intervals = new ArrayList<>();
        intervals.add(new Interval(0, 30));
        intervals.add(new Interval(7,12));
        intervals.add(new Interval(5, 10));
        intervals.add(new Interval(15, 20));
        System.out.println(sol.minMeetingRooms(intervals));
    }
}