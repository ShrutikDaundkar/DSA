class Pattern18 {

    public void pattern(int n) {
        for (int i = 1; i <= n; i++) {
            for (int ch = ('A' + n - i); ch < 'A' + n; ch++) {
                System.out.print((char) ch + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern18 obj = new Pattern18();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
