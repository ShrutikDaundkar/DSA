public class Pattern13 {

    public void pattern(int n) {
        int num = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(num + " ");
                num++;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern13 obj = new Pattern13();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
