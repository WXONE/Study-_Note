import java.util.Scanner;

public class RunNian {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("请输入年份");
        //boolean leap;
        int year = scan.nextInt();
        if(year%4 == 0 && year % 100 != 0||year % 400 == 0){
            System.out.println(year+"年是闰年");
        }
        else {
            System.out.println(year+"年不是闰年");
        }
    }
}
