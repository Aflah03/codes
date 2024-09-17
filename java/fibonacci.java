public class fibonacci {
    public long fib(int n){
        if(n<=2) return 1;
        return fib(n-1) + fib(n-2);
    }
    public static void main(String[] args){
        fibonacci my_fib = new fibonacci();
        System.out.println(my_fib.fib(5));
    }
    
}
