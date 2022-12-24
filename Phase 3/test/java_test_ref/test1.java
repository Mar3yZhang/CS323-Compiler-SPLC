public class test1 {
    public static void main(String[] args) {
        int a, b, c;
        int _final = 0;
        a = 5;
        b = a * a * (a + 2);
        System.out.println(b);
        c = b / a + 1;
        System.out.println(c);
        _final = a + b - c * 3 + (b / a - 4);
        System.out.println(_final);
    }
}
