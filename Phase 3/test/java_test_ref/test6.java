import java.util.Scanner;

public class test6 {
    static Scanner scanner = new Scanner(System.in);

    static int hanoi(int n, int p1, int p2, int p3) {
        if (n == 1) {
            System.out.println(p1 * 1000000 + p3);
        } else {
            hanoi(n - 1, p1, p3, p2);
            System.out.println(p1 * 1000000 + p3);
            hanoi(n - 1, p2, p1, p3);
        }
        return 0;
    }

    public static void main(String[] args) {

        int sum = 3;
        hanoi(sum, 1, 2, 3);
    }
}
