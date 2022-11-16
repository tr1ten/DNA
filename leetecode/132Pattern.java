class Solution {
    public boolean find132pattern(int[] nums) {
        Stack<int[]> gr = new Stack<>();
        int min= Integer.MAX_VALUE;
        for(int x:nums){
            while(!gr.isEmpty() && gr.peek()[0]<=x){
                gr.pop();
            }
            if(!gr.isEmpty() && gr.peek()[1]<x){
                return true;
            }
            min = Math.min(min,x);
            gr.push(new int[]{x,min});
        }
        return false;
    }
}