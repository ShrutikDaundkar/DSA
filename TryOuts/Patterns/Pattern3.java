class Pattern3 {

    public void pattern(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern3 obj = new Pattern3();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}