
class Solution
{
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        PriorityQueue<double[]> pq = new PriorityQueue<>((a,b)->Double.compare(b[0],a[0]));
        for(int i=0;i<n;i++){
            pq.offer(new double[]{arr[i].value*1.0/arr[i].weight,arr[i].weight});
        }
        double res = 0;
        while(W>0){
            double[] d = pq.poll();
            if(d==null) break;
            int w = Math.min((int)d[1],W);
            res += d[0]*w;
            W -=w;
        }
        
        return res;
    }
}