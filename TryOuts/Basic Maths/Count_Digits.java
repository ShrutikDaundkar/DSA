public class Count_Digits {
    public static int Count_Digits(int n){
        int count =0;
        while(n>0){
           
            count= count+1;
            n=n/10;
        }
        return count;
    }
    public static void main(String[] args) {
        
        System.out.println(Count_Digits(1234));

    }
}
