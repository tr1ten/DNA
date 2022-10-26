class Solution {
    public int longestStrChain(String[] words) {
        HashMap<String,Integer> map = new HashMap<>();
        Arrays.sort(words,(a,b)->a.length()-b.length());
        for(String word:words){
            int b = 0;
            for(int i=0;i<word.length();i++){
                String prev = word.substring(0,i) + word.substring(i+1,word.length());
                b = Math.max(b,map.getOrDefault(prev,0)+1);
            }
            map.put(word,b);
        }
        return Collections.max(map.values());
    }
}