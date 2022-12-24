import java.util.Scanner;

public class test7 {
    static Scanner scanner = new Scanner(System.in);
    static int gcd1(int a, int b)
    {
        int result;
        int temp;
        temp = a - a/ b * b;
        while (temp != 0) {
            a = b;
            b = temp;
            temp = a - a / b * b;
        }
        result = b;
        return result;
    }
    static int gcd2(int x, int y)
    {
        int remainder = 0;
        if(x > y){
            remainder = x - x / y * y;
            if(remainder == 0)
                return y;
            else
                return gcd2(y, remainder);
        }
        else {
            remainder = y - y / x * x;
            if(remainder == 0)
                return x;
            else
                return gcd2(x, remainder);
        }
    }

    public static void main(String[] args) {
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        System.out.println(gcd1(m,n));
        System.out.println(gcd2(m,n));
    }
}
