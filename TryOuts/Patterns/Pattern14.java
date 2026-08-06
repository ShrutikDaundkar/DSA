class Pattern14 {

    public void pattern(int n) {
        for (int i = 1; i <= n; i++) {
            for (char ch = 'A'; ch < 'A' + i; ch++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern14 obj = new Pattern14();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
