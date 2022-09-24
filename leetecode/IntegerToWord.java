
class Solution {
    private final String[] LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    private final String[] TENS = {"", "Ten","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    private final String[] THOUSANDS = {"","Hundred", "Thousand", "Million", "Billion"};
    public String solve(int num) {
        if(num<20) return LESS_THAN_20[num];
        if(num<100){
            return TENS[num/10]+ " " + solve(num%10);
        }
        String s = String.valueOf(num);
        int d = s.length();
        if(d<4) return LESS_THAN_20[num/100] + " " + THOUSANDS[1] + " " + solve(num%100);
        if(d<7) return solve(Integer.parseInt(s.substring(0, d-3))).trim() + " " + THOUSANDS[2] + " " + solve(Integer.parseInt(s.substring(d-3, d))).trim();
        if(d<10) return solve(Integer.parseInt(s.substring(0, d-6))).trim() + " " + THOUSANDS[3] + " " + solve(Integer.parseInt(s.substring(d-6, d))).trim();
        return solve(Integer.parseInt(s.substring(0, d-9))).trim() + " " + THOUSANDS[4] + " " + solve(Integer.parseInt(s.substring(d-9, d))).trim();

    }
    public String numberToWords(int num) {
        if(num==0) return "Zero";
        return solve(num).trim();
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solve(1234567891));
    }

}