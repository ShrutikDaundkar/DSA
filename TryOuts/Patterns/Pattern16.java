class Pattern16 {

    public void pattern(int n) {
        char ch = 'A';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(ch);
            }
            ch += 1;
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Pattern16 obj = new Pattern16();

        obj.pattern(4);

        System.out.println();

        obj.pattern(2);
    }
}
