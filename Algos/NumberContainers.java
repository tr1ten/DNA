class NumberContainers {
    HashMap<Integer, TreeSet<Integer>> map; // number to indices
    HashMap<Integer, Integer> rmap; // index to number

    public NumberContainers() {
        map = new HashMap<>();
        rmap = new HashMap<>();
    }

    public void change(int index, int number) {
        if(rmap.containsKey(index)) map.get(rmap.get(index)).remove(index);
        rmap.put(index, number);
        if (!map.containsKey(number))
            map.put(number, new TreeSet<>());
        map.get(number).add(index);
    }

    public int find(int number) {
        return (!map.containsKey(number) || map.get(number).size()==0) ? -1 : map.get(number).first();
    }
}