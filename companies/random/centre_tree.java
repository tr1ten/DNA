import java.util.*;

class Main {
    public static void main(String[] args) {
        List<int[]> edges1 = new ArrayList<>();
        edges1.add(new int[]{1, 2});
        edges1.add(new int[]{2, 3});
        edges1.add(new int[]{3, 4});
        edges1.add(new int[]{3, 5});
        edges1.add(new int[]{1, 6});
        edges1.add(new int[]{1, 7});

        int[] result1 = solve(edges1);
        System.out.println(Arrays.toString(result1));

        List<int[]> edges2 = new ArrayList<>();
        edges2.add(new int[]{2, 1});

        int[] result2 = solve(edges2);
        System.out.println(Arrays.toString(result2));
    }

    static class Edge {
        int v;
        int w;

        Edge(int v, int w) {
            this.v = v;
            this.w = w;
        }
    }

    public static int[] solve(List<int[]> edges) {
        int n = edges.size() + 1;
        List<List<Edge>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj.get(u).add(new Edge(v, 1));
            adj.get(v).add(new Edge(u, 1));
        }

        int[] d1 = dijkstra(0, adj);
        int v1 = -1;
        int maxDist1 = -1;

        for (int i = 0; i < n; i++) {
            if (d1[i] > maxDist1) {
                maxDist1 = d1[i];
                v1 = i;
            }
        }

        int[] d2 = dijkstra(v1, adj);
        int v2 = -1;
        int maxDist2 = -1;

        for (int i = 0; i < n; i++) {
            if (d2[i] > maxDist2) {
                maxDist2 = d2[i];
                v2 = i;
            }
        }

        List<Integer> path = new ArrayList<>();
        while (v2 != v1) {
            path.add(v2);
            v2 = par[v2];
        }
        path.add(v1);

        int[] res = new int[n];
        int mid = path.size() / 2;

        if (path.size() % 2 == 0) {
            int c1 = path.get(mid - 1);
            int c2 = path.get(mid);
            for (int v : leaves(c1, c2, adj)) {
                res[v] = 1;
            }
            for (int v : leaves(c2, c1, adj)) {
                res[v] = 1;
            }
        } else {
            int c1 = path.get(mid);
            for (int v : leaves(c1, c1, adj)) {
                res[v] = 1;
            }
        }

        return res;
    }

    static int[] par;

    public static int[] dijkstra(int src, List<List<Edge>> adj) {
        int n = adj.size();
        int[] dist = new int[n];
        par = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        Arrays.fill(par, -1);

        PriorityQueue<Edge> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.w));
        pq.add(new Edge(src, 0));
        dist[src] = 0;
        par[src] = src;

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int u = edge.v;
            int c = edge.w;

            if (c > dist[u]) {
                continue;
            }

            for (Edge neighbor : adj.get(u)) {
                int v = neighbor.v;
                int w = neighbor.w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    par[v] = u;
                    pq.add(new Edge(v, dist[v]));
                }
            }
        }

        return dist;
    }

    public static List<Integer> leaves(int u, int p, List<List<Edge>> adj) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(u);
        List<Integer> ret = new ArrayList<>();
        Set<Integer> vis = new HashSet<>();
        vis.add(u);
        vis.add(p);

        while (!q.isEmpty()) {
            int sz = q.size();
            List<Integer> lvl = new ArrayList<>();

            for (int i = 0; i < sz; i++) {
                int v = q.poll();
                lvl.add(v);

                for (Edge edge : adj.get(v)) {
                    int neighbor = edge.v;
                    if (!vis.contains(neighbor)) {
                        q.offer(neighbor);
                        vis.add(neighbor);
                    }
                }
            }

            ret = lvl;
        }

        return ret;
    }
}
