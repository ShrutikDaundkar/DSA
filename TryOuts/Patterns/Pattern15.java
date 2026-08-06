class Pattern15 {

    public void pattern(int n) {
        for (int i = n; i > 0; i--) {
            for (char ch = 'A'; ch < 'A' + i; ch++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern15 obj = new Pattern15();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
