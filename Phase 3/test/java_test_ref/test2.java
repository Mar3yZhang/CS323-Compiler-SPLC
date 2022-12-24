import java.util.Scanner;

public class test2 {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        int month, year;
        year = scanner.nextInt();
        month = scanner.nextInt();
        if(year == (year / 100 * 100)){
            if(year == (year / 400 * 400)){
                if(month == 2){
                    System.out.println(29);
                }
                else if(month == (month / 2 * 2)){
                    System.out.println(30);
                }
                else
                    System.out.println(31);
            }else {
                if(month == 2){
                    System.out.println(28);
                }
                else if(month == (month / 2 * 2)){
                    System.out.println(30);
                }
                else {
                    System.out.println(31);
                }
            }
        }
        else if(year == (year/4 * 4)){
            if(month == 2){
                System.out.println(29);
            }
            else if(month == (month / 2 * 2)){
                System.out.println(30);
            }
            else {
                System.out.println(31);
            }
        }
        else{
            if(month == 2){
                System.out.println(28);
            }
            else if(month == (month / 2 * 2)){
                System.out.println(30);
            }
            else {
                System.out.println(31);
            }
        }
    }
}
