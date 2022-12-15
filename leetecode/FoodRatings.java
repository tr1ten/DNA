import java.util.HashMap;
import java.util.PriorityQueue;

class FoodRatings {
    HashMap<String,PriorityQueue<Integer>> map;
    HashMap<String,Integer> fti;
    String[] cs;
    String[] foods;
    int[] ratings;
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        map = new HashMap<>();
        cs = cuisines;
        this.ratings = ratings;
        this.foods = foods;
        fti = new HashMap<>();
        int n = foods.length;
        for(int i=0;i<n;i++){
            fti.put(foods[i],i);
            if(!map.containsKey(cuisines[i])) map.put(cuisines[i],new PriorityQueue<>((a,b)->this.ratings[a]==this.ratings[b] ? this.foods[a].compareTo(this.foods[b]) : this.ratings[b]-this.ratings[a]));
            map.get(cuisines[i]).offer(i);
        }
    }
    
    public void changeRating(String food, int newRating) {
        int ind = fti.get(food);
        map.get(cs[ind]).remove(ind);
        ratings[ind] = newRating;
        map.get(cs[ind]).offer(ind);

    }
    
    public String highestRated(String cuisine) {
        return this.foods[map.get(cuisine).peek()];
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */