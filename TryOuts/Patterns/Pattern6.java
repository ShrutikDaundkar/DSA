class Pattern6 {

    public void pattern(int n) {
        for (int i = n; i > 0; i--) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern6 obj = new Pattern6();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
