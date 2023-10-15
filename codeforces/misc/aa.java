class Solution {
    public static void island(char [][]arr,int i,int j,boolean[][]visited){
      if(i<0 ||j<0 ||i>=arr.length||j>=arr[0].length||visited[i][j]==true||arr[i][j]=='0'){
          return;
      }
       
      visited[i][j]=true;
      island(arr,i-1,j,visited);
      island(arr,i+1,j,visited);
      island(arr,i,j-1,visited);
      island(arr,i,j+1,visited);
  }
   
   public int numIslands(char[][] arr) {
       
  boolean[][]visited=new boolean[arr.length][arr[0].length];
     int count=0;
     for(int i=0;i<arr.length;i++){
         for(int j=0;j<arr[i].length;j++){
            
             if(visited[i][j]==false && arr[i][j]=='1'){
                 island(arr,i,j,visited);
                 count++;
                
             }
         }
     }
     
     return count;
  }
   
}