class Pattern4 {

    public void pattern(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print(i);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern4 obj = new Pattern4();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}