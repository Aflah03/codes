public abstract class check_abstraction{
    public abstract void numberOfSides();
}

class Rectangle extends  check_abstraction{
    public void numberOfSides(){
        System.out.println("This is going to be cool");
    }
}
class test {
        public static void main(String[] args){
            // Scanner sc = new Scanner(System.in);
            // int number = Integer.valueOf(sc.nextLine());
            // System.out.println(number);
          Rectangle r1= new Rectangle();
          r1.numberOfSides();
        }
        
}
