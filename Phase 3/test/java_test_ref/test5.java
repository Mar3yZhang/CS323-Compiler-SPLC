import java.util.Scanner;

public class test5 {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int i, tu1, tu2, tu3, m, a, b, c;
        a = 1;
        b = 2;
        c = 3;
        tu1 = 1;
        tu2 = 1;
        tu3 = 0;
        m = scanner.nextInt();
        if (m < 1)
            System.out.println(0);
        else if (m == 1 || m == 2)
            System.out.println(1);
        else if (m > 2) {
            i = 3;
            while (i <= m) {
                tu3 = tu1 + tu2;
                tu1 = tu2;
                tu2 = tu3;
                i = i + 1;
            }
            System.out.println(tu3);
        }
    }
}
