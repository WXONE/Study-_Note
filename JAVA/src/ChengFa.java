public class ChengFa {
    public static void main(String[] args) {
        int i=1;
        while(i<10) {
            int j=1; while(j<i+1){
                System.out.print(i+"*"+j+"="+i*j+"\t"); j++;
            }
            i++;
            System.out.println();
        }
    }

}
