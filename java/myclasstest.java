import java.util.*;
public abstract class myclass{
  
    public abstract void numberOfSides();
}

class Rectangle extends  myclass{
  public abstract void numberOfSides(){
      System.out.println("helllo");
  }
 }
public class myclasstest {
        public static void main(String[] args){
            // Scanner sc = new Scanner(System.in);
            // int number = Integer.valueOf(sc.nextLine());
            // System.out.println(number);
          Rectangle r1= new Rectangle();
          r1.numberOfSides();
        }
        
}
