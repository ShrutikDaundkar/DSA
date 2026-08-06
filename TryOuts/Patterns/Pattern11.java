class Pattern11 {

    public void pattern(int n) {
        int start = 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                start = 1;
            }
            for (int j = 0; j <= i; j++) {
                System.out.print(start);
                start = 1 - start;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern11 obj = new Pattern11();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
