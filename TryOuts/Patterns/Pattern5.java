class Pattern5 {

    public void pattern(int n) {
        for (int i = n; i > 0; i--) {
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern5 obj = new Pattern5();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}