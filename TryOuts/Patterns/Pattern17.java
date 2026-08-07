class Pattern17 {

    public void pattern(int n) {
        for (int i = 1; i <= n; i++) {
            char ch = 'A';
            // Space
            for (int j = 1; j <= n - i; j++) {
                System.out.print(" ");
            }

            // Character
            for (int j = 1; j <= i; j++) {
                System.out.print(ch);
                ch += 1;
            }
            ch--;
            // Character
            for (int j = 1; j <= i - 1; j++) {
                ch -= 1;
                System.out.print(ch);

            }

            // Space
            for (int j = 1; j <= n - i; j++) {
                System.out.print(" ");
            }

            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern17 obj = new Pattern17();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
