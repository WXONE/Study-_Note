import java.util.Scanner;

public class ChouJiang {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("请输入一个数字：");
        int a = scan.nextInt();
        switch (a){
            case 1:System.out.println("恭喜您获得JAVA习题+视频大礼包");break;
            case 2:System.out.println("恭喜您获得JAVA习题大礼包");break;
            case 3:System.out.println("恭喜您获得JAVA视频大礼包");break;
            default:System.out.println("没有奖品给你！");break;
        }

    }
}
