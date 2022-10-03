class Solution {
    int merge(int[] A,int p,int q,int r){
        int p2 = q+1;
        int cnt =0;
        for (int i = p; i <=q; i++) {
            while(p2<=r &&Long.compare(A[i], (long)2*A[p2])>0) p2++;
            cnt += (p2-q-1);
        }
        int n1 = q-p+1;
        int n2 = r-q;
        int i=0;
        int j=0;
        long[] left = new long[n1+1];
        long[] right = new long[n2+1];
        while (i<n1) left[i] =A[p+i++];
        while (j<n2) right[j] =A[q+1+j++];
        left[n1] = Long.MAX_VALUE;
        right[n2] = Long.MAX_VALUE;
        i=0;
        j=0;
        for (int k = p; k <=r; k++) {
            if(left[i]<right[j]) A[k] = (int)left[i++];
            else A[k] = (int)right[j++];
        }
        return cnt;
        
    }
    int mergeSort(int[] A,int p,int r){
        if(r<=p) return 0;
        int mid = (p+r)/2;
        int v = mergeSort(A, p, mid);
        v +=mergeSort(A, mid+1, r);
        v +=merge(A,p,mid,r);
        return v;
    }
    public int reversePairs(int[] nums) {
        return mergeSort(nums, 0, nums.length-1);
    }
}