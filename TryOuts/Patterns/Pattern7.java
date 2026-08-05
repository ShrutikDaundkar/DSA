class Pattern7 {

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
    }

    public static void main(String[] args) {
        Pattern7 obj = new Pattern7();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
