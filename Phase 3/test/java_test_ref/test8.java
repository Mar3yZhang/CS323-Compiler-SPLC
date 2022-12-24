import java.util.Scanner;

public class test8 {
    static Scanner scanner = new Scanner(System.in);
    static int mod(int x, int n) {
        return x - (x / n) * n;
    }

    static int DigitSum(int y) {
        if (y == 0)
            return 0;
        return mod(y, 10) + DigitSum(y / 10);
    }

    public static void main(String[] args) {
        int num;
        num = scanner.nextInt();
        if (num < 0)
            System.out.println(-1);
        else
            System.out.println(DigitSum(num));
    }
}
