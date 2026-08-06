class Pattern12 {

    public void pattern(int n) {
        int space = 2 * (n - 1);
        for (int i = 1; i <= n; i++) {
            // Number
            for (int j = 1; j <= i; j++) {
                System.out.print(j);
            }

            // Space
            for (int j = 0; j < space; j++) {
                System.out.print(" ");
            }

            // Number
            for (int j = i; j >= 1; j--) {
                System.out.print(j);
            }

            System.out.println();
            space -= 2;
        }
    }

    public static void main(String[] args) {
        Pattern12 obj = new Pattern12();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
