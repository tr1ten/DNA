import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class PathWithMax {
    double djisktra(List<double[]>[] graph,int s,int e){
        double[] distTo = new double[graph.length];
        Arrays.fill(distTo, 0.0);
        distTo[s] = 1;
        PriorityQueue<double[]> pq = new PriorityQueue<>((a,b)->Double.compare(b[1], a[1]));
        pq.offer(new double[]{s,1});
        while (!pq.isEmpty()) {
            double[] item = pq.poll();
            int u = (int)item[0];
            double d = item[1];
            // if outdated value 
            if(distTo[u]>d) continue;
            if(u==e) return d;
            for (double[] ed:graph[u]) {
                int v = (int) ed[0];
                double dis = ed[1];
                if(distTo[v]<dis*distTo[u]) {
                    distTo[v] = (dis*distTo[u]);
                    pq.offer(new double[]{v,distTo[v]});
                }
            }
        }
        return distTo[e];
        
    }
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        List<double[]>[] graph = new List[n];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < edges.length; i++) {
            graph[edges[i][0]].add(new double[]{edges[i][1],succProb[i]});  
            graph[edges[i][1]].add(new double[]{edges[i][0],succProb[i]});
        }
        double d = djisktra(graph, start, end);
        return d==Double.MAX_VALUE ? 0.0 : d;
    }
}
