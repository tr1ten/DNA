class AddBinary {
    public static void main(String[] args) {
        System.out.println(addBinary("1011", "11"));
    }
    public static String addBinary(String a, String b) {
        int c = 0;
        int sum = 0;
        int i = 1;
        int al = a.length();
        int bl = b.length();
        int A;
        int B;
        StringBuilder res = new StringBuilder();
        while (i <=al && i <=bl) {
            A = a.charAt(al - i) - '0';
            B = b.charAt(bl - i) - '0';
            sum = A ^ B ^ c;
            c = A & B | B & c | c & A;
            res.append(Integer.toString(sum).charAt(0));
            i++;
        }
        String larger = al > bl ? a : b;
        while (i <=larger.length()) {
            A = larger.charAt(larger.length() - i) - '0';
            int temp = c;
            c = A & c;
            sum = A ^ temp;
            res.append(Integer.toString(sum).charAt(0));
            i++;
        }
        if (c==1) {
            res.append(Integer.toString(c).charAt(0));
        }

        return res.reverse().toString();
    }
}
