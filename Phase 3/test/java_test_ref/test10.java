import java.util.Scanner;

public class test10 {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n;
        n = scanner.nextInt();
        if (n > 0) System.out.println(1);
        else if (n < 0) System.out.println(-1);
        else System.out.println(0);
    }
}
