
class Solution {
    int countIncreasing(int arr[], int n) {
        if(n<2) return 0;
        int p1 = 0;
        int p2 = 1;
        int len = arr.length;
        int count = 0;
        while(p1<len && p2<len){
            if(arr[p2]>arr[p2-1]){
                count =count + (p2-p1);
                p2++;
                continue;
            }
            p1 = p2;
            p2++;
            
        }
        return count;
    }
    
}