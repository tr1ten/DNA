package excercise;

import java.util.Random;

class Item {
    int value, weight;
    Item(int x, int y){
        this.value = x;
        this.weight = y;
    }
}

class Solution
{
    private static Random random = new Random();    

    public static int getRandomInt(int min, int max){
    return random.nextInt(max - min + 1) + min;
    }
    private void swap(int[][] arr,int i,int j){
        int[] temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    private int partition(int high,int low,int[][] arr,int pi){
        swap(arr,pi,high);
        int pivot = arr[high][0];
        int p1 = low-1;
        for (int i = low; i < high; i++) {
            if(arr[i][0]<pivot){
                swap(arr,++p1,i);
            }
        }
        swap(arr,++p1,high);
        return p1;
    }
    double f(int low,int high,int W,int[][] ratios){
        if(W==0) return 0;
        int pi = random.nextInt(low,high);
        int pivot = partition(high, low, ratios, pi);

    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        
        
        return res;
    }
}