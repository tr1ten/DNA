import java.util.*;
public class BasicCalculator {
    String eval(String a, String b, char op){
        int x = Integer.parseInt(a);
        int y = Integer.parseInt(b);
        if(op=='+') return String.valueOf(x+y);
        else if(op=='-') return String.valueOf(x-y);
        else if(op=='*') return String.valueOf(x*y);
        else return String.valueOf(x/y);
    }
    public int calculate(String s) {
        s= s.replaceAll("\\s+","");
        int n = s.length();
        int i = 0;
        Stack<Character> ops = new Stack<>();
        Stack<String> ods = new Stack<>();
        int isign = 1;
        Stack<Integer> osign = new Stack<>();
        while (i<n) {
            char c = s.charAt(i);
            if(Character.isDigit(c)){
                int j = i;
                while (j<n && Character.isDigit(s.charAt(j))) j++;
                String oprand = s.substring(i, j);
                if(isign<0) {
                    oprand = "-" + oprand;
                    isign = 1;
                }
                if(!ods.isEmpty() && ods.peek()!="("){
                    ods.push(eval(ods.pop(), oprand, ops.pop()));
                }
                else{
                    ods.push(oprand);
                }
                i = j-1;
            }
            else{
                switch (c) {
                    case '(':
                        ods.push("(");
                        osign.push(isign);
                        isign = 1;
                        break;
                    case ')':{
                        String temp = ods.pop();
                        ods.pop();
                        if(osign.pop()<0) {
                            if(temp.charAt(0)=='-') temp = temp.substring(1);
                            else temp = "-" + temp;
                        }
                        if(!ods.isEmpty() && ods.peek()!="("){
                            ods.push(eval(ods.pop(), temp, ops.pop()));
                        }
                        else ods.push(temp);
                        break;
                    }
                    case '-':
                        if(ods.isEmpty() || ods.peek()=="(") isign = -1;
                        else ops.push(c);
                        break;
                    default:
                        ops.push(c);
                        break;
                }
                
            }
            i++;
        }
        return ods.isEmpty() ? 0 : Integer.valueOf(ods.pop());
    }
    public static void main(String[] args) {
        BasicCalculator s = new BasicCalculator();
        // System.out.println(s.calcula te("1 + 1"));
        // System.out.println(s.calculate(" 2-1 + 2 "));
        // System.out.println(s.calculate("1+(4+2)-3 +"));
        // System.out.println(s.calculate("1-(5)"));
        System.out.println(s.calculate("1-(-2)"));
    }
}
