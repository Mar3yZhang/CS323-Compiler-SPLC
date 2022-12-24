import java.util.Scanner;

public class test4 {

    static int sqr(int i1) {
        return i1 * i1;
    }

    static int cbc(int i2) {
        return i2 * i2 * i2;
    }

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int a, r;
        a = scanner.nextInt();
        System.out.println(a);
        r = sqr(a);
        System.out.println(r);
        r = cbc(a);
        System.out.println(r);
    }
}
