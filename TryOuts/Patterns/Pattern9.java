class Pattern9 {

    public void pattern(int n) {
        for (int i = 0; i < n; i++) {
            // Space
            for (int j = 0; j < n - i - 1; j++) {
                System.out.print(" ");
            }

            // Star
            for (int j = 0; j < i * 2 + 1; j++) {
                System.out.print("*");
            }

            // Space
            for (int j = 0; j < n - i - 1; j++) {
                System.out.print(" ");
            }

            System.out.println();
        }
        for (int i = 0; i < n; i++) {

            // Space
            for (int j = 0; j < i; j++) {
                System.out.print(" ");
            }

            // Star
            for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
                System.out.print("*");
            }

            // Space
            for (int j = 0; j < i; j++) {
                System.out.print(" ");
            }

            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern9 obj = new Pattern9();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
